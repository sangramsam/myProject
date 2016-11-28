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

///////////////////////////////////////////////////////////////////////////////
// Mutation Routines 
///////////////////////////////////////////////////////////////////////////////
//******************************************************************
// Picks a random character in the LString, either from the Axiom,
// or from the right hand side of a rule, and returns the character. 
// The returned character may also be '\0', which indicates that the 
// end of a line has been picked. The line in which the character 
// resides is returned in "line_itr", and the position in that line 
// is returned in "char_pos".
// Pick up method
// If "random_line" is false, the character is picked randomly from all possible characters. 
// If "random_line" is true, a line is picked at random, and a character then picked at random from that line.
// This second method of picking a character will not bias mutation towards occuring in longer rules.
//******************************************************************
char LString::pick_axiom_or_rule_char(const bool random_line, vector<LlineClass *>::iterator &ln_itr, int &char_pos)
{
	// The string is false
  if (valid_string == false)
    Warning("Not a valid string");

  //point line_itr to the axiom
  ln_itr = line.begin();
  while  (*ln_itr != line_ptr[AXIOM_LINE])
    ++ln_itr;
  
  // if there are no characters in the axiom or rules, point to the 
  //end of the (presumably empty) axiom
  if (num_axiom_and_rule_chars==0) {
    char_pos = 0;
    return '\0';
  }
  
  vector<LlineClass *>:: iterator ln_itr2=ln_itr;
  int                             ln_cnt=0, lsize, rand_pos, rand_ln;

  //otherwise, count the number of non-comment lines
  while (ln_itr2!=line.end()) {
    if ((*ln_itr2)->get_marker()!=COMMENT)
      ln_cnt++;
    ++ln_itr2;
  };

printf("(there are %i mutable lines)",ln_cnt);
  //Initially set the line size to that of the Axiom line + 1 
  //(to include the end of line character) 
  lsize  =line_ptr[AXIOM_LINE]->info_length()+1;
printf(".");
  if (random_line) {
printf("rl");
    // *********** Pick a line at random...
    rand_ln=static_cast<int>(floor(Rnd()*ln_cnt));
    while (rand_ln!=0) {
      ++ln_itr;
      if (((*ln_itr)->get_marker()!=COMMENT) &&
	  ((*ln_itr)->info_length()>=2) ){
	//reset line size to RHS of rule + end char
	lsize=(*ln_itr)->info_length()-1; 
	rand_ln--;
      };
    };
    rand_pos = static_cast<int>(floor(Rnd() * lsize)); //rnd char in line
    
    
  } else {          
printf("rc");
    // ************ Or pick a random character from the entire string 
    rand_pos = static_cast<int>(floor(Rnd()*num_axiom_and_rule_chars+ln_cnt));
    while (rand_pos>=lsize) {
      ++ln_itr;
      if (((*ln_itr)->get_marker()!=COMMENT) &&
	  ((*ln_itr)->info_length()>=2) ){
	rand_pos-=lsize;
	//reset line size to RHS of rule + end char
	lsize=(*ln_itr)->info_length()-1;
      };
    };
  };
printf(".");
  //Now finish off
  char_pos = (*ln_itr)->info_length()-rand_pos;//pick char from end
printf(".");  
  if (rand_pos==0) //end of line
    return '\0';
  else
    return (*ln_itr)->char_num(char_pos);
}

//******************************************************************
//******************************************************************
void LString::mutate_General_Parameter()
{
printf("Mutating parameter\n");
  if (Rnd()<(MutParam->pr_R + MutParam->pr_A + MutParam->pr_T))
    mutate_Variable();
  else
    mutate_ChangeRuleParameter();
}

