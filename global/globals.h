///////////////////////////////////////////////////////////////////////////////
//
//      globals.h                                   Author:  Eric McDaniel
//                                                  Email:   chate@cs.wisc.edu
//                                                  Date:    Summer 2001
//
//      Global variables, macros, etc for this application.
//
///////////////////////////////////////////////////////////////////////////////

#ifndef _GLOBALS
#define _GLOBALS


// platform specific
#ifdef _WIN32
    #define MS_WINDOWS

    #ifndef _DEBUG
        #define _RELEASE
    #endif

    #ifdef _VISUAL_STUDIO_7
        #define _VISUAL_STUDIO

        #pragma warning(disable : 4100)        // disable unused parameter warning
        #pragma warning(disable : 4127)        // disable conditional is constant warning

        // macros to disable/enable conversion warnings, must be placed outside methods/classes
        #define MPushWarningState warning(push)
        #define MPopWarningState warning(pop)
        #define MDisableConversionWarnings  warning(disable : 4267; disable : 4244; disable : 4311; disable : 4312; disable : 4511; disable : 4512)
        #define MEnableConversionWarnings  warning(default : 4267; default : 4244; default : 4311; default : 4312; default : 4511; default : 4512)

        // disable those conversion warnings
        #pragma MDisableConversionWarnings
    #else 
        #ifndef _VISUAL_STUDIO_6
            #define _VISUAL_STUDIO_6
        #endif
        #define _VISUAL_STUDIO
        #define for if (false) {} else for     // fix for loop scoping problem in vc++, this has no performance cost for a release build
        #pragma warning(disable : 4786)        // fix the "mangled name exceeds 255 characters" bug in vc
    #endif
#elif defined __GNUC__
   #define _GNU

   #ifdef NDEBUG
      #define _RELEASE
   #else
      #define _DEBUG
   #endif
#else
   #error Unknown compiler and platform.
#endif

// global includes
#include "typedefs.h"           // type definitions
#include "errorHandling.h"      // error handling


// global constants
const float       g_cEpsilon        = 0.00001f;             // small value used to compare floating point values
const float       g_cPi             = 3.14159265358979f;    // the constant pi
const THandle     g_cInvalidHandle  = 0;                    // invalid handle
const double	  g_cInfinite       = 9999999999999.99;		// a extremely big number

#include "globals.inl"      // global functions and templates

#endif // _GLOBALS

