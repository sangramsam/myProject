/* ========================================================================
 *                                ERNDMCNM.H
 * ------------------------------------------------------------------------
 *  Instantiations of the MultConModRandGen class.
 *
 *  Version 0.9
 *
 *  Copyright 1995-1997 by G. Wade Johnson
 *   Use of this code is placed in the public domain as long as the
 *   copyright notice is retained.
 */


#if !defined( ERNDMCNM_H )
  #define ERNDMCNM_H

  #if !defined( RNDMCONM_H )
    #include "rndmconm.h"
  #endif

/* -------------------------------------------------------------------------
 * The following PRNGs are taken from Knuth Vol 2. in the Spectral test
 *  table, Section 3.3.4
 */

 class Knuth22RandGen : public MultConModRandGen
  {
 public:
   EXPLICIT Knuth22RandGen( size_rand seed=1 ) :
    MultConModRandGen( 0x10003UL, 0x20000000UL, seed )
    { }
  } ;


 class Knuth27RandGen : public MultConModRandGen
  {
 public:
   EXPLICIT Knuth27RandGen( size_rand seed=1 ) :
    MultConModRandGen( 314159269UL-0x7FFFFFFFUL, 0x7FFFFFFFUL, seed )
    { }
  } ;


 class RANDURandGen : public MultConModRandGen
  {
 public:
   EXPLICIT RANDURandGen( size_rand seed=1 ) :
    MultConModRandGen( 65539UL, 0x80000000UL, seed )
    { }
  } ;

#endif
