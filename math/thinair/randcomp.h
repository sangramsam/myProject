/* =========================================================================
 *                                 RANDCOMP.H
 * -------------------------------------------------------------------------
 *  Interface file for a random number generator class based on the
 *  rand() function in the current library.
 *
 *  Version 0.9
 *
 *  Copyright 1995-1997 by G. Wade Johnson
 *   Use of this code is placed in the public domain as long as the
 *   copyright notice is retained.
 */

#if !defined( RANDCOMP_H )
  #define RANDCOMP_H

  #if !defined( RANDGEN_H )
    #include "randgen.h"
  #endif

  class  CompilerRandGen : public RandomGenerator
   {
  private:
    size_rand      mySeed;
    unsigned long  myCount;

  private:
    // protect the = operator and copy constructor so they cannot be used.
    CompilerRandGen& operator=( CompilerRandGen const & );
    CompilerRandGen( CompilerRandGen const & );

  protected:
    size_rand      Seed( void )     const { return mySeed; }
    void           SetSeed( size_rand seed ) { mySeed = seed; myCount = 0L; }
    unsigned long  Count( void )    const { return myCount; }
    void           RunTo( unsigned long cnt );

  public:
    EXPLICIT CompilerRandGen( size_rand seed=1 ) : mySeed(seed), myCount(0L)
     { srand((unsigned)seed); }
    virtual   ~CompilerRandGen() { }
 
    virtual DIFFRET(RandomGenerator,CompilerRandGen)  *ReCreate( void ) const;

    virtual RandGenToken  CreateToken( void ) const;
    virtual int     SetToken( const RandGenToken &Token );

    virtual void    Reset( void );

    virtual  void        IntSeed( size_rand seed );
    virtual  size_rand   MaxRandom( void ) const;
    virtual  size_rand   Number( void );
   } ;

#endif
