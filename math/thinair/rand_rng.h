/* ========================================================================
 *                                RAND_RNG.H
 * ------------------------------------------------------------------------
 *  Mimic the C Standard Library interface with the Random Number classes.
 *
 *  Version 0.9
 *
 *  Copyright 1995-1997 by G. Wade Johnson
 *   Use of this code is placed in the public domain as long as the
 *   copyright notice is retained.
 */

#if !defined( RAND_RNG_H )
  #define RAND_RNG_H

  #if !defined( RANDGEN_H )
    #include "randgen.h"
  #endif

  size_rand   myMaxRand( void );
  size_rand   myRand( void );
  size_rand   myRandom( unsigned lim );
  void        mySRand( size_rand seed );


  #if !defined( IMPLEMENT_RAND_RNG )
     #define  RAND_MAX     myMaxRand()
     #define  rand()       myRand()
     #define  random(lim)  myRandom(lim)
     #define  srand(seed)  mySRand(seed)
     #define  randomize()  srand((unsigned)time(NULL))
  #endif

  extern void  setup_rand( RandomGenerator *pRNG=0 );

#endif
