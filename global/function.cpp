#include "Defines.h"
#include "function.h"
//*****************************************************************************
// Removes a line from "text", and returns the removed line
// as a string, minus leading whitespace.
//*****************************************************************************
std::string snip_line(std::string &text)
{
	// The end of the string
  size_t marked_pos;
	// The temporary storing string
	std::string ss;

	// The text contain nothing
  if (text.length()==0)
    return "";

  // Find the end position of the line
  marked_pos=text.find_first_of(endline_markers);
	// text contain only one line
  if (marked_pos == std::string::npos) {
    ss = text;
    text = "";
  }
	// Copy this text and move the cursor of text to proper place
	else {                       //end of line marker found
		// Extract the text out
    ss         = text.substr(0, marked_pos);
		// Find the next element after the end of line
    marked_pos = text.find_first_not_of(endline_markers, marked_pos);
		// Erase the ss out from text
    text.erase(0, marked_pos);
  };
  
  //strip leading whitespace
  marked_pos =  ss.find_first_not_of(whitespace);
  ss.erase(0, marked_pos);
  
  return ss;
}


