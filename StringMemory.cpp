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
//******************************************************************
// Why not use string directly
// ReAllocate memory for the final string
//******************************************************************
bool LString::FS_alloc(size_t mem)
{
  void *new_mem = realloc(FinaLString,mem);

  if (new_mem) {
    FinaLString = (unsigned char *) new_mem;
    FS_MemSize = mem;
    return true;
  } 
	else {
    Warning("Out of memory");
    return false;
  }// end of else
}

//quick work around

//******************************************************************
// Find out the maximum number of the two size 
//******************************************************************
inline size_t Max(size_t i1, size_t i2)
{
  if (i1 > i2)
		return i1;
  else
		return i2;
}

/////////////////////////////////////////////////////////////////////
//
// Methods to get information
//
/////////////////////////////////////////////////////////////////////
//******************************************************************
// Reads an (xx) value from a production string at the curr_pos,
// and make it into a real. Then advance curr_pos to the next position.
// Returns true if there is such a bracketed value.
//******************************************************************
bool  LString::Get_value(unsigned long &curr_pos, r32 &val)
{                 

  int characters_read = 0;
  if (curr_pos >= FS_Lgth) 
    return false;
  if (FinaLString[curr_pos] == '(')
    sscanf((char *) &(FinaLString[curr_pos]), "(%f)%n", &val, &characters_read);
  
  curr_pos += characters_read;
  if (characters_read>2)
    return true;
  else
    return false;
}

//******************************************************************
// If the character at position s_pos in the FinaLString is a
// CountChar, return the CountChar number and advance s_pos by one.
//******************************************************************
int LString::Get_RecursionChar(unsigned long &s_pos)
{ 
  if (s_pos<=FS_Lgth) {
    int i=0;
    unsigned char theChar = FinaLString[s_pos];
    while (CountChar[i]!='\0')
      if (CountChar[i++]==theChar) break;
    if (i!='\0') {
      s_pos++;
      return i;
    }
  }
  return 0;
};

//******************************************************************
// Return the FinaLString, minus any CountChars
//******************************************************************
string LString::FormattedFinaLString()
{
  string fs=(char *) FinaLString;
  string ss=(char *) CountChar;
  size_t pos=0;
  while (pos!=string::npos) {
    pos=fs.find_first_of(ss,pos);
    if (pos!=string::npos)
      fs.replace(pos,1,"");
  }
  return fs;
}

//******************************************************************
// Check whether the final string exist or not
//******************************************************************
bool LString::FinaLStringExists()
{
  if (FinaLString == NULL)
    return false;
  else
    return true;
}

//******************************************************************
// The length of the final string
//******************************************************************
int  LString::FinaLStringLength()
{
  return FS_Lgth;
}

//******************************************************************
// Check the ith string number
//******************************************************************
unsigned char LString::FinaLStringChr(unsigned int i)
{
  return FinaLString[i];
}

//******************************************************************
// Chech the final string level
//******************************************************************
int  LString::FinaLStringRecLev()
{
  return FS_Lev;
}
