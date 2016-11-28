/*******************************************************************************
		Main Program:	

		Comment:			LString Operator to handle the parsing 


		Author:				Yu-Chi Lai, yu-chil@cae.wisc.edu

		Due Date:			

		Course:				CS777, Spring 2003
*******************************************************************************/
#ifndef _LSTRING_H
#define _LSTRING_H

#include "../global/globals.h"
#include "../global/function.h"

#include "LlineClass.h"
#include "Mutation.h"

#include <fstream>
#include <stdio.h>
#include <math.h>

class LString
{
	//****************************************************
	// Constructor and destructor
	//****************************************************
	public:
		LString(MutationParameters& mut_param);
		~LString();
	private:
		// Clear the memory space
		void Clear();
		// Generate the common rules 
		void GenerateStdRules();
		// Put the_rule into StdRule list
		void GenerateStdRule(char *the_rule);
		// Create the loop up table in RuleForChar
		void SetStdRules();
		// Put the rule pointer into the_pos in the Rule for char array
		void SetRule(LlineClass *the_rule, char the_pos);
		// Put the rule pointer into the_pos in the Rule for char array
		void SetRule(LlineClass *the_rule, unsigned char the_pos);
		// According to the first character put the pointer into RuleForChar array
		void SetRule(LlineClass *the_rule);

	//************************************************
	// Interface function
	//************************************************
	public:
		// Input and output interface
		bool parserFile(char *filename);
		// Interface function
		void operator << (std::string& p);
		// Output
		void operator >> (std::string& out);
		// Assign the Lstring
		LString &operator = (LString& lstr);
		// Print out the LString the information
		void print();

	//***********************************************
	// Input the string include variable, axiom, and user rules
	//***********************************************
	private:
		// Insert three variable
		bool InsertVariable  (std::string &to_insert, var_line_label which);
		// Insert the Axiom
		bool InsertAxiom     (std::string &to_insert);
		// Replace the Axiom
		bool ReplaceAxiom    (std::string to_insert);
		// Insert a user rule into the LString object.		
		bool InsertUserRule(std::string &to_insert);
		// Allocate a new table character for the rule and replace all occurrence in the rule
		bool allocate_new_rule_char(std::string &rule);
		// Add the rule into user_rule and the ruleChar table
		bool SetUserRule(LlineClass *the_rule);

	//*********************************************
	// Get the variable and axiom from the string
	//*********************************************
	public:
		// Get the axiom
		std::string get_axiom();
		// Get the angle
		float  get_ang();
		// Get the thickness
		float  get_thick();
		// Get the decimal part of the recursion => Rec - floor(Rec)
		float  get_fraction();
		// Get the level ceil(Recursion)
		int    get_lev();

		// Get the value in (XX)
		bool   Get_value(unsigned long &current_string_pos, float32 &val);
		// If FinalString[s_pos] is a CountChar, return its position in COuntChar
		int    Get_RecursionChar(unsigned long &s_pos);

		int		 get_LineNumber(std::vector<LlineClass *>::iterator the_line);
		// Get the real recursion this final string go through
		int    FinalStringRecLev();
		// Return the final string and remove all the CountChar
		std::string   FormattedFinalString();
		// Check whether the final string exists or not
		bool   FinalStringExists();
		// The length of the final string
		int    FinalStringLength();
		// The ith character of the string
		unsigned char FinalStringChr(unsigned int i);

	//************************************************
	// Generate the final string
	//************************************************
	public:
		// For recursively created the string
		bool Parse();
		bool Parse(signed short int reclevel); 

	private:
		// Check whether the fraction is existing
		bool growing();
		bool FS_alloc(size_t mem);

	//************************************************************
	// Mutation the string
	//************************************************************
	public:
		// Change the generate variable: recursion, angle, thickness
		void mutate_General_Parameter();
		void mutate_General_Algorithm();
	private:

		// Mutate the three variables
		void mutate_Variable();
		// Replace the corresponding variable
		bool ReplaceVariable (const float  new_value, var_line_label which);
		bool ReplaceVariable (const int    new_value, var_line_label which);
		bool ReplaceVariable (const std::string new_value, var_line_label which);
		// Replace the general rule parameter
		void mutate_ChangeRuleParameter();
		char pick_axiom_or_rule_char(const bool random_line, 
																 std::vector<LlineClass *>::iterator &ln_itr, 
																 int &char_pos);
		// Replace the user rule with to_insert
		bool ReplaceUserRule (std::string to_insert, LlineClass *to_replace);

		// Delete the user rule and allocation of memory
		void DeleteUserRule(LlineClass *to_delete);
		// Replace the user rule with standard rule or blank
		bool UnsetUserRule(LlineClass *the_rule);

		void mutate_AddRule();
		bool mutate_DeleteRule();
		void mutate_ChangeRuleDelete();
		void mutate_ChangeRuleAdd();
		
	// variables
	private:
		unsigned char        CountChar[128]; //

		//******************************************************
		// For character operation's memory allocation
		//******************************************************
		unsigned int         FS_Lgth;						// The lenght of final string
		int                  FS_Lev;						// The total iterations the string go through
		int                  FS_MemSize;				// The total allocate memory size

		//******************************************************
		// The final result
		//******************************************************
		unsigned char        *FinalString;											// Final ineration string for turtle operation
		std::string          OutputString;
		bool                 valid_string;											// Indicate whether the final string is valid

		//******************************************************
		// Input message
		//******************************************************
		std::vector<LlineClass *> line;													// All the user input information string space
		std::vector<LlineClass *> StdRule;											// List for standard rule
		LlineClass           *DefaultStdRule;										// The default rule to any unrecognize variable
		LlineClass           *RuleForChar[256];									// The look up table for the character => rule class
		LlineClass           *line_ptr[single_line_label_num];	// Line pointer to the recursion, angle, thickness, axiom
		std::string          user_rules;												// User created rules string
		int                  num_axiom_and_rule_chars;					// The number of character in axiom

		// The mutation parameter
		MutationParameters&  MutParam;

};

#endif _LSTRING_H
