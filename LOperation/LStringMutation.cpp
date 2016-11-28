/*******************************************************************************
		Main Program:	Viewer.cpp

		Comment:			Rule Operator

		Author:				Yu-Chi Lai, yu-chil@cae.wisc.edu

		Due Date:			

		Course:				CS777, Spring 2003
		DefaultRule " = "
******************************************************************************/
#include "LString.h"
#include "../math/ExtraMath.h"

///////////////////////////////////////////////////////////////////////////////
// Mutation Routines 
///////////////////////////////////////////////////////////////////////////////
//******************************************************************
// Change the generate variable: recursion, angle, thickness
//******************************************************************
void LString::mutate_General_Parameter()
{
	printf("Mutating parameter\n");
  if (Rnd() < (MutParam.pr_R + MutParam.pr_A + MutParam.pr_T))
    mutate_Variable();
  else
    mutate_ChangeRuleParameter();
}

//******************************************************************
// Mutate the three variables
//******************************************************************
void LString::mutate_Variable()
{
	printf("Mutating variable: ");
	// Generate a random variable
  float32   randnum= Rnd() * (MutParam.pr_R + MutParam.pr_A + MutParam.pr_T);
	//****************************************
	// if randnum < pr_R
	//    mutate recursion
	// else if randnum < pr_R + pr_A
	//    mutate angle
	// else 
	//    mutate thickness
	//
	//***************************************
  if (randnum < MutParam.pr_R) {
    //mutate recursion level
		printf("recursion parameter augmented by");
		// Check whether the grow have been set up or not
    if (this->growing()) {
      float v;
			float min = 0;
			float max = g_cInfinite;
      int   i = MutParam.MaxMutTries;
      while (i--) {
				v = Normalize(0, MutParam.R_stdev);  
				printf(" %f:",v);
				// Get the real level value back
				v += this->get_lev() - 1 + this->get_fraction();
				// The value is within limit
				if ((v >= min) && (v <= max)) {
					ReplaceVariable(v, REC_VARIABLE);
					printf("suceeded!");
					break;
				}// end of if
				else 
					printf("failed;");
			}// end ofwhile
		}// end of if growing
		else {
			int v;
			int min = 0;
			int max = (int) g_cInfinite;
			int i = MutParam.MaxMutTries;
			while (i--) {
				v=(int) (Normalize(0,MutParam.R_stdev));
				printf(" %i:",v);
				v += this->get_lev();
		
				if ((v >= min) && (v <= max)) {
					ReplaceVariable(v, REC_VARIABLE);
					printf("suceeded!");
					break;
				} // if
				else 
					printf("failed;");
			}// end of while
		}// end of else
  }// end of if rand < MutParam.pr
	else if (randnum < (MutParam.pr_R + MutParam.pr_A)) {
    //mutate angle
    float v; 
		float min = ANGLE_MIN;
		float max=ANGLE_MAX;
    int   i = MutParam.MaxMutTries;
		printf("default angle parameter augmented by");
    while (i--) {
      v = Normalize(0,MutParam.A_stdev);
			printf(" %f:",v);
      v += this->get_ang();
      if ((v >= min) && (v <= max)) {
				ReplaceVariable(v, ANG_VARIABLE);
				printf("suceeded!");
				break;
      } // end of if
			else 
				printf("failed;");
    }// end of while
  } 
	else {
    //mutate thickness
    float v;
		float min = 0;
		float max = THICK_MAX;
    int   i = MutParam.MaxMutTries;
		printf("starting thickness parameter augmented by");
    while (i--) {
      v = Normalize(0, MutParam.T_stdev);
			printf(" %f:",v);
      v += this->get_thick();
      if ((v >= min) && (v <= max)) {
				ReplaceVariable(v, THICK_VARIABLE);
				printf("suceeded!");
				break;
      }// end of if
			else 
				printf("failed;");
    }// end of while
  }// end of else
	printf("\n");
}

//******************************************************************
// Changes the string in one of the 3 variable lines
// Assign the three variable in string variable
//******************************************************************
bool LString::ReplaceVariable(const std::string new_value, const var_line_label which)
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
  
  std::string tempStr;
  char   tempChr[40];
	// Extract the information out of the origin string
  tempStr = line_ptr[(single_line_label)which]->text();
	// Create the string
  _snprintf(tempChr, 39, "%f", new_value);
  tempStr.replace(0, line_ptr[(single_line_label) which]->info_length(), tempChr);
  
  return ReplaceVariable(tempStr, which);
}

