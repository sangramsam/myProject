/* =========================================================================
 *                                 RNDMCONM.CPP
 * -------------------------------------------------------------------------
 *  Implementation file for any multiplicative congruential pseudo-random 
 *  number generator as an object.
 *
 *  This generator uses the algorithm described in Jerry Dwyer's article in
 *  CUJ June 1995 entitled  "Quick and Portable Random Number Generators".
 *
 *  WARNING: only valid for  Modulus > Multiplier * Multiplier.
 *
 *  Version 0.9
 *
 *  Copyright 1995-1997 by G. Wade Johnson
 *   Use of this code is placed in the public domain as long as the
 *   copyright notice is retained.
 */

#include <math.h>

#include "environ.h"
#include "rndmconm.h"
#include "modarith.h"



DIFFRET(RandomGenerator,MultConModRandGen)
                                    *MultConModRandGen::ReCreate( void ) const
 {
  return new MultConModRandGen( Multiplier(), Modulus(), Seed() );
 }




size_rand    MultConModRandGen::Number( void )
 {
  SetCurrSeed( mod_mult( Multiplier(), CurrSeed(), Modulus() ) );

  return CurrSeed();
 }
