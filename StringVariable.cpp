/*******************************************************************************
		Main Program:	

		Comment:			Variable operation

		Author:				Yu-Chi Lai, yu-chil@cae.wisc.edu

		Due Date:			

		Course:				CS777, Spring 2003
******************************************************************************/
#include "LString.h"
#include "../global/function.h"

////////////////////////////////////////////////////////////////////////////////
//
// Method to handle the variable and axiom
//
////////////////////////////////////////////////////////////////////////////////

//******************************************************************
// Insert one of the 3 variable lines (recursion, angle, thickness) into the LString.  
// Returns false 
//  1. if the line has not been inserted,
//  2. if the the line is a comment, 
//  3. if "which" turns out not to be one of the 3 variable lines
//******************************************************************
bool LString::InsertVariable(string &to_insert, var_line_label which)
{
	// Variable for store the information string
  string     the_line;

  LlineClass *VarLine;

  //Grab a line from the string
  the_line = snip_line(to_insert);

  // If the line is empty, delete it
  if (the_line.length()==0) {
    Warning("The input line is empty and ignore");
    return false;
  }

  //allocate a new line
  VarLine = new LlineClass(&line);

  // Comment line
  if (the_line[0] == '#') { 
    VarLine->assign(the_line, COMMENT);
    return false;
  }

  VarLine->assign(the_line, (line_label)which);
  switch (which) {
		// Recursion variable
		case REC_VARIABLE:
			// There exists some recursion information
			if (line_ptr[REC_LINE] != NULL)
				Warning("The recursion has already existed");
			// The information is not a number, and we will use the default string
			if (VarLine->is_float() == false) {
				Warning("The recursion line is not a number");
				VarLine->assign(default_rec_string, RECURSION);
			}
			// Assigned the 
			line_ptr[REC_LINE] = VarLine;
			break;
		// Angle variable
		case ANG_VARIABLE:
			// There exists some angle information
			if (line_ptr[ANG_LINE]!=NULL)
				Warning("Angle line already allocated");
			// The information is not a number, and we will use the default string
			if (VarLine->is_float() == false) {
				Warning("The angle line is not a number")
				VarLine->assign(default_ang_string,ANGLE);
			}
			//
  		line_ptr[ANG_LINE] = VarLine;
			break;
  
		// Thickness variable
		case THICK_VARIABLE:
			// There exists some thick information
			if (line_ptr[THICK_LINE] != NULL)
				Warning("thickness line already allocated");
			if (VarLine->is_float() == false) {
				Warning("The thick line is not a number");
				VarLine->assign(default_thick_string,THICKNESS);
			}
			//
			line_ptr[THICK_LINE]=VarLine;
			break;
  }
  return true;
}

//******************************************************************
// Insert an axiom line into the LString object. 
// Returns false if comment or empty line, true otherwise
//******************************************************************
bool LString::InsertAxiom(string &to_insert)
{ 
	// The Axiomline
  LlineClass *AxiomLine;
	// The information
  string the_line;

  // Extract the information out
  the_line=snip_line(to_insert);
  if (the_line.length() == 0) {
    Warning("The axiom line is empty");
    return false;
  }
  
  AxiomLine = new LlineClass(&line);
	// The first word is a comment
  if (the_line[0] == '#') {
    AxiomLine->assign(the_line, COMMENT);
    return false;
  } 
	else {
    if (line_ptr[AXIOM_LINE]!=NULL)
      Warnigg("axiom line already allocated");
		// Allocate the AxiomLine information
    line_ptr[AXIOM_LINE] = AxiomLine;
    if(ReplaceAxiom(the_line) == false) {
				Warning( "error replacing axiom");
				return false;
      }
  }// end of else
  return true;
}
//******************************************************************
// Replaces the axiom line with a new string. 
// Returns false if there is no previous axiom string, 
//               if the replacement is blank or a comment
//******************************************************************
bool LString::ReplaceAxiom(const string to_insert)
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

/****************************************************
 ****** methods for changing a current L string *****
 ****************************************************/
//******************************************************************
// Changes the string in one of the 3 variable lines
// Assign the three variable in string variable
//******************************************************************
bool LString::ReplaceVariable(const string new_value, const var_line_label which)
{
  if (line_ptr[(single_line_label)which] == NULL)
    return false;
  line_ptr[(single_line_label)which]->assign(new_value,(line_label) which);
		return true;
}
//******************************************************************
// changes the value in one of the 3 variable lines to a float
// whilst keeping any comments that were there previously
//******************************************************************
bool LString::ReplaceVariable(const float new_value, const var_line_label which)
{
  
  string tempStr;
  char   tempChr[40];
	// Extract the information out of the origin string
  tempStr = line_ptr[(single_line_label)which]->text();
	// Create the string
  snprintf(tempChr, 39, "%f", new_value);
  tempStr.replace(0, line_ptr[(single_line_label) which]->info_length(), tempChr);
  
  return ReplaceVariable(tempStr, which);
}

//******************************************************************
// Changes the value in one of the 3 variable lines to an int
// whilst keeping any comments that were there previously
//******************************************************************
bool LString::ReplaceVariable(const int new_value, const var_line_label which)
{
  
  string tempStr;
  char   tempChr[40];
  
  tempStr=line_ptr[(single_line_label) which]->text();
  snprintf(tempChr,39,"%i",new_value);
  tempStr.replace(0, line_ptr[(single_line_label) which]->info_length(),tempChr);
  
  return ReplaceVariable(tempStr, which);
}

/////////////////////////////////////////////////////////////////////
//
// Get the variable, and axiom
//
/////////////////////////////////////////////////////////////////////
//******************************************************************
// Get the axiom string
//******************************************************************
string LString::get_axiom()
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
};

//******************************************************************
// Get the level of the line
//******************************************************************
int  LString::get_lev()
{
  double temp=line_ptr[REC_LINE]->as_float();
  return static_cast<s16>(ceil(temp));
}
//******************************************************************
//????????????????????????????????????????
//******************************************************************
r32  LString::get_fraction()
{
  double temp = line_ptr[REC_LINE]->as_float();
  return static_cast<r32>(temp - floor(temp));
}

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
