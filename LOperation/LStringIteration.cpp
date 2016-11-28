/*******************************************************************************
		Main Program:	Viewer.cpp

		Comment:			I do not like his method if have time rewrite it

		Author:				Yu-Chi Lai, yu-chil@cae.wisc.edu

		Due Date:			

		Course:				CS777, Spring 2003
*******************************************************************************/
#include "LString.h"
////////////////////////////////////////////////////////////////////
//
//	Recursively Create the final string
//
////////////////////////////////////////////////////////////////////
bool LString::Parse()
{
	return Parse(-1);
}
//******************************************************************
// Expand l-system into production string
//******************************************************************
bool LString::Parse(const signed short int reclevel)
{
	size_t          k,remaining,s;
  void            *new_mem;
  signed short int  l, lev = get_lev();
  LlineClass      *i;
  bool            marker = false, fractional_recursion;

  if (valid_string==false) {
    return false;
  }
  
  //store the actual number of recursions done in FS_Lev
  if ((reclevel<0) || (reclevel==lev)) {  // use the Lstring rec level
    fractional_recursion=growing();
    FS_Lev = lev;
  }
	else if (lev>reclevel) {              // use a lower rec level
    fractional_recursion=false;
    FS_Lev = reclevel;
  }
	else {   // a rec level higher than that defined has been requested
    return false;
  }
  //allocate FinalString and so forth (assumes 'char' is 1 byte)
  FS_Lgth=0;

  //initially allocate FS_Chunk of memory if we have none
  if (FinalString==NULL)
    if (FS_alloc(FS_Chunk)==false)
      return false;

	//see if we need more memory for the axiom
  k = line_ptr[AXIOM_LINE]->info_length();
	int needSize;
	if(k + 1 > FS_MemSize)
		needSize = k + 1;
	else
		needSize = FS_MemSize;

  if (FS_alloc(needSize)==false)
    return false;

  strncpy((char *) FinalString, 
	  line_ptr[AXIOM_LINE]->text().c_str(),  k);
  FinalString[k]='\0'; //make sure string is terminated

  //*******************************
  //******* Start parsing *********
  //*******************************
  remaining=k; //count of characters remaining to parse
  for (l = 0; l < FS_Lev; l++) {
    k=0;
    marker = ((l == (FS_Lev - 1)) && fractional_recursion); 
        
    //start a single pass of the parser: k is the current parse position
    while (FinalString[k]!='\0') {
      i  = RuleForChar[FinalString[k]]; // i points to a replacement rule
      s  = i->info_length();            // s is total length of rule

      //longer string needed
      if ((k+s+remaining+2) > FS_MemSize) {
				if (FS_alloc(FS_MemSize+FS_Chunk)==false) {
					free(FinalString);
					FS_MemSize=0;
					FS_Lgth=0;
					return false;
				}
      }
      //replace character with rule, surrounded by the @ character
      //if this is the last round of recursion, and a fractional
      //recursion level has been requested.
      if (marker && (i->get_marker()==USER_RULE)) {
				memmove(&FinalString[k+s],&FinalString[k+1],remaining);
				FinalString[k]='@';
				memcpy(&FinalString[k+1],i->rule_start(),s-2);
				FinalString[k+s-1]='@';
				k+=s;
      } 
			else {
				memmove(&FinalString[k+s-2],&FinalString[k+1],remaining);
				memcpy(&FinalString[k],i->rule_start(),s-2);
				k+=s-2;
      }

      remaining --;                     // one character down      
    } //end of a single parse
    remaining=k; //reset the count of remaining characters
  } //end of series of parses

  FS_Lgth=k;
  return true;
}

//******************************************************************
// Check whether there is a "." in the recursion line
//******************************************************************
bool LString::growing()
{
  //if there is a decimal place in the recursion line...
  if (line_ptr[REC_LINE]->text().find('.') == std::string::npos)
    return false;
  else
    return true;
}

bool LString::FS_alloc(size_t mem)
{
  void *new_mem=realloc(FinalString,mem);
  if (new_mem) {
    FinalString=(unsigned char *) new_mem;
    FS_MemSize=mem;
    return true;
  } else {
    Warning("Memory is not enough");
    return false;
  }
}
