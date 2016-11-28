/* ========================================================================
 *                                ENVIRON.H
 * ------------------------------------------------------------------------
 *  Hold environment-specific macros needed for portability
 *
 *  Version 0.9
 *
 *  Copyright 1995-1997 by G. Wade Johnson
 *   Use of this code is placed in the public domain as long as the
 *   copyright notice is retained.
 */

#if !defined( ENVIRON_H )
  #define  ENVIRON_H

  //   Define capabilities by compiler and environment.

  #if __BCPLUSPLUS__ >= 0x0340
     #define  _DYNAMIC_CAST
     #define  _STRING_CLASS
     #define  _DIFFERING_RETURNS_ALLOWED
     #define  _STRING_HEADER  <cstring.h>
     #define  _STRING          string
     #define  _HAS_BINARY
  #endif


  #if _MSC_VER >= 1020
//     #define  _DYNAMIC_CAST  // fails cast of const base to const derived ptrs
     #define  _STRING_CLASS
     #define  _STRING          string
     #define  _HAS_BOOL
     #define  _HAS_BINARY
     #define  _ANSI_CPP_HEADERS
     #include <minmax.h>
  #endif

  #if __GNUC__ >= 2 && __GNUC_MINOR__ >= 6 && defined( __cplusplus )
     #define  _HAS_BOOL
     #define  _STRING_CLASS
     #if __GNUC__ >= 2 && __GNUC_MINOR__ < 7
       #define  _STRING_HEADER   <g++/String.h>
       #define  _STRING          String
     #else
       #define  _STRING_HEADER   <string>
       #define  _STRING          string
       #define  _DIFFERING_RETURNS_ALLOWED
       #include <stl.h>
     #endif
     #define  _HAS_INT64

     typedef  long long        Int64;
  #endif

  #if defined( _ANSI_CPP_HEADERS )
     #define _STRING_HEADER    <string>
     #define _IOSTREAM_HEADER  <iostream>
     #define _IOMANIP_HEADER   <iomanip>
     #define _FSTREAM_HEADER   <fstream>
     #define _STRSTREAM_HEADER <strstream>
     #define _VECTOR_HEADER    <vector>
     #define _ALGO_HEADER      <algo>
  #else
     #define _IOMANIP_HEADER   <iomanip.h>
     #define _IOSTREAM_HEADER  <iostream.h>
     #define _FSTREAM_HEADER   <fstream.h>
     #define _STRSTREAM_HEADER <strstream.h>
     #define _VECTOR_HEADER    <vector.h>
     #define _ALGO_HEADER      <algo.h>
  #endif


  // Encapsulate environment differences in macros.

  #if defined( _DYNAMIC_CAST )
    #define  DYNACAST( type )  dynamic_cast<type>
    #define  CONSTCAST( type ) const_cast<type>
  #else
    #define  DYNACAST( type )  (type)
    #define  CONSTCAST( type ) (type)
  #endif

  #if defined( _STRING_CLASS )
    #define  STRING( cstr )      _STRING( cstr )
  #else
    #define  STRING( cstr )      (cstr)
  #endif

  #if defined( _HAS_BOOL )
    #define  BOOL   bool
  #else
    #if !defined( BOOL )
      #define  BOOL   int
    #endif

    const  int      false = 0;
    const  int      true = !false;
  #endif

  #if defined( _DIFFERING_RETURNS_ALLOWED )   // Two arg version of this.
    #define  DIFFRET(base,deriv)  deriv
  #else
    #define  DIFFRET(base,deriv)  base
  #endif

  #if defined( _HAS_EXPLICIT )
     #define EXPLICIT    explicit
  #else
     #define EXPLICIT
  #endif

#endif
