/*******************************************************************************
		Main Program:	

		Comment:			Variable operation

		Author:				Yu-Chi Lai, yu-chil@cae.wisc.edu

		Due Date:			

		Course:				CS777, Spring 2003
******************************************************************************/
#include "LString.h"

/////////////////////////////////////////////////////////////////////
//
// Methods to get information
//
/////////////////////////////////////////////////////////////////////
//******************************************************************
// Get the axiom string
//******************************************************************
std::string LString::get_axiom()
{
  return (line_ptr[AXIOM_LINE]->text());
}

//******************************************************************
// Get the change angle
//******************************************************************
float  LString::get_ang()
{
  return (line_ptr[ANG_LINE]->as_float());
  return (float) 0.1;
}

//******************************************************************
// Get the thickness of the line
//******************************************************************
float  LString::get_thick()
{
  return (line_ptr[THICK_LINE]->as_float());
}

//******************************************************************
// Get the level of the line
//******************************************************************
int  LString::get_lev()
{
  double temp = line_ptr[REC_LINE]->as_float();
  return static_cast<signed short int>(ceil(temp));
}

//******************************************************************
// Get the fraction part of the number
//******************************************************************
float32 LString::get_fraction()
{
  double temp = line_ptr[REC_LINE]->as_float();
  return static_cast<float32>(temp - floor(temp));
}

//******************************************************************
// Find out the maximum number of the two size 
//******************************************************************
inline size_t Max(size_t i1, size_t i2)
{
  if (i1 > i2)
		return i1;
  else
		return i2;
}

//******************************************************************
// Reads an (xx) value from a production string at the curr_pos,
// and make it into a real. Then advance curr_pos to the next position.
// Returns true if there is such a bracketed value.
//******************************************************************
bool  LString::Get_value(unsigned long &curr_pos, float32 &val)
{       
	// The letter go through
  int characters_read = 0;
	// Check the position which should be within the bound
  if (curr_pos >= FS_Lgth) 
    return false;
	// Extract the information and then get how many letter go through
  if (FinalString[curr_pos] == '(')
    sscanf((char *) &(FinalString[curr_pos]), "(%f)%n", &val, &characters_read);
  
  curr_pos += characters_read;
  if (characters_read > 2)
    return true;
  else
    return false;
}

//******************************************************************
// If the character at position s_pos in the FinalString is a
// CountChar, return the CountChar number and advance s_pos by one.
//******************************************************************
int LString::Get_RecursionChar(unsigned long &s_pos)
{
	// Check the position should be within bound
  if (s_pos <= FS_Lgth) {
    int i = 0;
    unsigned char theChar = FinalString[s_pos];
    while (CountChar[i] != '\0')
      if (CountChar[i++] == theChar)
				break;
    if (i != '\0') {
      s_pos++;
      return i;
    }
  }
  return 0;
}

//******************************************************************
// Return the FinalString, minus any CountChars
//******************************************************************
std::string LString::FormattedFinalString()
{
	std::string fs=(char *) FinalString;
	std::string ss=(char *) CountChar;
  size_t pos = 0;
  while (pos != std::string::npos) {
    pos = fs.find_first_of(ss, pos);
    if (pos != std::string::npos)
      fs.replace(pos, 1, "");
  }
  return fs;
}

//******************************************************************
// Check whether the final string exist or not
//******************************************************************
bool LString::FinalStringExists()
{
  if (FinalString == NULL)
    return false;
  else
    return true;
}

//******************************************************************
// The length of the final string
//******************************************************************
int  LString::FinalStringLength()
{
  return FS_Lgth;
}

//******************************************************************
// Check the ith string number
//******************************************************************
unsigned char LString::FinalStringChr(unsigned int i)
{
  return FinalString[i];
}

//******************************************************************
// Chech the final string level
//******************************************************************
int  LString::FinalStringRecLev()
{
  return FS_Lev;
}