//******************************************************************
//******************************************************************
void LString::mutate_General_Algorithm()
{
  float r1=Rnd(), r2=Rnd();
DEBUGGING_MESSAGE3("Mutating algorithm (r1=%f, r2=%f)\n",r1,r2);
 printf("mp=%f\n",MutParam->pr_add_or_del_rule);
  if (r1<MutParam->pr_add_or_del_rule) {
    if (r2<MutParam->pr_add_rule) 
      mutate_AddRule();
    else
      mutate_DeleteRule();
  } else {
    if (r2<MutParam->pr_add_to_rule)
      mutate_ChangeRuleAdd();
    else
      mutate_ChangeRuleDelete();
  };
}

//******************************************************************
//******************************************************************
void LString::mutate_Variable()
{
printf("Mutating variable: ");
  r32   randnum=Rnd()*(MutParam->pr_R+MutParam->pr_A+MutParam->pr_T);
  if (randnum<MutParam->pr_R) {
    //mutate recursion level
printf("recursion parameter augmented by");
    if (this->growing()) {
      float v, min=0, max=LENGTH_MAX;
      int   i=MutParam->MaxMutTries;
      while (i--) {
	v = N(0,MutParam->R_stdev);  
printf(" %f:",v);

	v+= this->get_lev()-1 + this->get_fraction();
	
	if ((v >= min) && (v <= max)) {
	  ReplaceVariable(v, REC_VARIABLE);
printf("suceeded!");
	  break;
	} else {
printf("failed;");
	};
      };
    } else {
      int v, min=0, max=(int) LENGTH_MAX;
      int i=MutParam->MaxMutTries;
      while (i--) {
	v=(int) (N(0,MutParam->R_stdev));
printf(" %i:",v);
	v += this->get_lev();
	
	if ((v >= min) && (v <= max)) {
	  ReplaceVariable(v, REC_VARIABLE);
printf("suceeded!");
	  break;
	} else {
printf("failed;");
	};
      };
    };
  } else if (randnum< (MutParam->pr_R+MutParam->pr_A)) {
    //mutate angle
    float v, min=ANGLE_MIN, max=ANGLE_MAX;
    int   i=MutParam->MaxMutTries;
printf("default angle parameter augmented by");
    while (i--) {
      v=N(0,MutParam->A_stdev);
printf(" %f:",v);
      v += this->get_ang();
      
      if ((v >= min) && (v <= max)) {
	ReplaceVariable(v, ANG_VARIABLE);
printf("suceeded!");
	break;
      } else {
printf("failed;");
      };
    };
  } else {

    //mutate thickness
    float v, min=0, max=THICK_MAX;
    int   i=MutParam->MaxMutTries;
printf("starting thickness parameter augmented by");
    while (i--) {
      v=N(0,MutParam->T_stdev);
printf(" %f:",v);
      v += this->get_thick();
      if ((v >= min) && (v <= max)) {
	ReplaceVariable(v, THICK_VARIABLE);
printf("suceeded!");
	break;
      } else {
printf("failed;");
      };
    };
  };
printf("\n");
}

//******************************************************************
//******************************************************************
void LString::mutate_AddRule()
{
printf("Mutating : rule added\n");
  string new_rule=new_rule_start;
  new_rule += MutParam->DefaultNewRule;
  InsertUserRule(new_rule);
}

//******************************************************************
//******************************************************************
bool LString::mutate_DeleteRule()
{
printf("Mutating : rule deleted\n");
  if (user_rules.length()==0) return false;

  string temp;
  size_t d_pos;
  int   to_del = static_cast<int>(floor(Rnd()*user_rules.length()));
  char  rule_to_del       = user_rules[to_del];
  LlineClass *line_to_del = RuleForChar[rule_to_del];
  
  DeleteUserRule(line_to_del);
  //delete references to this rule in other rules or in the axiom
  
  vector<LlineClass *>::iterator line_itr = line.begin();
  while  (*line_itr != line_ptr[AXIOM_LINE])
    ++line_itr;

  while (line_itr!=line.end()){
    temp=(*line_itr)->text();
    if ((d_pos=temp.find(rule_to_del))!=string::npos) {
      do {
	temp.replace(d_pos,1,"");
	d_pos=temp.find(rule_to_del,d_pos);
      } while (d_pos!=string::npos);
      if (*line_itr==line_ptr[AXIOM_LINE])
	ReplaceAxiom(temp);
      else
	ReplaceUserRule(temp,*line_itr);
    };
    ++line_itr;
  };
  return true;
}

