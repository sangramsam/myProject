/*******************************************************************************
		Main Program:	

		Comment:			Variable operation

		Author:				Yu-Chi Lai, yu-chil@cae.wisc.edu

		Due Date:			

		Course:				CS777, Spring 2003
******************************************************************************/
#include "LString.h"

////////////////////////////////////////////////////////////////////////////////
//
// Method to handle parse the user input
//
////////////////////////////////////////////////////////////////////////////////
//*************************************************************************
// Parse the element from the user file
//*************************************************************************
bool LString::parserFile(char *filename)
{
	// The input file string concatenate all string together
	std::string inputString;
	// The input buffer
	char inputBuf[2048];
	// The input file stream
	std::ifstream inStream;

	// Initialize the string to zero
	inputString = "";
	// open the input file stream
	inStream.open(filename);
	if(!inStream.is_open()){
		printf("Filename %s\n", filename);
		Warning("The input file can not be opened");
		return false;
	}
	
	// Read all string in and then concatenate them to the end of the string
	while(!inStream.eof()){
		inStream.getline(inputBuf, 2048);
		inputString += inputBuf;
		inputString += "\n";
	}
	printf("***************** The input file **********************\n");
	printf("%s\n", inputString.c_str());
	printf("*******************************************************\n");

	// Input them into the LString by the operator
	*this << inputString;
	return true;
}

//***********************************************************************************
// Input string to create a LString
//***********************************************************************************
void LString::operator<<(std::string& p)
{
	// Print out the reading information
	printf("Starting to read an LString in\n");

	// Temporary string variable
	std::string     tempStr1, tempStr2;

	// Line's label type
  line_label i   = RECURSION;
  // Reset all variable to standard rules
  Clear();
	//
	printf("Stripping text\n");

	//********************************************************
	// Extract the valid information before the @ character
	//********************************************************
  // Strip the last @ from the string and any following text.
  tempStr1 = p.substr(0, p.find('@'));

  // Strip trailing newlines
  tempStr2 = tempStr1.substr(0, p.find_last_not_of(endline_markers));

	// Extract the information out
	// 1. Recursion information
	// 2. Angle
	// 3. Thickness
	// 4. Axiom
	// 5. User rule
  while (tempStr2.length() != 0) {
    switch (i) {
			case RECURSION:
				// Insert the variable
				if (InsertVariable(tempStr2, (var_line_label)i)){
					// Advance to the next operation angle
					i = static_cast<line_label>(i + 1);  
					printf("Insert the recursion\n");
				}// end of if
				break;
			case ANGLE:
				if (InsertVariable(tempStr2, (var_line_label) i)){
					// Advance to the next operation thickness
					i = static_cast<line_label>(i + 1);  
					printf("Insert the angle\n");
				}// end of if
				break;
			case THICKNESS:
				// Advance to the next operation axiom
				if (InsertVariable(tempStr2, (var_line_label) i)){
					i = static_cast<line_label>(i+1);  
					printf("Insert the thickness\n");
				}
				break;
			case AXIOM:
				// INsert the axiom
				if (InsertAxiom(tempStr2)) {
					valid_string = true;
					// Advances to the user rule
					i = USER_RULE;
					printf("Insert the axiom\n");
				}
				break;
			case USER_RULE:
				InsertUserRule(tempStr2);
				printf("Insert user rule\n");
				break;
			default:
				Warning("bad case in switch statement");
				break;
		}// end of switch
  }// end of while
	printf("finished\n");
}

//******************************************************************
// Insert one of the 3 variable lines (recursion, angle, thickness) into the LString.  
// Returns false 
//  1. if the line has not been inserted,
//  2. if the the line is a comment, 
//  3. if "which" turns out not to be one of the 3 variable lines
//******************************************************************
bool LString::InsertVariable(std::string &to_insert, var_line_label which)
{
	// Variable for store the information string
  std::string     the_line;
	// For the variable operation
  LlineClass *VarLine;

  // Grab a line from the string
  the_line = snip_line(to_insert);

  // If the line is empty, return false
  if (the_line.length() == 0) {
    Warning("The input line is empty and ignore");
    return false;
  }

  // Allocate a new line
  VarLine = new LlineClass(line);

  // Comment line
  if (the_line[0] == '#') { 
    VarLine->assign(the_line, COMMENT);
    return false;
  }

	// Assign the line with the value
  VarLine->assign(the_line, (line_label)which);
  switch (which) {
		// Recursion variable
		case REC_VARIABLE:
			// There exists some recursion information
			if (line_ptr[REC_LINE] != NULL)
				Warning("The recursion has already existed");

			// The information is not a number, and we will use the default string
			if (!VarLine->is_float()) {
				Warning("The recursion line is not a number");
				VarLine->assign(default_rec_string, RECURSION);
			}

			// Assigned the to line_ptr
			line_ptr[REC_LINE] = VarLine;
			break;

		// Angle variable
		case ANG_VARIABLE:
			// There exists some angle information
			if (line_ptr[ANG_LINE]!=NULL)
				Warning("Angle line already allocated");

			// The information is not a number, and we will use the default string
			if (!VarLine->is_float()) {
				Warning("The angle line is not a number");
				VarLine->assign(default_ang_string, ANGLE);
			}

			// Assigned to the line_ptr
  		line_ptr[ANG_LINE] = VarLine;
			break;
  
		// Thickness variable
		case THICK_VARIABLE:

			// There exists some thick information
			if (line_ptr[THICK_LINE] != NULL)
				Warning("thickness line already allocated");

			// The line is not a number
			if (!VarLine->is_float()) {
				Warning("The thick line is not a number");
				VarLine->assign(default_thick_string,THICKNESS);
			}

			// Assgined to the pointer
			line_ptr[THICK_LINE] = VarLine;
			break;
  }// end of switch
  return true;
}

