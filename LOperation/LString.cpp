/*******************************************************************************
		Main Program:	Viewer.cpp

		Comment:			Basic LString Operator

		Author:				Yu-Chi Lai, yu-chil@cae.wisc.edu

		Due Date:			

		Course:				CS777, Spring 2003
*******************************************************************************/
#include "LString.h"
//**************************************************
// Constructor
//**************************************************
// Need to be test
LString::LString(MutationParameters& mut_param): MutParam(mut_param)
{
	// Printf the starting message
  printf("starting LString construction...\n");
	// Initialize the string variable 
	FinalString = NULL;
	// Initialize the line class
	DefaultStdRule = NULL;

	// Set the end character of the string
	//CountChar should be an unsigned char 
  CountChar[127]='\0';     

	//string with ascii 128, 129, 130 etc. 
	//terminated (as all char strings) with \0
  for (int i = 0; i < 127; i++)  
    CountChar[i] = 128 + i;    

	// Set up the general standard rule
  GenerateStdRules();

	// Clear all the data and flag
  Clear();
	// Print the finish message
  printf("finished the LString\n");  
}

//***********************************************************************************
// Clear the string informaiton
//***********************************************************************************
void LString::Clear()
{
	// Print the message
	printf("Clearing\n");

  //clear the user lines
  for (std::vector<LlineClass *>::iterator it = line.begin(); it != line.end(); ++it)
		delete *it;
	printf(".\n");
  line.clear();

	// Clear the user_rules
	printf(".\n");
  user_rules="";

	// The number of basic axiom and rule character
  num_axiom_and_rule_chars = 0;
	// From enum release the memory of recursion, angle, thickness, and axiom
  line_ptr[REC_LINE]		= NULL;
  line_ptr[ANG_LINE]		= NULL;
  line_ptr[THICK_LINE]	= NULL;
  line_ptr[AXIOM_LINE]	= NULL;
	printf(".\n");

	//************************************************
  //Free the FinaLString memory, should be changed
	//************************************************
  valid_string = false;
	OutputString = "";
  FinalString = NULL;
  FS_Lgth			= 0;
  FS_Lev			= 0;
	printf(".\n");

	// Set up the standard RuleChar table
  SetStdRules();
	printf("ended\n");
}

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
  sprintf(c3,"%.1s=%.1s",&CountChar[i - 1], &CountChar[0]);
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
  // Initialize all look up table to default rule
  for(unsigned int n = 0; n < 256; n++)
    SetRule(DefaultStdRule, (unsigned char)n);

  for(std::vector<LlineClass *>::iterator i = StdRule.begin(); i != StdRule.end(); ++i)
		SetRule(*i);
}
//******************************************************************
// Use the first character of "the_rule" as the index in RuleForChar
//******************************************************************
void LString::SetRule(LlineClass *the_rule)
{
  SetRule(the_rule, the_rule->first_char());
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
// Simply point the RuleForChar array at the_rule
//******************************************************************
void LString::SetRule(LlineClass *the_rule, unsigned char the_pos)
{ 
  RuleForChar[the_pos] = the_rule;
}

//**********************************************************************************
// Destructor
//**********************************************************************************
LString::~LString()
{
	// Clear all the information
  Clear();

	// Release the memory allocate for the standard rule
	for(int i = 0; i < StdRule.size(); i++)
		delete StdRule[i];

	// Clear the rule
  StdRule.clear();
}
