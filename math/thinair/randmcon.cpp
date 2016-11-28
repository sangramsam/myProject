/* =========================================================================
 *                                 RANDMCON.CPP
 * -------------------------------------------------------------------------
 *  Implementation file for any multiplicative congruential pseudo-random 
 *  number generator with a modulus of 2^32 as an object.
 *
 *  Version 0.9
 *
 *  Copyright 1995-1997 by G. Wade Johnson
 *   Use of this code is placed in the public domain as long as the
 *   copyright notice is retained.
 */

#include "environ.h"
#include "randmcon.h"




DIFFRET(RandomGenerator,MultConRandGen) *MultConRandGen::ReCreate( void ) const
 {
  return new MultConRandGen( Multiplier(), Seed() );
 }



size_rand    MultConRandGen::Number( void )
 {
  SetCurrSeed( myMultiplier * CurrSeed() );
  return CurrSeed();
 }
