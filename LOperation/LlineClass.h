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
#ifndef _LLINECLASS_H
#define _LLINECLASS_H

#include "../global/globals.h"
#include "../global/Defines.h"
#include <string>
#include <vector>

class LlineClass 
{
	// Member
	private:
		std::string     the_text;
		size_t     end_text;
		line_label marker;

	public:
		//************************************************
		// Constructor and assignment
		//************************************************
		// The_list is a look up table for all rules
		LlineClass();
		LlineClass(std::vector<LlineClass *> &the_list);
		LlineClass(std::vector<LlineClass *> &the_list, LlineClass& cpy);
		// Assign the text and marker into the line class
		void                assign(char *const rule_in, line_label marker_in);
		void                assign(const std::string rule_in, line_label marker_in);
		//************************************************
		// Extract value
		//************************************************
		// Return the text
		std::string text();
		// Set the start up marker place
		void         set_marker(line_label marker_in);
		// Get the marker information
		line_label	 get_marker();
		// The std::string size
		size_t       info_length();
		// Find the first character of the text
		char         first_char();
		// The character at the memory space
		char         char_num(int i);
		// Normally the rule is a=... and third character would be start of the rule
		char         *rule_start();
		// Return the replace rule information
		std::string  rule_info();
		// Check whether text contain the floating data from pos + 1
		bool         has_value(size_t pos);
		// Check whether starting of the text contain the floating data
		bool                is_float();
		// Return starting of the text contain the floating data
		float               as_float();

		// Check wether the_pos is within bracket and a, b indicate ")" and "("
		bool							  within_round_brackets(size_t the_pos, size_t &start, size_t &end);
		// Check wether the_pos is within bracket
		bool								within_round_brackets(size_t the_pos);
		// Find the matching bracket (), {}, [] and return the other's position
		size_t							matching_bracket(size_t the_pos);
		double							assoc_param(const size_t the_pos, int& the_length);
		bool								increment(size_t &the_pos);
		bool								decrement(size_t &the_pos);
		// Print out the string information
		void                print();
};

#endif _LLINECLASS_H