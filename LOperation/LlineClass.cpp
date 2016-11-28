/*******************************************************************************
		Main Program:	Viewer.cpp

		Comment:			LlineClass methods
									The LlineClass stores a single line of an L System specification.
									If the line begins with a #, it is marked as a COMMENT line. 
									Text after a # is always ignored: to cope with this,
									the "end_text" variable	marks where the # comment begins 
									(actually, it marks	the start of any whitespace before a # character).

									The line can be 
									1. RECursion line
									2. starting ANGle line
									3. A default THICKness line
									which 3 cases, it must consist of a single number. 
									Otherwise, it can be an AXIOM	line or a RULE line. 
									* There should only be one RECursion line, one ANGle line, one THICKness line, 
									  and one AXIOM line.

		Author:				Yu-Chi Lai, yu-chil@cae.wisc.edu

		Due Date:			

		Course:				CS777, Spring 2003
*******************************************************************************/
#include "LlineClass.h"
#include <math.h>

//*******************************************************************************
// Constructor
//*******************************************************************************
LlineClass::LlineClass()
{
  the_text = "";
  end_text = 0;
  marker   = COMMENT;
} 
//*******************************************************************************
// Constructor - an Lline must be added to a list of such lines. 
//							 The list to which it is added is passed to the constructor 
//*******************************************************************************
LlineClass::LlineClass(std::vector<LlineClass *> &the_list)
{
  the_text = "";
  end_text = 0;
  marker   = COMMENT;
  the_list.push_back(this);
} 

//*******************************************************************************
// My own copy constructor
//*******************************************************************************
LlineClass::LlineClass(std::vector<LlineClass *> &the_list,
												LlineClass& const cpy)
{
  the_text = cpy.the_text;
  end_text = cpy.end_text;
  marker   = cpy.marker;
  the_list.push_back(this);
} 


//*******************************************************************************
// Allocate text (as a char array) to an Lline
//*******************************************************************************
void LlineClass::assign(char* const text_in, const line_label marker_in)
{
	// Deallocate everything
  the_text="";
	// Assign the text in
  the_text.append(text_in);

  // Let the end_text to the first # at the end
  end_text = the_text.find('#');
  end_text = the_text.find_last_not_of("#\t ", end_text);
	// We did not find the #
  if (end_text == std::string::npos)
    end_text = 0;
  else
    end_text++;
  marker = marker_in;
} 

//*******************************************************************************
// Assign the text and the marker of the in
//*******************************************************************************
void LlineClass::assign(const std::string text_in, const line_label marker_in)
{
	//Desc: allocate text (as a std::string) to an Lline
  the_text="";
  the_text.append(text_in);
  //cout << the_text << endl;
  //look for comments
  end_text=the_text.find('#');
	// And mark the last character which is not #, \t or space
  end_text=the_text.find_last_not_of("#\t ",end_text);
	// There are no such characters
  if (end_text==std::string::npos)
    end_text=0;
  else
    end_text++;
	// Put the marker in
  marker=marker_in;
}

//*********************************************************************************
// Return the text
//*********************************************************************************
std::string LlineClass::text()
{
  return the_text;
}

//*********************************************************************************
// Set the marker of the text
//*********************************************************************************
void LlineClass::set_marker(line_label marker_in)
{
  marker = marker_in;
};

//*********************************************************************************
// Get the marker of the text
//*********************************************************************************
line_label LlineClass::get_marker()
{
  return marker;
}

//*********************************************************************************
// Get the lenth of the text
//*********************************************************************************
size_t LlineClass::info_length()
{
  return end_text;
}

//*********************************************************************************
// Get the first character of the text
//*********************************************************************************
char LlineClass::first_char()
{
  return the_text[0];
}

//*********************************************************************************
// Get the ith character of the text
//*********************************************************************************
char LlineClass::char_num(int i)
{
  return the_text[i];
}

//*********************************************************************************
// Return the address of the second character
//*********************************************************************************
char *LlineClass::rule_start()
{
  return &the_text[2];
}

//*********************************************************************************
// Check whether text contain the floating data from pos + 1
//*********************************************************************************
bool LlineClass::has_value(size_t pos) 
{
	// An asterisk (*) following the percent sign suppresses assignment of the next input field,
	// which is interpreted as a field of the specified type. 
	// The field is scanned but not stored.
  if (sscanf(the_text.data() + pos + 1, "(%*f)") == 1)
		return true;
  else
		return false;
} 

