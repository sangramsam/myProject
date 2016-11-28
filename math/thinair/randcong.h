/* =========================================================================
 *                                 RANDCONG.H
 * -------------------------------------------------------------------------
 *  Interface file for the abstract congruential pseudo-random number
 *  generator with a modulus of 2^32 as an object.
 *
 *  Version 0.9
 *
 *  Copyright 1995-1997 by G. Wade Johnson
 *   Use of this code is placed in the public domain as long as the
 *   copyright notice is retained.
 */

#if !defined( RANDCONG_H )
  #define RANDCONG_H

  #if !defined( RANDGEN_H )
    #include "randgen.h"
  #endif


  class  CongruentialRandGen : public RandomGenerator
   {
  private:
    // protect the = operator and copy constructor so they cannot be used.
    CongruentialRandGen &operator=( const CongruentialRandGen & /* rhs */ );
    CongruentialRandGen( CongruentialRandGen const & );

    size_rand         mySeed;
    size_rand         myCurrSeed;

  protected:
    size_rand         Seed( void )     const { return mySeed; }
    size_rand         CurrSeed( void ) const { return myCurrSeed; }

    void         SetSeed( size_rand seed ) { mySeed = seed; }
    void         SetCurrSeed( size_rand seed ) { myCurrSeed = seed; }

  public:
    EXPLICIT CongruentialRandGen( size_rand seed )
     {
      SetSeed( seed );
      CongruentialRandGen::Reset();
     }
    virtual   ~CongruentialRandGen() { }

    virtual RandGenToken  CreateToken( void ) const;
    virtual int     SetToken( const RandGenToken &Token );

    virtual  void        IntSeed( size_rand seed );
    virtual  void        Reset( void ) { SetCurrSeed( Seed() ); }
   } ;



#endif