//******************************************************************
// Changes the value in one of the 3 variable lines to an int
// whilst keeping any comments that were there previously
//******************************************************************
bool LString::ReplaceVariable(const int new_value, const var_line_label which)
{
  
  std::string tempStr;
  char   tempChr[40];
  
  tempStr=line_ptr[(single_line_label) which]->text();
  _snprintf(tempChr,39,"%i",new_value);
  tempStr.replace(0, line_ptr[(single_line_label) which]->info_length(),tempChr);
  
  return ReplaceVariable(tempStr, which);
}

//******************************************************************
//******************************************************************
void LString::mutate_ChangeRuleParameter()
{
  std::vector<LlineClass *>::iterator  theFoundLine;
  int                             i;
  int                             theFoundPos, theParamLength;
  char                            theFoundChar;
  float                           theFoundParam, min = 0, max = 0;
  float                           pr_lose=0,pr_gain=0,base_val=0,stdev=0;

  //pick a character
  i = MutParam.MaxMutTries;
  while(i--) {
		printf("Mutating : changing parameter ");
    //make sure it is one that can have a parameter
    theFoundChar = pick_axiom_or_rule_char(false, theFoundLine, theFoundPos);
		printf("in %s ", (line_ptr[AXIOM_LINE] == (*theFoundLine)) ? "Axiom" : (string("Rule ") + (*theFoundLine)->first_char()).c_str());

		// Check whether the found character is bracket character
    if (bracketed_chars.find(theFoundChar) != std::string::npos)
      break;
		printf("at pos %i, char %c rejected.\n" ,theFoundPos, theFoundChar);
  }// end of while

	// Fail to mutate the rule
  if (i <= 0)
		return;
	
	printf("at pos %i, char %c accepted. " ,theFoundPos, theFoundChar);

	// Check whether the selected character are length character
  if (length_chars.find(theFoundChar) != std::string::npos) {
		// set up the gain and lose 
    pr_gain = MutParam.pr_length_gain_brack;
    pr_lose = MutParam.pr_length_lose_brack;
		
		// Check what character we found and set up corresponding parameter
    if(full_length_chars.find(theFoundChar) != std::string::npos) {
      stdev = MutParam.length_stdev;
      min   = 0; 
			max   = g_cInfinite;
      base_val = UI_DIST;
    }
		else if(half_length_chars.find(theFoundChar) != std::string::npos) {
      stdev    = MutParam.length_stdev / 2.0;
      min = 0; 
			max = LENGTH_MAX;
      base_val = UI_DIST / 2.0;
    } 
		else {
     stdev = MutParam.length_decr_stdev;
     min = 0;
		 max = g_cInfinite;
		 // Check whether this is increment or decrement parameter
     if (increment_length_chars.find(theFoundChar) != std::string::npos)
				base_val = 1.0 / LENGTH_DECR;
     else if (decrement_length_chars.find(theFoundChar)!=std::string::npos)
				base_val = LENGTH_DECR;
     else 
			Warning("cannot find length character");
		}// end of else  length character check
  }// length increment
  //******* angle character ******
	else if (angle_chars.find(theFoundChar) != std::string::npos) {
		// Set up the angle gain
    pr_gain = MutParam.pr_angle_gain_brack;
    pr_lose = MutParam.pr_angle_lose_brack;
    if(other_angle_chars.find(theFoundChar) != std::string::npos) {
      stdev = MutParam.angle_stdev;
      min = ANGLE_MIN;
			max = ANGLE_MAX;
      base_val=get_ang();
    }
		else {
      stdev    = MutParam.angle_decr_stdev;
      min=0; max=ANGLE_MAX;
      if (decrement_angle_chars.find(theFoundChar)!=std::string::npos)
				base_val = ANGLE_DECR;
      else if (increment_angle_chars.find(theFoundChar)!=std::string::npos)
				base_val=1.0/ANGLE_DECR;
      else
				Warning("cannot find angle character");
    }
  }
  //******* thickness character ******
	else if (thick_chars.find(theFoundChar)!=std::string::npos) {
    pr_gain = MutParam.pr_thick_gain_brack;
    pr_lose = MutParam.pr_thick_lose_brack;
    stdev   = MutParam.thick_decr_stdev;
    min = 0;
		max = THICK_MAX;
    if (increment_thick_chars.find(theFoundChar) != std::string::npos)
      base_val = 1.0 / THICK_DECR;
    else if(decrement_thick_chars.find(theFoundChar) != std::string::npos)
      base_val=THICK_DECR;
    else
      Warning("cannot find thickness character");
  }
  //******* colour character ******
	else if (colour_chars.find(theFoundChar)!=std::string::npos) {
    pr_gain = MutParam.pr_colour_gain_brack;
    pr_lose = MutParam.pr_colour_lose_brack;
    base_val  = 2;
    stdev     = 0;
    min=0; max=COLOUR_MAX;
    
  }
  //******* Gravity trope character ******
 	else if (trope_chars.find(theFoundChar) != std::string::npos) {
    pr_gain = MutParam.pr_trope_gain_brack;
    pr_lose = MutParam.pr_trope_lose_brack;
    base_val  = UI_TR;
    stdev     = MutParam.tr_stdev;
    min=0; max=1;
  }
  //******* ~ character ******
	else if (randrot_chars.find(theFoundChar)!=std::string::npos) {
    pr_gain = MutParam.pr_randrot_gain_brack;
    pr_lose = MutParam.pr_randrot_lose_brack;
    base_val  = UI_RAND_AMOUNT;
    stdev     = MutParam.randrot_stdev;
    min=0; max=180;
  }
	else {
    char msg[]="\"*\" character found - don't know how to add or delete a parameter!";
    msg[1] = theFoundChar;
    Warning("LString::mutate_ChangeRuleParameter");
  }

  //replace base by user specified parameter, if present
  theFoundParam = (*theFoundLine)->assoc_param(theFoundPos, theParamLength);
  if (theParamLength > 2) 
    base_val = theFoundParam;

  //make a copy of the line
  std::string tempStr =(*theFoundLine)->text();  
  
  //does it have a parameter
  float r=Rnd();
	printf("(r=%f) ",r);
  if ((theParamLength >= 3) && (r < pr_lose)) {         //remove
    tempStr.replace(theFoundPos + 1, theParamLength,"");
		printf("parameter removed\n");
  }
	else if (((theParamLength>=3) && (r>pr_lose)) ||
					((theParamLength< 3) && (r<pr_gain)) ) {       //change
    float param;
    int i = MutParam.MaxMutTries;
		printf("Parameter changed by");
    while(i--) {
			param =  Normalize(0,stdev);
			printf(" %f: ",param);
			param += base_val;
			if ((param>=min) && (param<=max)) {
				char pStr[50];
				if (colour_chars.find(theFoundChar)!=std::string::npos) 
					_snprintf(pStr, 49, "(%i)",(int) param);
				else
					_snprintf(pStr, 49, "(%f)",param);
				tempStr.replace(theFoundPos+1,theParamLength,pStr);
				printf("suceeded!");
				break;
			}// end of if
			else 
				printf("failed; ");
	  }// end of while
  }// end of else if
	else 
		printf("Nothing done");

	printf("\n");

  if ((*theFoundLine) == line_ptr[AXIOM_LINE])
    ReplaceAxiom(tempStr);
  else
    ReplaceUserRule(tempStr, *theFoundLine);
}

