/*******************************************************************************
		Main Program:	Viewer.cpp

		Comment:			Rule Operator

		Author:				Yu-Chi Lai, yu-chil@cae.wisc.edu

		Due Date:			

		Course:				CS777, Spring 2003
		DefaultRule " = "
******************************************************************************/
#include "LString.h"
#include "../global/function.h"

///////////////////////////////////////////////////////////////////
//
// Standard rule opearation
//
////////////////////////////////////////////////////////////////////
//******************************************************************
// Generate the standard rule for method
//******************************************************************
void LString::GenerateStdRules()
{
  unsigned int i;
	// c4, mutation rule
  char c3[4], c4[5];
	// Clear the standard rule
  StdRule.clear();
	//************************************************************
  // Generate rules that replace symbols with themselves. This
  // allows fast parsing of an L string in the Parse() method.
	// Number, c, F, f, g, t, Z, z and some other symples
	//************************************************************
  GenerateStdRule(".=.");
  GenerateStdRule("1=1");
  GenerateStdRule("2=2");
  GenerateStdRule("3=3");
  GenerateStdRule("4=4");
  GenerateStdRule("5=5");
  GenerateStdRule("6=6");
  GenerateStdRule("7=7");
  GenerateStdRule("8=8");
  GenerateStdRule("9=9");
  GenerateStdRule("0=0");
  GenerateStdRule("(=(");
  GenerateStdRule(")=)");

  GenerateStdRule("+=+");
  GenerateStdRule("-=-");
  GenerateStdRule("&=&");
  GenerateStdRule("^=^");
  GenerateStdRule("<=<");
  GenerateStdRule(">=>");

  GenerateStdRule("%=%");
  GenerateStdRule("|=|");
  GenerateStdRule("!=!");
  GenerateStdRule("?=?");
  GenerateStdRule(":=:");
  GenerateStdRule(";=;");
  GenerateStdRule("\'=\'");
  GenerateStdRule("\"=\"");
  GenerateStdRule("c=c");
  
  GenerateStdRule("[=[");
  GenerateStdRule("]=]");
  GenerateStdRule("{={");
  GenerateStdRule("}=}");
  
  GenerateStdRule("F=F");
  GenerateStdRule("f=f");

  GenerateStdRule("t=t");
  GenerateStdRule("g=g");
  GenerateStdRule("Z=Z");
  GenerateStdRule("z=z");
  GenerateStdRule("*=*");
  GenerateStdRule("$=$");

  GenerateStdRule("_=_");
  GenerateStdRule("`=`");

	//***************************************************************************
  // The rule ~ is the only one which incorporates randomness into the LString interpretation.
	// This makes it complicated, as we want to be able to track the number of recursions
	// which it has experienced, so that we can show the stages in its growth. 
	// We use the characters above #128 listed in the CountChars string.
	//***************************************************************************
  //replace ~ with `C where C is the first CountChar 
  sprintf(c4,"~=`%.1s", (char *)CountChar); 
  GenerateStdRule(c4);

  //on each pass of the parser, replace any CountChar with the next one
  for (i = 1; CountChar[i] != '\0'; i++){
    sprintf(c3,"%.1s=%.1s", &CountChar[i-1], &CountChar[i]);
    GenerateStdRule(c3);
  }

  // Replace any instance of the last CountChar with the first CountChar 
  sprintf(c3,"%.1s=%.1s",&CountChar[i-1], &CountChar[0]);
  GenerateStdRule(c3);

  //Spaces in an LString are removed when parsing
  GenerateStdRule(" =");
  //Any unspecified character also gets removed
  DefaultStdRule = *StdRule.rbegin();
}

//***********************************************************************************
// Put the rule into rule string
//***********************************************************************************
void LString::GenerateStdRule(char *the_rule)
{
  LlineClass *temp = new LlineClass(StdRule);
  temp->assign(the_rule, STANDARD_RULE);
}

//***********************************************************************************
// Put the rule into rule string
//***********************************************************************************
void LString::SetStdRules()
{
  // Initialize all loop up table to default rule
  for (unsigned int n = 0; n < 256; n++)
    SetRule(DefaultStdRule, (unsigned char)n);

  for (std::vector<LlineClass *>::iterator i = StdRule.begin(); i != StdRule.end(); ++i)
			SetRule(*i);
}

//******************************************************************
// Simply point the RuleForChar array at the_rule
//******************************************************************
void LString::SetRule(LlineClass *the_rule, unsigned char the_pos)
{ 
  RuleForChar[the_pos] = the_rule;
}