//******************************************************************
//******************************************************************
void LString::mutate_ChangeRuleDelete()
{
  vector<LlineClass *>::iterator line_itr;
  int                 char_pos;
  char                found_char;
  bool                searching=true;
  string              tempStr;
  for (unsigned int i=0;i<MutParam->MaxMutTries;i++) {
printf("Mutating : removing character ");
    found_char = pick_axiom_or_rule_char(false, line_itr, char_pos);
    tempStr    = (*line_itr)->text();
DEBUGGING_MESSAGE3("from %s at position %i, ",  (line_ptr[AXIOM_LINE]==(*line_itr)) ? "Axiom" : (string("Rule ")+(*line_itr)->first_char()).c_str(), char_pos);
    if (found_char=='\0') {
    } else if (found_char=='.') {
      if ((*line_itr)->within_round_brackets(char_pos) == false) {
	searching=false;
	break;
      };
    } else if (mutable_chars.find(found_char) != string::npos) {
      searching=false;
      break;
    };
printf("should not remove \"%c\" - trying again\n",found_char); 
  };
  
  size_t c=0;
  if (searching==false) 
    {
printf("removing char %c\n",found_char); 
      if ((found_char=='{') || (found_char == '[')) {
	c=(*line_itr)->matching_bracket(char_pos);
	if (c!=string::npos)
	  {
	    tempStr.replace(c,1,"");
	    tempStr.replace(char_pos,1,"");
	  };

      } else {
	int length;
	(*line_itr)->assoc_param(char_pos, length);
	tempStr.replace(char_pos, 1+length, "");
      };
      
      if ((*line_itr)==line_ptr[AXIOM_LINE])
	ReplaceAxiom(tempStr);
      else
	ReplaceUserRule(tempStr,*line_itr);
    };
}

//******************************************************************
//******************************************************************
void LString::mutate_ChangeRuleAdd()
{
  unsigned int r_num;
  int                              insertion_point=-1;  
  LlineClass                       *insertion_line=NULL;
  vector<LlineClass *>::iterator   line_itr;

  for (unsigned int i=0;i<MutParam->MaxMutTries;i++) {
printf("Mutating : adding character ");
    pick_axiom_or_rule_char(true, line_itr, insertion_point);
DEBUGGING_MESSAGE3("to %s at position %i, ", (line_ptr[AXIOM_LINE]==(*line_itr)) ? "Axiom" : (string("Rule ")+(*line_itr)->first_char()).c_str(), insertion_point);    
    if ((insertion_point==(*line_itr)->info_length()) ||
	((*line_itr)->within_round_brackets(insertion_point)==false)) {

      //now into the serious body of the function.
      //first pick a character to insert
      string poss_new_chars = length_chars+angle_chars+colour_chars+
	                      thick_chars+extra_chars+user_rules+"[{";
      char   char_picked    = poss_new_chars[static_cast<int>(floor(Rnd()*poss_new_chars.length()))];
printf(" picked %c to add, ",char_picked);
      //insert the character(s)
      size_t other_bracket;
      int    move_chars;
      string tempStr      =(*line_itr)->text();
      char   corresponding_bracket='}';
      
      //tackle the situation where we are inserting an opening bracket
      //this is complicated, since we need to add the closing bracket too
      switch (char_picked) {
      case '[':
	corresponding_bracket=']';
      case '{':
	other_bracket = insertion_point;
	move_chars=static_cast<int>((N(0,MutParam->new_brack_dist_stdev)));
printf("bracket distance is %i",move_chars);
        if (move_chars<0) {
	  while ((move_chars) && ((*line_itr)->decrement(other_bracket)))
	    move_chars++;
	  tempStr.insert(insertion_point,1,corresponding_bracket);
	  tempStr.insert(other_bracket,1,char_picked);
	} else {
	  while ((move_chars) && ((*line_itr)->increment(other_bracket)))
	    move_chars--;
	  tempStr.insert(other_bracket,1,corresponding_bracket);
	  tempStr.insert(insertion_point,1,char_picked);
	};
printf("other bracket inserted at pos %i\n",other_bracket);
        break;
      
      default:
	tempStr.insert(insertion_point,1,char_picked);
printf("\n");
      };
      
      if ((*line_itr)==line_ptr[AXIOM_LINE])
	ReplaceAxiom(tempStr);
      else
	ReplaceUserRule(tempStr,*line_itr);

      return;
    } else {
printf(" tried to add within () - trying again\n");
    };
  }; //end i (loop to try to find a valid char) 
}

