///////////////////////////////////////////////////////////////////////////////
//
//      errorHandling.h                         Author:     Eric McDaniel
//                                              Email:      chate@cs.wisc.edu
//                                              Written:    Summer 2002
//                                              Modified:   Summer 2002
//
//      Error handling methods.
//
///////////////////////////////////////////////////////////////////////////////

#ifndef _ERROR_HANDLING
#define _ERROR_HANDLING

// define this constant if you want the program to halt and allow you to start the debugger in response to a warning
//#define _HALT_ON_WARNING

#include <string>

// function declarations
namespace NErrorHandling
{
    ///////////////////////////////////////////////////////////////////////////////
    //
    //      Causes error message to be displayed if conditional fails in debug 
    //   mode.  Program is then halted and user is given a chance to start the 
    //   debugger.
    //
    ///////////////////////////////////////////////////////////////////////////////
    void AssertFunction(bool bConditional, const char* sMessage, const char* sMethod, const char* sFile, int line);

    ///////////////////////////////////////////////////////////////////////////////
    //
    //      Causes error message to be displayed if conditional fails.  Program is
    //   then halted and user is given a chance to start the debugger.
    //
    ///////////////////////////////////////////////////////////////////////////////
    void VerifyFunction(bool bConditional, const char* sMessage, const char* sMethod, const char* sFile, int line);

    ///////////////////////////////////////////////////////////////////////////////
    //
    //      Causes error message to be displayed.  If _HALT_ON_WARNING is defined, 
    //   program is halted and user is given a chance to start the debugger.
    //
    ///////////////////////////////////////////////////////////////////////////////
    void WarningFunction(const std::string& sMessage, const char* sMethod, const char* sFile, int line);

    ///////////////////////////////////////////////////////////////////////////////
    //
    //      Causes error message to be displayed.  Program is then halted and user
    //   is given a chance to start the debugger.
    //
    ///////////////////////////////////////////////////////////////////////////////
    void ErrorFunction(const std::string& sMessage, const char* sMethod, const char* sFile, int line);
}// NErrorHandling


// assert macro definitions
#ifdef _VISUAL_STUDIO_6
    #define __FUNCTION__ "Not Available"
#endif

#ifdef _DEBUG
   #define _USE_ASSERT
#endif

#ifdef _USE_ASSERT
    #define Assert(bConditional, sMessage)      NErrorHandling::AssertFunction(bConditional, sMessage, __FUNCTION__, __FILE__, __LINE__)
#else
    #define Assert(bConditional, sMessage)
#endif


#define     Verify(bConditional, sMessage)      NErrorHandling::VerifyFunction(bConditional, sMessage, __FUNCTION__, __FILE__, __LINE__)
#define     Warning(sMessage)                   NErrorHandling::WarningFunction(sMessage, __FUNCTION__, __FILE__, __LINE__)
#define     Error(sMessage)                     NErrorHandling::ErrorFunction(sMessage, __FUNCTION__, __FILE__, __LINE__)


// ToDo macro definitions
#ifdef _VISUAL_STUDIO
    // display todos in vc++ build window, gcc will just ignore them, unless you do a post build process to find them that is
   #define _TODO_QUOTE_QUOTE(x) # x
   #define _TODO_QUOTE(x) _TODO_QUOTE_QUOTE(x)
   #define ToDo(x) message(__FILE__"(" _TODO_QUOTE(__LINE__) "): ToDo: " #x"\n") 
#endif

#endif // _ERROR_HANDLING
