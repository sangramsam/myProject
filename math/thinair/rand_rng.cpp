/* ========================================================================
 *                               RAND_RNG.CPP
 * ------------------------------------------------------------------------
 *  Implementation for the C Standard library interface for the Random
 *  Number Classes.
 *
 *  Version 0.9
 *
 *  Copyright 1995-1997 by G. Wade Johnson
 *   Use of this code is placed in the public domain as long as the
 *   copyright notice is retained.
 */

#include <string.h>
#include <stdlib.h>   // for the std rand()

#include "environ.h"

#define  IMPLEMENT_RAND_RNG
#include "rand_rng.h"
#include "randcomp.h"


static  RandomGenerator  *pInternal = new CompilerRandGen();



void  setup_rand( RandomGenerator *pRNG )
 {
  delete pInternal;

  if(pRNG)
   {
    pInternal = pRNG;
   }
  else
   {
    pInternal = new CompilerRandGen();
   }
 }




size_rand    myMaxRand( void )
 {
  return pInternal->MaxRandom();
 }





size_rand   myRand( void )
 {
  return pInternal->Number();
 }




size_rand   myRandom( unsigned lim )
 {
  return pInternal->LimitedNumber( (size_rand)lim );
 }




void        mySRand( size_rand seed )
 {
  pInternal->IntSeed( seed );
 }
