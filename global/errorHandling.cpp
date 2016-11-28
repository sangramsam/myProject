#include "globals.h"
#include "errorHandling.h"
#include <string>
#include <iostream>

// include the signal system on linux
#ifdef _GNU
   #include <unistd.h>
   #include <signal.h>
#endif

using std::cerr;
using std::endl;

namespace NErrorHandling
{
    ///////////////////////////////////////////////////////////////////////////////
    //
    //      Causes error message to be displayed if conditional fails in debug 
    //   mode.  Program is then halted and user is given a chance to start the 
    //   debugger.
    //
    ///////////////////////////////////////////////////////////////////////////////
    void AssertFunction(bool bConditional, const char* sMessage, const char* sMethod, const char* sFile, int line)
    {
        if (!bConditional)
        {
            cerr  << endl
                  << "** Assertion failed ***********************************************************" << endl
                  << sMessage << endl 
                  << "Method:  " << sMethod << endl
                  << "File:  " << sFile << endl
                  << "Line:  " << line << endl
                  << "*******************************************************************************" << endl
                  << endl;

            // give the user a chance to use the debugger
            #ifdef MS_WINDOWS
               _asm{int 0x03}
            #else
               kill(getpid(), SIGABRT);
            #endif
        }// if
    }// AssertFunction


    ///////////////////////////////////////////////////////////////////////////////
    //
    //      Causes error message to be displayed if conditional fails.  Program is
    //   then halted and user is given a chance to start the debugger.
    //
    ///////////////////////////////////////////////////////////////////////////////
    void VerifyFunction(bool bConditional, const char* sMessage, const char* sMethod, const char* sFile, int line)
    {
        if (!bConditional)
        {
            cerr  << endl
                  << "** Verification failed ********************************************************" << endl
                  << sMessage << endl 
                  << "Method:  " << sMethod << endl
                  << "File:  " << sFile << endl
                  << "Line:  " << line << endl
                  << "*******************************************************************************" << endl
                  << endl;

            // give the user a chance to use the debugger
            #ifdef MS_WINDOWS
               _asm{int 0x03}
            #else
               kill(getpid(), SIGABRT);
            #endif
        }// if
    }// VerifyFunction


    ///////////////////////////////////////////////////////////////////////////////
    //
    //      Causes error message to be displayed.  If _HALT_ON_WARNING is defined, 
    //   program is halted and user is given a chance to start the debugger.
    //
    ///////////////////////////////////////////////////////////////////////////////
    void WarningFunction(const std::string& sMessage, const char* sMethod, const char* sFile, int line)
    {
        cerr   << endl
               << "** Warning ********************************************************************" << endl
               << sMessage << endl 
               << "Method:  " << sMethod << endl
               << "File:  " << sFile << endl
               << "Line:  " << line << endl
               << "*******************************************************************************" << endl
               << endl;

        // if we're halting on warnings do so, otherwise just return
        #ifdef _HALT_ON_WARNING
            // give the user a chance to use the debugger
            #ifdef MS_WINDOWS
               _asm{int 0x03}
            #else
               kill(getpid(), SIGABRT);
            #endif
        #endif
    }// WarningFunction


    ///////////////////////////////////////////////////////////////////////////////
    //
    //      Causes error message to be displayed.  Program is then halted and user
    //   is given a chance to start the debugger.
    //
    ///////////////////////////////////////////////////////////////////////////////
    void ErrorFunction(const std::string& sMessage, const char* sMethod, const char* sFile, int line)
    {
         cerr  << endl
               << "** Error **********************************************************************" << endl
               << sMessage << endl 
               << "Method:  " << sMethod << endl
               << "File:  " << sFile << endl
               << "Line:  " << line << endl 
               << "*******************************************************************************" << endl
               << endl;

         // give the user a chance to use the debugger
         #ifdef MS_WINDOWS
            _asm{int 0x03}
         #else
            kill(getpid(), SIGABRT);
         #endif
    }// ErrorFunction
}// NErrorHandling

