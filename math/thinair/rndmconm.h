/* =========================================================================
 *                                 RNDMCONM.H
 * -------------------------------------------------------------------------
 *  Interface file for any multiplicative congruential pseudo-random number 
 *  generator as an object.
 *
 *  Version 0.9
 *
 *  Copyright 1995-1997 by G. Wade Johnson
 *   Use of this code is placed in the public domain as long as the
 *   copyright notice is retained.
 */

#if !defined( RNDMCONM_H )
  #define RNDMCONM_H

  #if !defined( RANDGEN_H )
    #include "randgen.h"
  #endif
  #if !defined( RANDMCON_H )
    #include "randmcon.h"
  #endif


  class  MultConModRandGen : public MultConRandGen
   {
  private:
    const unsigned long   myModulus;

  private:
    // protect the = operator and copy constructor so they cannot be used.
    MultConModRandGen& operator=( MultConModRandGen const & );
    MultConModRandGen( MultConModRandGen const & );

  protected:
    unsigned long   Modulus( void ) const  { return myModulus; }

  public:
    MultConModRandGen( unsigned long mult, unsigned long mod,
                                                         size_rand seed=1 ) :
      MultConRandGen( mult, seed ), myModulus(mod)
     {
      SetSeed( seed % (MultConModRandGen::MaxRandom() + 1) );
      MultConModRandGen::Reset();
     }
    virtual   ~MultConModRandGen() { }
 
    virtual DIFFRET(RandomGenerator,MultConModRandGen)  *ReCreate( void ) const;

    virtual  void        Reset( void ) { SetCurrSeed( Seed() ); }

    virtual  size_rand   Number( void );
    virtual  size_rand   MaxRandom( void ) const { return Modulus()-1; }
   } ;


#endif