//******************************************************************
// Insert an axiom line into the LString object. 
// Returns false if comment or empty line, true otherwise
//******************************************************************
bool LString::InsertAxiom(std::string &to_insert)
{ 
	// The Axiomline
  LlineClass *AxiomLine;
	// The information
  std::string the_line;

  // Extract the information out
  the_line = snip_line(to_insert);
  if (the_line.length() == 0) {
    Warning("The axiom line is empty");
    return false;
  }
  
  AxiomLine = new LlineClass(line);
	// The first word is a comment
  if (the_line[0] == '#') {
    AxiomLine->assign(the_line, COMMENT);
    return false;
  } // end of if

	// The axiom has already exist
  if (line_ptr[AXIOM_LINE] != NULL)
		Warning("axiom line already allocated");

	// Allocate the AxiomLine information
  line_ptr[AXIOM_LINE] = AxiomLine;
	// Could not replace the axiom
  if(!ReplaceAxiom(the_line)) {
			Warning( "error replacing axiom");
			return false;
  }
  return true;
}

//******************************************************************
// Replaces the axiom line with a new string. 
// Returns false if there is no previous axiom string, 
//               if the replacement is blank or a comment
//******************************************************************
bool LString::ReplaceAxiom(const std::string to_insert)
{
  if (line_ptr[AXIOM_LINE] == NULL) 
		return false;
  if (to_insert.length() == 0)
    return false;
  if (to_insert[0] == '#')
		return false;
	// Remove the original length
  num_axiom_and_rule_chars -= line_ptr[AXIOM_LINE]->info_length();
	// Insert the text into AXIOM
  line_ptr[AXIOM_LINE]->assign(to_insert, AXIOM);
	// Add the current length
  num_axiom_and_rule_chars += line_ptr[AXIOM_LINE]->info_length();
  return true;
}

//******************************************************************
// Insert a rule into the LString object.
// Returns true if a rule or comment line is inserted
//******************************************************************
bool LString::InsertUserRule(std::string &to_insert)
{ 
	// The new rule pointer
  LlineClass   *the_new_rule;
	// The extract information
  std::string   the_line;

  // Get a line
  the_line = snip_line(to_insert);

	// No element in the line
  if (the_line.length() == 0) {
    Warning("The line is empty");
    return false;
  }
	
	//?????????????????????????????????????????????????????????
	// Why do we need this line
	//?????????????????????????????????????????????????????????
  // Indicates that this is the end
  if (the_line[0] == '@')  
		// Find an empty character for the rule
    if(!allocate_new_rule_char(the_line)) {
			Warning("There is no memory space for new rules");
      return false;
    }// end of if !allocate

	// Create a new line class
  the_new_rule = new LlineClass(line);
  
  //make new Lline
  switch (the_line[0]) {
		case '#':
			the_new_rule->assign(the_line, COMMENT);
			return true;

		// The forward rule
		case 'F':
		case 'f':
		case 'Z':
		case 'z':
			the_new_rule->assign(the_line, FZ_RULE);
			break;

    // User define rule
		default:
			the_new_rule->assign(the_line, USER_RULE);
  }
  
  // Set up the look up table
  SetUserRule(the_new_rule);
  return true;
}
//******************************************************************
// Replace the first character in a string by a new character, 
// and also replace occurences of the old character
// in the string. If no new character can be found, return false
//******************************************************************
bool LString::allocate_new_rule_char(std::string &rule)
{
	// The position
  size_t pos = 0;

	// Find a non-used represented character in the table
  size_t new_rule = new_rule_chars.find_first_not_of(user_rules);

	// No empty pointer
  if(new_rule == std::string::npos) 
		return false;

	// Check whether the rule exist or not if not replace it
  char   old_char = rule[0], new_char = new_rule_chars[new_rule];

  // Replace all the occurence of character in the rule
  while ((pos = rule.find(old_char, pos)) != std::string::npos)
    rule.replace(pos, 1, new_char, 1);
  return true;
}

//******************************************************************
// Add "the_rule" to the RuleForChar array and augment the 
// number of mutable characters.
//******************************************************************
bool LString::SetUserRule(LlineClass *the_rule)
{
	// If the rule marker is not user_rule or fz_rule no action taken
  if ((the_rule->get_marker() != USER_RULE) &&
      (the_rule->get_marker() != FZ_RULE))
    return false;

	// Add the rule length into the num_axiom_and_rule_chars
  num_axiom_and_rule_chars += the_rule->info_length() - 2;

	// Add the first character into user rule
  user_rules += the_rule->first_char();
	// Set up the look up table
  SetRule(the_rule);
  return(true);
}

//******************************************************************
// output the L string description stored in the LString object
//******************************************************************
void LString::operator >> (std::string& out)
{
  // Go through all the string and copy the string into the output string
  for (std::vector<LlineClass *>::iterator i=line.begin(); i != line.end(); ++i) {
    out += ((*i)->text());
    out += "\n"; 
  }

	// Put and end character to the end of the file
  out += "@";
  out += "\n";
}

//***********************************************************************************
// Copy the string information
//***********************************************************************************
LString &LString::operator = (LString& lstr)
{
	// To put the temporary information
	std::string temp;
	// Output the string of lstr to temp
  lstr >> temp;
	// and put the information into the string
  *this << temp;
  return (*this);
}

//***********************************************************************************
// Print out the LString information
//***********************************************************************************
void LString::print()
{
	printf("The line size %d\n", line.size());
	// Print out the user rule size
	int size = user_rules.size();
	// Print out variable information
	int i;
	for(i = 0; i < 4; i++)
		line_ptr[i]->print();

	for(i = 0; i < size; i++)
		RuleForChar[user_rules[i]]->print();

}