//******************************************************************
//******************************************************************
void LString::mutate_ChangeRuleParameter()
{
  vector<LlineClass *>::iterator  theFoundLine;
  int                             i;
  int                             theFoundPos, theParamLength;
  char                            theFoundChar;
  float                           theFoundParam,min=0,max=0;
  float                           pr_lose=0,pr_gain=0,base_val=0,stdev=0;

  //pick a character
  i=MutParam->MaxMutTries;
  while(i--) {
printf("Mutating : changing parameter ");
    //make sure it is one that can have a parameter
    theFoundChar=pick_axiom_or_rule_char(false,theFoundLine,theFoundPos);
printf("in %s ", (line_ptr[AXIOM_LINE]==(*theFoundLine)) ? "Axiom" : (string("Rule ")+(*theFoundLine)->first_char()).c_str());
    if (bracketed_chars.find(theFoundChar)!=string::npos)
      break;
DEBUGGING_MESSAGE3("at pos %i, char %c rejected.\n" ,theFoundPos, theFoundChar);
  };
  if (i<=0) return;
DEBUGGING_MESSAGE3("at pos %i, char %c accepted. " ,theFoundPos, theFoundChar);

  
  //******* length character ******
  if        (length_chars.find(theFoundChar)!=string::npos) {
    pr_gain = MutParam->pr_length_gain_brack;
    pr_lose = MutParam->pr_length_lose_brack;
    if      (full_length_chars.find(theFoundChar)!=string::npos) {
      stdev    = MutParam->length_stdev;
      min=0; max=LENGTH_MAX;
      base_val = UIClassPtr->get_dis();
    } else if (half_length_chars.find(theFoundChar)!=string::npos) {
      stdev    = MutParam->length_stdev/2.0;
      min=0; max=LENGTH_MAX;
      base_val = UIClassPtr->get_dis()/2.0;
    } else {
      stdev    = MutParam->length_decr_stdev;
      min=0; max=LENGTH_MAX;
      if      (increment_length_chars.find(theFoundChar)!=string::npos)
	base_val = 1.0/LENGTH_DECR;
      else if (decrement_length_chars.find(theFoundChar)!=string::npos)
	base_val = LENGTH_DECR;
      else 
	UIClassPtr->ProgrammingError("LString::mutate_ChangeRuleParameter","cannot find length character");
    };  
    //******* angle character ******
  } else if (angle_chars.find(theFoundChar)!=string::npos) {
    pr_gain = MutParam->pr_angle_gain_brack;
    pr_lose = MutParam->pr_angle_lose_brack;
    if        (other_angle_chars.find(theFoundChar)!=string::npos) {
      stdev    = MutParam->angle_stdev;
      min=ANGLE_MIN; max=ANGLE_MAX;
      base_val=get_ang();
    } else {
      stdev    = MutParam->angle_decr_stdev;
      min=0; max=ANGLE_MAX;
      if      (decrement_angle_chars.find(theFoundChar)!=string::npos)
	base_val = ANGLE_DECR;
      else if (increment_angle_chars.find(theFoundChar)!=string::npos)
	base_val=1.0/ANGLE_DECR;
      else
	UIClassPtr->ProgrammingError("LString::mutate_ChangeRuleParameter",
				     "cannot find angle character");
    };
  //******* thickness character ******
  } else if (thick_chars.find(theFoundChar)!=string::npos) {
    pr_gain=MutParam->pr_thick_gain_brack;
    pr_lose=MutParam->pr_thick_lose_brack;

    stdev    = MutParam->thick_decr_stdev;
    min=0; max=THICK_MAX;
    if      (increment_thick_chars.find(theFoundChar)!=string::npos)
      base_val=1.0/THICK_DECR;
    else if (decrement_thick_chars.find(theFoundChar)!=string::npos)
      base_val=THICK_DECR;
    else
      UIClassPtr->ProgrammingError("LString::mutate_ChangeRuleParameter","cannot find thickness character");
    
  //******* colour character ******
  } else if (colour_chars.find(theFoundChar)!=string::npos) {
    pr_gain = MutParam->pr_colour_gain_brack;
    pr_lose = MutParam->pr_colour_lose_brack;
    base_val  = 2;
    stdev     = 0;
    min=0; max=COLOUR_MAX;
    
   //******* trope character ******
  } else if (trope_chars.find(theFoundChar)!=string::npos) {
    pr_gain = MutParam->pr_trope_gain_brack;
    pr_lose = MutParam->pr_trope_lose_brack;
    base_val  = UIClassPtr->get_tr();
    stdev     = MutParam->tr_stdev;
    min=0; max=1;

  //******* ~ character ******
  } else if (randrot_chars.find(theFoundChar)!=string::npos) {
    pr_gain = MutParam->pr_randrot_gain_brack;
    pr_lose = MutParam->pr_randrot_lose_brack;
    base_val  = UIClassPtr->rand_amount();
    stdev     = MutParam->randrot_stdev;
    min=0; max=180;
  } else {
    char msg[]="\"*\" character found - don't know how to add or delete a parameter!";
    msg[1]=theFoundChar;
    UIClassPtr->ProgrammingError("LString::mutate_ChangeRuleParameter",msg);
  };

  //replace base by user specified parameter, if present
  theFoundParam=(*theFoundLine)->assoc_param(theFoundPos,theParamLength);
  if (theParamLength>2) 
    base_val = theFoundParam;

  //make a copy of the line
  string tempStr =(*theFoundLine)->text();  
  
  //does it have a parameter
  float r=Rnd();
printf("(r=%f) ",r);
  if        ( ( theParamLength>=3) && (r<pr_lose)) {         //remove
    tempStr.replace(theFoundPos+1,theParamLength,"");
printf("parameter removed\n");
  } else if ( ((theParamLength>=3) && (r>pr_lose)) ||
	      ((theParamLength< 3) && (r<pr_gain)) ) {       //change
      float param;
      int   i=MutParam->MaxMutTries;
printf("Parameter changed by");
      while(i--) {
	param =  N(0,stdev);
printf(" %f: ",param);
	param += base_val;
	if ((param>=min) && (param<=max)) {
	  char pStr[50];
	  if (colour_chars.find(theFoundChar)!=string::npos) 
	    snprintf(pStr, 49, "(%i)",(int) param);
	  else
	    snprintf(pStr, 49, "(%f)",param);
	  tempStr.replace(theFoundPos+1,theParamLength,pStr);
printf("suceeded!");
	  break;
	} else {
printf("failed; ");
	};
      };
  } else {
printf("Nothing done");
  };  

printf("\n");

  if ((*theFoundLine)==line_ptr[AXIOM_LINE])
    ReplaceAxiom(tempStr);
  else
    ReplaceUserRule(tempStr,*theFoundLine);
}