//******************************************************************
// Simply point the RuleForChar array at the_rule
//******************************************************************
void LString::SetRule(LlineClass *the_rule, char the_pos)
{
  unsigned char arr_index;
	// Let the char to unsigned char
  memcpy(&arr_index, &the_pos, 1);
  SetRule(the_rule, arr_index);
}
//******************************************************************
// Use the first character of "the_rule" as the index in RuleForChar
//******************************************************************
void LString::SetRule(LlineClass *the_rule)
{
  SetRule(the_rule, the_rule->first_char());
}

///////////////////////////////////////////////////////////////////
//
// User rule operation
//
////////////////////////////////////////////////////////////////////
//******************************************************************
// Insert a rule into the LString object.
// Returns true if a rule or comment line is inserted
//******************************************************************
bool LString::InsertUserRule(string &to_insert)
{ 
	// The new rule pointer
  LlineClass   *the_new_rule;
	// The extract information
  string       the_line;

  // Get a line
  the_line = snip_line(to_insert);
	// No element in the line
  if (the_line.length() == 0) {
    Warning("The line is empty");
    return false;
  }

  //indicates that this is a new rule
  if (the_line[0] == '@')  
		// Find an empty character for the rule
    if(allocate_new_rule_char(the_line) == false) {
			Warning("There is no memory space for new rules");
      return false;
    }
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
// Replace the first character in a string by a new
// character, and also replace occurences of the old character
// in the string. If no new character can be found, return false
//******************************************************************
bool LString::allocate_new_rule_char(string &rule)
{
	// The position
  size_t pos      = 0;
	// Find a non-used represented character in the table
  size_t new_rule = new_rule_chars.find_first_not_of(user_rules);
	// No empty pointer
  if (new_rule == string::npos) 
		return false;
	// Check whether the rule exist or not if not replace it
  char   old_char = rule[0], new_char = new_rule_chars[new_rule];

  // Replace all the occurence of character in the rule
  while ((pos = rule.find(old_char, pos)) != string::npos)
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
  user_rules        += the_rule->first_char();
	// Set up the look up table
  SetRule(the_rule);
  return(true);
}

//Methods to change the text value of lines in an Lstring

//******************************************************************
// Deletes a rule from the Lstring
//******************************************************************
void LString::DeleteUserRule(LlineClass *to_delete)
{
	// Replace the delete rule with standard rule or blank
  UnsetUserRule(to_delete);
	// Find the memory space in line and erase it
  vector<LlineClass *>::iterator i = line.begin(); 
  while ((*i) != to_delete)
    ++i;
  line.erase(i);

	// delete the to_delete memory space
  delete to_delete;

}
//******************************************************************
// Replace the_rule with the standard rule if exist or with blank if 
// no corresponding rule exists
//******************************************************************
bool LString::UnsetUserRule(LlineClass *the_rule)
{
	// Let the replacement rule to " ="
  LlineClass *replacement_rule = DefaultStdRule;
	// If the rule is not user rule or increment rule
  if ((the_rule->get_marker() != USER_RULE) &&
      (the_rule->get_marker() != FZ_RULE))
    return false;

  // Find the appropriate Standard Rule, if any or it will be brank rule
  for (std::vector<LlineClass *>::iterator i = StdRule.begin(); i !=StdRule.end(); ++i)
    if ((*i)->first_char() == the_rule->first_char()) {
      replacement_rule = *i;
      break;
    }

  // Clear the first character in the user rule
  user_rules.replace(user_rules.find(the_rule->first_char()), 1, "");
	// reduce the user counting
  num_axiom_and_rule_chars -= the_rule->info_length() - 2;
	// Replace with standard rule or the blank rule
  SetRule(replacement_rule, the_rule->first_char());
  return true;
}

//******************************************************************
// Replace the user define rule
//******************************************************************
bool LString::ReplaceUserRule(string to_insert, LlineClass *to_replace)
{
	// Extract the information out
  to_insert = snip_line(to_insert);
  // No information in the replace text
  if (to_insert.length() == 0) {
    Warning("The replace line is empty");
    return false;
  }
  
  // The first rule is not the same, and we could not find a user rule with the same first character
  if ((to_insert[0] != to_replace->first_char()) &&
      (user_rules.find(to_insert[0]) != string::npos)) {
		  Warning("The rule identification character is not the same");
			return false;
  }// end of if
	// Remove the user Rule of to_replace
  UnsetUserRule(to_replace);
  // Reset the user rule
  switch (to_insert[0]) {
		case '#':
			to_replace->assign(to_insert, COMMENT);
			break;
    
		case 'F':
		case 'f':
		case 'Z':
		case 'z':
			to_replace->assign(to_insert, FZ_RULE);
	    break;
		default:
			to_replace->assign(to_insert, USER_RULE);
  }
	// Set up the look up table
  SetUserRule(to_replace);
  return true;
}