//*********************************************************************************
// Check whether starting of the text contain the floating data
//*********************************************************************************
bool LlineClass::is_float()
{
	// Dummy data variable
  float dummy;
	// Check whether the starting point contain data 
  if (sscanf(the_text.c_str(), "%f", &dummy) ==1)
    return true;
  return false;
}

//*********************************************************************************
// Return the float value
//*********************************************************************************
float LlineClass::as_float()
{
	// Return varialbe
  float temp = 0;
	// Get the float variable
  if (sscanf(the_text.c_str(),"%f", &temp) ==1)
    return temp;
  return sqrt(-1);

}

//*********************************************************************************
// Returns true if the character in position "the_pos" is, or
// is enclosed by "(" and ")", and the only other characters enclosed
// are numbers or a decimal point. 
// Also uses the "b" and "a" variables to return the positions of the "(" and ")". 
//*********************************************************************************
bool LlineClass::within_round_brackets(size_t the_pos, size_t &b, size_t &a)
{
	// Find the starting bracket characters to include (
  static const std::string br_chars_aft = inbrackets_chars + "(";
	// Find the ending bracket characters to include )
  static const std::string br_chars_bef = inbrackets_chars + ")";
	// The first character
  size_t first_pos;

	//*******************************************************************
  // Only look at RULE lines or the AXIOM line. 
	//*******************************************************************
  // If a RULE line, ignore the first 2 characters
  switch (marker) {
		case FZ_RULE:
		case USER_RULE:
		case STANDARD_RULE:
			first_pos=2;
			break;
		case AXIOM:
			first_pos=0;
			break;
		default:
			return false;
  }
	// Find )..... or number.....
  a = the_text.find_first_not_of(br_chars_aft, the_pos);
	// Find ....( or ....number
  b = the_text.find_last_not_of(br_chars_bef, the_pos);
	// a is over the end of valid text
  if ((a >= end_text) || (a == std::string::npos)) 
		a = end_text;
	// b is over the bigin of the valid text
  if ((b < first_pos) || (b == std::string::npos)) 
		b = first_pos;
    
  if ((the_text[a] == ')') || (the_text[b]=='('))
    return true;
  else
    return false;
}

//*********************************************************************************
// As the same named function above, but don't return before 
// and after positions of the brackets
//*********************************************************************************
bool LlineClass::within_round_brackets(size_t the_pos)
{
 size_t a, b;
 return within_round_brackets(the_pos, b, a);
}

//*********************************************************************************
// Return the position of the matching bracket of a pair, 
// where the position of one of the pair is "the_pos". 
// Brackets can be [], {}, or ()
//*********************************************************************************
size_t LlineClass::matching_bracket(size_t the_pos)
{
	// The position of found
  size_t found;
	// Going down depth
  int    depth = 1;

  switch (the_text[the_pos]) {
		case '{':
			found = the_pos;
			do {
				// Find the next correspondence
				found = the_text.find_first_of("{}", found + 1);
				// Over the valid text
				if ((found == std::string::npos) || (found >= end_text))
					return std::string::npos;
				// Recursive because we found starting {
				if (the_text[found]=='{')
					depth++;
				// Find the } reduce a pair
				else
					depth--;
			} while (depth > 0);
			// The final match the original pair
			return found;

		case '}':
			found = the_pos;
			do {
				// Search to front 
				found = the_text.find_last_of("{}", found - 1);
				// Over the limit
				if ((found == std::string::npos) || (found < 2)) 
					return std::string::npos;
				if (the_text[found]=='}') 
					depth++;
				else                      
					depth--;
			} while (depth > 0);
			return found;

		case '(':
			found = the_pos;
			do {
				found = the_text.find_first_of("()", found + 1);
				if ((found == std::string::npos) || (found >= end_text)) 
					return std::string::npos;
				if (the_text[found] == '(')
					depth++;
				else
					depth--;
			} while (depth > 0);
			return found;
		case ')':
			found = the_pos;
			do {
				found = the_text.find_last_of("()", found - 1);
				if ((found == std::string::npos) || (found < 2))
					return std::string::npos;
				if (the_text[found] == ')')
					depth++;
				else
					depth--;
			} while (depth > 0);
			return found;

		case '[':
			found = the_pos;
			do {
				found = the_text.find_first_of("[]", found + 1);
				if ((found == std::string::npos) || (found >= end_text)) 
					return std::string::npos;
				if (the_text[found] == '[')
					depth++;
				else
					depth--;
			} while (depth > 0);
			return found;

		case ']':
			found = the_pos;
			do {
				found = the_text.find_last_of("[]", found - 1);
				if ((found == std::string::npos) || (found < 2)) 
					return std::string::npos;
				if (the_text[found]==']')
					depth++;
				else
					depth--;
			} while (depth > 0);
			return found;
		default:
			return std::string::npos;
  }// end of switch
}