//******************************************************************
// Picks a random character in the LString, either from the Axiom,
// or from the right hand side of a rule, and returns the character. 
// The returned character may also be '\0', which indicates that the 
// end of a line has been picked. The line in which the character 
// resides is returned in "ln_itr", and the position in that line 
// is returned in "char_pos".
// Pick up method
// If "random_line" is false, the character is picked randomly from all possible characters. 
// If "random_line" is true, a line is picked at random, and a character then picked at random from that line.
// This second method of picking a character will not bias mutation towards occuring in longer rules.
//******************************************************************
char LString::pick_axiom_or_rule_char(const bool random_line, std::vector<LlineClass *>::iterator &ln_itr, int &char_pos)
{
	// The string is false
  if(!valid_string)
    Warning("Not a valid string");

  // Point line_itr to the axiom to neglect the standard rule and variable rule
  ln_itr = line.begin();
  while(*ln_itr != line_ptr[AXIOM_LINE])
    ++ln_itr;
  
  // If there are no characters in the axiom or rules, point to the 
  // end of the (presumably empty) axiom
  if (num_axiom_and_rule_chars == 0) {
    char_pos = 0;
    return '\0';
  }
  
  std::vector<LlineClass *>::iterator ln_itr2 = ln_itr;
  int ln_cnt = 0, lsize, rand_pos, rand_ln;

  // Otherwise, count the number of non-comment lines
  while (ln_itr2 != line.end()) {
    if ((*ln_itr2)->get_marker() != COMMENT)
      ln_cnt++;
    ++ln_itr2;
  }
	printf("(there are %i mutable lines)", ln_cnt);


  // Initially set the line size to that of the Axiom line + 1 
  // (to include the end of line character) 
  lsize  = line_ptr[AXIOM_LINE]->info_length() + 1;
	printf(".");
  if (random_line) {
		printf("rl");

    // Pick a line at random...
    rand_ln=static_cast<int>(floor(Rnd() * ln_cnt));
    while (rand_ln != 0) {
      ++ln_itr;
      if (((*ln_itr)->get_marker() != COMMENT) &&
					((*ln_itr)->info_length()>=2) ){
					//reset line size to RHS of rule + end char
					lsize=(*ln_itr)->info_length()-1; 
					rand_ln--;
      }// end of if
    }// end of while
    rand_pos = static_cast<int>(floor(Rnd() * lsize)); //rnd char in line
  } 
	//*******************************************************
  // Or pick a random character from the entire string 
	//*******************************************************
	else {          
		printf("rc");
    rand_pos = static_cast<int>(floor(Rnd() * num_axiom_and_rule_chars + ln_cnt));
    while (rand_pos>=lsize) {
      ++ln_itr;
      if (((*ln_itr)->get_marker()!=COMMENT) &&
				 ((*ln_itr)->info_length()>=2) ){
				rand_pos -= lsize;
				//reset line size to RHS of rule + end char
				lsize=(*ln_itr)->info_length()-1;
      }// end of if
    }// end of while
  }// end of else
	printf(".");

  //Now finish off
  char_pos = (*ln_itr)->info_length() - rand_pos;//pick char from end
	printf(".");  
  if (rand_pos == 0) //end of line
    return '\0';
  else
    return (*ln_itr)->char_num(char_pos);
}

