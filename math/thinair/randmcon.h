/* =========================================================================
 *                                 RANDMCON.H
 * -------------------------------------------------------------------------
 *  Interface file for any multiplicative congruential pseudo-random number 
 *  generator with a modulus of 2^32 as an object.
 *
 *  Version 0.9
 *
 *  Copyright 1995-1997 by G. Wade Johnson
 *   Use of this code is placed in the public domain as long as the
 *   copyright notice is retained.
 */

#if !defined( RANDMCON_H )
  #define RANDMCON_H

  #if !defined( RANDGEN_H )
    #include "randgen.h"
  #endif
  #if !defined( RANDCONG_H )
    #include "randcong.h"
  #endif


  class  MultConRandGen : public CongruentialRandGen
   {
  private:
    const unsigned long   myMultiplier;

  private:
    // protect the = operator and copy constructor so they cannot be used.
    MultConRandGen& operator=( MultConRandGen const & );
    MultConRandGen( MultConRandGen const & );

  protected:
    unsigned long   Multiplier( void ) const  { return myMultiplier; }

  public:
    EXPLICIT MultConRandGen( unsigned long mult, size_rand seed=1 ) :
      CongruentialRandGen(seed), myMultiplier(mult)
     { }
    virtual   ~MultConRandGen() { }
 
    virtual DIFFRET(RandomGenerator,MultConRandGen)  *ReCreate( void ) const;

    virtual  size_rand   Number( void );
   } ;

#endif
