///////////////////////////////////////////////////////////////////////////////
//
//  typedefs.h                                  Author:     Eric McDaniel
//                                              Email:      chate@cs.wisc.edu
//                                              Written:    Summer 2001
//                                              Modified:   Summer 2002
//
//      Type definitions for this project.
//
///////////////////////////////////////////////////////////////////////////////

#ifndef _TYPEDEFS
#define _TYPEDEFS

#ifdef _VISUAL_STUDIO
    typedef     unsigned char       byte;
    typedef     unsigned int        uint;
    typedef     char                int8;
    typedef     unsigned char       uint8;
    typedef     short               int16;
    typedef     unsigned short      uint16;
    typedef     int                 int32;
    typedef     unsigned int        uint32;
    typedef     __int64             int64;
    typedef     unsigned __int64    uint64;
    typedef     float               float32;
    typedef     double              float64;
#elif defined(_GNU)
    typedef     unsigned char       byte;
    typedef     unsigned int        uint;
    typedef     char                int8;
    typedef     unsigned char       uint8;
    typedef     short               int16;
    typedef     unsigned short      uint16;
    typedef     int                 int32;
    typedef     unsigned int        uint32;
    typedef     long long           int64;
    typedef     unsigned long long  uint64;
    typedef     float               float32;
    typedef     double              float64;
#else
    #error Type definitions are not defined for this platform.
#endif 

// THandle
typedef uint            THandle;

// TPosition
class CVector3;
typedef CVector3        TPosition;

// TOrientation
class CQuaternion;
typedef CQuaternion     TOrientation;

// TLogProb
typedef double          TLogProb;

#endif // _TYPEDEFS