//******************************************************************
// Replace the user define rule
//******************************************************************
bool LString::ReplaceUserRule(std::string to_insert, LlineClass *to_replace)
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
      (user_rules.find(to_insert[0]) != std::string::npos)) {
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

//******************************************************************
// Mutate the general rule
//******************************************************************
void LString::mutate_General_Algorithm()
{
  float r1 = Rnd(), r2 = Rnd();
	printf("Mutating algorithm (r1=%f, r2=%f)\n",r1,r2);
	printf("mp=%f\n",MutParam.pr_add_or_del_rule);
  // Check whether to add new rule or
	if (r1 < MutParam.pr_add_or_del_rule) {
		// Add new rule
    if (r2 < MutParam.pr_add_rule) 
      mutate_AddRule();
		// delete new rule
    else
      mutate_DeleteRule();
  } 
	// Change rule
	else {
    if (r2 < MutParam.pr_add_to_rule)
      mutate_ChangeRuleAdd();
    else
      mutate_ChangeRuleDelete();
  }// end of else
}

//******************************************************************
// Add new rule default new rule
//******************************************************************
void LString::mutate_AddRule()
{
	printf("Mutating : rule added\n");
  string new_rule = new_rule_start;
  new_rule += MutParam.DefaultNewRule;
  InsertUserRule(new_rule);
}

//******************************************************************
// Delete original rule
//******************************************************************
bool LString::mutate_DeleteRule()
{
	printf("Mutating : rule deleted\n");
	// No user rule exists
  if (user_rules.length() == 0)
		return false;

	std::string temp;
  size_t			d_pos;
	// Random generate a character in user rule to delete and find the character and line
  int   to_del = static_cast<int>(floor(Rnd() * user_rules.length()));
  char  rule_to_del       = user_rules[to_del];
  LlineClass *line_to_del = RuleForChar[rule_to_del];
	// Delete the rule  
  DeleteUserRule(line_to_del);

	//**************************************************************
  // Delete references to this rule in other rules or in the axiom
	//**************************************************************
  std::vector<LlineClass *>::iterator line_itr = line.begin();
  while  (*line_itr != line_ptr[AXIOM_LINE])
    ++line_itr;

	// Find the line and delete it
  while (line_itr != line.end()){
    temp=(*line_itr)->text();
    if ((d_pos=temp.find(rule_to_del)) != std::string::npos) {
      do {
					temp.replace(d_pos,1,"");
					d_pos=temp.find(rule_to_del,d_pos);
      } while (d_pos != std::string::npos);
      if (*line_itr == line_ptr[AXIOM_LINE])
				ReplaceAxiom(temp);
      else
				ReplaceUserRule(temp,*line_itr);
    }
    ++line_itr;
  }
  return true;
}

//******************************************************************
//
//******************************************************************
void LString::mutate_ChangeRuleDelete()
{
  std::vector<LlineClass *>::iterator line_itr;
  int                 char_pos;
  char                found_char;
  bool                searching=true;
  std::string              tempStr;

  for (unsigned int i = 0; i < MutParam.MaxMutTries; i++) {
		printf("Mutating : removing character ");
    found_char = pick_axiom_or_rule_char(false, line_itr, char_pos);
    tempStr = (*line_itr)->text();
		printf("from %s at position %i, ",  (line_ptr[AXIOM_LINE]==(*line_itr)) ? "Axiom" : (string("Rule ")+(*line_itr)->first_char()).c_str(), char_pos);
    if (found_char == '\0') {
    } 
		else if (found_char=='.') {
      if ((*line_itr)->within_round_brackets(char_pos) == false) {
				searching=false;
				break;
      }
    } // end of else if
		else if (mutable_chars.find(found_char) != std::string::npos) {
      searching=false;
      break;
    }// end of else if
		printf("should not remove \"%c\" - trying again\n",found_char); 
  }// end of for
  
  size_t c = 0;
  if (searching == false)  {
		printf("removing char %c\n",found_char); 
    if ((found_char=='{') || (found_char == '[')) {
			c = (*line_itr)->matching_bracket(char_pos);
			if (c!=std::string::npos) {
				tempStr.replace(c,1,"");
				tempStr.replace(char_pos,1,"");
			}// end of if
		}// end of if
		else {
			int length;
			(*line_itr)->assoc_param(char_pos, length);
			tempStr.replace(char_pos, 1+length, "");
		}// end of else
      
		if ((*line_itr)==line_ptr[AXIOM_LINE])
			ReplaceAxiom(tempStr);
		else
		ReplaceUserRule(tempStr,*line_itr);
	}// end of if
}

//******************************************************************
//
//******************************************************************
void LString::mutate_ChangeRuleAdd()
{
  int                              insertion_point=-1;  
  LlineClass                       *insertion_line=NULL;
  std::vector<LlineClass *>::iterator   line_itr;

  for (unsigned int i=0;i<MutParam.MaxMutTries;i++) {
		printf("Mutating : adding character ");
    pick_axiom_or_rule_char(true, line_itr, insertion_point);
		printf("to %s at position %i, ", (line_ptr[AXIOM_LINE]==(*line_itr)) ? "Axiom" : (string("Rule ")+(*line_itr)->first_char()).c_str(), insertion_point);    
    if ((insertion_point==(*line_itr)->info_length()) ||
			 ((*line_itr)->within_round_brackets(insertion_point)==false)) {

      //now into the serious body of the function.
      //first pick a character to insert
      std::string poss_new_chars = length_chars+angle_chars+colour_chars+
	                      thick_chars+extra_chars+user_rules+"[{";
      char   char_picked    = poss_new_chars[static_cast<int>(floor(Rnd()*poss_new_chars.length()))];
			printf(" picked %c to add, ",char_picked);
      //insert the character(s)
      size_t other_bracket;
      int    move_chars;
      std::string tempStr      =(*line_itr)->text();
      char   corresponding_bracket='}';
      
      //tackle the situation where we are inserting an opening bracket
      //this is complicated, since we need to add the closing bracket too
      switch (char_picked) {
				case '[':
					corresponding_bracket=']';
				case '{':
					other_bracket = insertion_point;
					move_chars=static_cast<int>((Normalize(0,MutParam.new_brack_dist_stdev)));
					printf("bracket distance is %i",move_chars);
					if (move_chars<0) {
						while ((move_chars) && ((*line_itr)->decrement(other_bracket)))
							move_chars++;
						tempStr.insert(insertion_point,1,corresponding_bracket);
						tempStr.insert(other_bracket,1,char_picked);
					}
					else {
						while ((move_chars) && ((*line_itr)->increment(other_bracket)))
							move_chars--;
						tempStr.insert(other_bracket,1,corresponding_bracket);
						tempStr.insert(insertion_point,1,char_picked);
					}
					printf("other bracket inserted at pos %i\n",other_bracket);
				break;
				default:
					tempStr.insert(insertion_point,1,char_picked);
					printf("\n");
      }// end of swithc
      
      if ((*line_itr)==line_ptr[AXIOM_LINE])
				ReplaceAxiom(tempStr);
      else
				ReplaceUserRule(tempStr,*line_itr);
      return;
    }
		else {
			printf(" tried to add within () - trying again\n");
    }
  } //end i (loop to try to find a valid char) 
}

//******************************************************************
// Deletes a rule from the Lstring
//******************************************************************
void LString::DeleteUserRule(LlineClass *to_delete)
{
	// Replace the delete rule with standard rule or blank
  UnsetUserRule(to_delete);
	// Find the memory space in line and erase it
  std::vector<LlineClass *>::iterator i = line.begin(); 
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

