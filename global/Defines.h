#ifndef _DEFINES_H
#define _DEFINES_H
#include "globals.h"
#include <string>

#define UI_DIST 100 // derive from the canvas
#define UI_TR   0.2
#define UI_MIN_THICK 1// problem
#define UI_RAND_AMOUNT 100
#define UI_IS_RAND_SET  false
#define UI_IS_TROPE_SET false
#define UI_TROPE_AMOUNT 0.0


// some constants used in the Lstring 
const float LENGTH_MAX	= 10000.0f;
const float LENGTH_DECR = 0.9f;
const float ANGLE_DECR	= 0.9f;
const float ANGLE_MIN		=	0.0f;
const float ANGLE_MAX		=	1000.0f;
const float THICK_DECR	=	0.7f;
const float THICK_MAX		=	200.0f;
const float COLOUR_MAX	=	200.0f;


// Some often used consts 
const float32		zero				= 0.0;
const float32		one					= 1.0;
const float VIEW_ASPECT	= 1.3f;
const float VIEW_ANGLE	= 3.0f; //in degrees


//***********************************************************
// Enum for operation
//***********************************************************
enum line_label {
	RECURSION=0,					// Go into recursion
	ANGLE,								// Rotation angle
	THICKNESS,						// The thickness
	AXIOM,								// The basic pattern
	FZ_RULE,							// FZ rules
	USER_RULE,						// user define rules
	STANDARD_RULE,				// standard rules
	COMMENT								// The comment
};

enum single_line_label {
	REC_LINE		= RECURSION, // Recursion label
	ANG_LINE		= ANGLE,		 // Angle label
	THICK_LINE	= THICKNESS, // Thickness lable
	AXIOM_LINE	= AXIOM			 // The axiom
};

enum {single_line_label_num = 4};

enum var_line_label {
	REC_VARIABLE		=	RECURSION,	// Recursion label
	ANG_VARIABLE		=	ANGLE,			// Angle label
	THICK_VARIABLE	=	THICKNESS		// Thickness label
};


//************************************************************************************
// Some default strings
//************************************************************************************
const std::string new_rule_start("@=");
const std::string default_rec_string("5 #this is the default recursion level, inserted to replace a badly formatted line");
const std::string default_ang_string("45 #this is the default angle, inserted to replace a badly formatted line");
const std::string default_thick_string("50 #this is the default starting thickness, inserted to replace a badly formatted line");

//************************************************************************************
// Size of memory allocation chunks for final string array
//************************************************************************************
const unsigned long FS_Chunk=10000;

//Define useful characters
const std::string whitespace("\t ");						// White space
const std::string endline_markers("\n");				// end of the line
const std::string full_length_chars("Ffg");		// The forward full length characters
const std::string half_length_chars("Zz");			// The forward half length characters
const std::string increment_length_chars("\"");// Increment the length
const std::string decrement_length_chars("\'");// Decrement the length
const std::string increment_angle_chars(";");	// Increment the angle
const std::string decrement_angle_chars(":");	// Decrement the angle
const std::string other_angle_chars("+-<>&^"); // Rotation direction
const std::string increment_thick_chars("?");	// Increment the thickness
const std::string decrement_thick_chars("!");	// Decrement the thickness
const std::string colour_chars("c");						// Color 
const std::string trope_chars("t");						//
const std::string randrot_chars("~");					//
const std::string extra_chars("|%$.");					//
const std::string new_rule_chars("ABCDEGHIJKLMNOPQRSTUVWXYabcdehijklmnopqrsuvwxy"); // All possible operation character
const std::string inbrackets_chars("0123456789. ");// number character
const std::string open_mutable_brackets("[{");		// bracket
// All possible character for length operation
const std::string length_chars = full_length_chars + 
														half_length_chars +
														increment_length_chars + 
														decrement_length_chars;

// All possible character for angle operation
const std::string angle_chars	= increment_angle_chars	+
														decrement_angle_chars + 
														other_angle_chars;

// All possible character for thickness operation
const std::string thick_chars	= increment_thick_chars +
														decrement_thick_chars;

// All possible character for character in bracket
const std::string bracketed_chars = length_chars + 
															 angle_chars +
															 thick_chars + 
															 colour_chars +
															 trope_chars +
															 randrot_chars;
// Don't include close brackets, otherwise brackets will have twice the chance of mutating
// to other characters
const std::string mutable_chars = length_chars + 
														 angle_chars +
														 thick_chars +
														 colour_chars +
														 trope_chars +
														 randrot_chars +
														 extra_chars +
														 new_rule_chars +
														 open_mutable_brackets;  

#endif _DEFINES_H