//*********************************************************************************
// Returns the associated parameter, and also gives the number of characters 
// (including brackets) of the bracketed number associated with a character in the LString.
// This character must be one of those listed in the bracketed_chars std::string. 
// Returns NaN if no parameter or a bad parameter.
//*********************************************************************************
double LlineClass::assoc_param(const size_t the_pos, int& the_length)
{ 
	// The floating point parameter
  float param;
	// temporary variable
  int conv, dummy;
	// Initialize no number
  the_length = 0;
	// At the end of the text
  if (the_pos == info_length() - 1)
		return sqrt(-1);

	// The starting character is not in the bracket_chars
  if (bracketed_chars.find(the_text[the_pos]) == std::string::npos)
		return sqrt(-1);
	// %n, int *; the number of characters written so far by this call
	// Find the (...) and counting its number
  conv = sscanf( &(the_text.data()[the_pos + 1]), "(%f)%n", &param, &the_length);
	// No character has been operated
  if (conv == sscanf("", "%n", &dummy)) {
    the_length = 0;
    return sqrt(-1);
  } 
	else {
    return param;
  }
}

//*********************************************************************************
// Increments the_pos along an Lstring line, skipping any parameters associated with 
// an Lstring character (i.e. numbers in round brackets). 
// Returns false if at the end of the informative characters in the line.
//*********************************************************************************
bool LlineClass::increment(size_t &the_pos)
{ 
	// before and after pointer
  size_t bef, aft;
  //only look at RULE and AXIOM lines
  switch (marker) {   
		case USER_RULE:
		case FZ_RULE:
		case STANDARD_RULE:
		case AXIOM:
		  break;
		default:
	    the_pos=0;
			return false;
  }

  // The position bigger than the end of the text
  if (!(the_pos < end_text)) {
    the_pos = end_text;
    return false;
  }// end of if the_pos
	else {
		// If the character is not belonging to the bracket character
		// And we could not find the corresponding position of brackets
    if ((bracketed_chars.find(the_text[the_pos]) != std::string::npos) &&
				(within_round_brackets(the_pos + 1, bef, aft)))
				the_pos = aft;
		// Get the to character next to )
    the_pos++;
		// The position is valid
    if (the_pos <= end_text) {
      return true;
    } 
		// over the line
		else {
      the_pos = end_text;
      return false;
    }// end of else
  }// end of else
}

//*********************************************************************************
// As for LlineClass::increment, but decrements the_pos, returning false 
// if at the start of the informative characters (this is at pos 0 for the axiom, 
//                                                 but pos 2 for rules).
//*********************************************************************************
bool LlineClass::decrement(size_t &the_pos)
{
	// The starting position, before and after bracket
  size_t first_pos, bef, aft;
	// RUle starting position is 2, and axiom is 0
  switch (marker) {
		case USER_RULE:
		case FZ_RULE:
		case STANDARD_RULE:
			first_pos = 2;
			break;
		case AXIOM:
			first_pos = 0;
	    break;
		default:
			the_pos = 0;
			return false;
  }// end of switch
	
  the_pos--;
  if ((the_pos > first_pos) && (within_round_brackets(the_pos, bef, aft))) {
    the_pos = bef;
    if ((the_pos != std::string::npos) &&
				(the_pos > first_pos)     && 
				(bracketed_chars.find(the_text[the_pos - 1]) != std::string::npos))
				the_pos--;
  }// end of if
  if ((the_pos != std::string::npos) && (the_pos >= first_pos))
    return true;
  else {
    the_pos = first_pos;
    return false;
  }// end of else
}
//*******************************************************
// Print out the string information
//********************************************************
void LlineClass::print()
{
	printf("The end text is %d\n", end_text);
	printf("%s\n", the_text.c_str());
}