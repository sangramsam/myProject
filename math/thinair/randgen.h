/* =========================================================================
 *                                RANDGEN.H
 * -------------------------------------------------------------------------
 *  Interface file for a pseudo-random number generator object.
 *
 *  Version 0.9
 *
 *  Copyright 1995-1997 by G. Wade Johnson
 *   Use of this code is placed in the public domain as long as the
 *   copyright notice is retained.
 */

#if !defined( RANDGEN_H )
  #define RANDGEN_H

  #if !defined( ENVIRON_H )
    #include "environ.h"
  #endif

  #include _IOSTREAM_HEADER
  #include _STRING_HEADER

using namespace std;
  typedef  unsigned long   size_rand;


  class  RandGenTokenImpl
   {
  private:
    // protect the = operator and copy constructor so they cannot be used.
    RandGenTokenImpl &operator=( const RandGenTokenImpl & /* rhs */ );
    RandGenTokenImpl( RandGenTokenImpl const & );

  protected:
    friend class RandomGenerator;
    RandGenTokenImpl( void ) { }

  public:
    virtual   ~RandGenTokenImpl( void ) { }
    virtual RandGenTokenImpl   *Clone() const = 0;

    virtual _STRING CreateInitString( void ) const = 0;
    virtual int     Initialize( istream &InitStream ) = 0;

    virtual void  Print( ostream &os ) const = 0;
    virtual void  Read( istream &is ) = 0;
   } ;

  class  RandGenToken
   {
    RandGenTokenImpl   *myImpl;
    friend class RandomGenerator;

  public:
    RandGenToken( void ) : myImpl(0) { }
    RandGenToken( RandGenTokenImpl *pImpl ) : myImpl(pImpl) { }
    RandGenToken( RandGenToken const &rhs ) : myImpl(0) { *this = rhs; }

    ~RandGenToken( void )
     {
      delete myImpl; myImpl = 0;
     }

    const RandGenTokenImpl  *Implementation() const { return myImpl; }

    RandGenToken &operator=( const RandGenToken &rhs )
     {
      if(&rhs != this)
       {
        delete myImpl;
        myImpl = rhs.myImpl->Clone();
       }

      return *this;
     }

    _STRING CreateInitString( void ) const
     {
      return myImpl->CreateInitString();
     }
    int     Initialize( const _STRING &InitString );
    int     Initialize( istream &InitStream )
     {
      return myImpl->Initialize( InitStream );
     }

    void  Print( ostream &os ) const
     {
      myImpl->Print( os );
     }
    void  Read( istream &is )
     {
      myImpl->Read( is );
     }
   } ;

  istream &operator>>( istream &is, RandGenToken &Token );
  ostream &operator<<( ostream &os, RandGenToken const &Token );

  class  RandomGenerator
   {
  private:
    // protect the = operator and copy constructor so they cannot be used.
    RandomGenerator& operator=( RandomGenerator const & );
    RandomGenerator( RandomGenerator const & );

  public:
    RandomGenerator( void ) { }
    virtual   ~RandomGenerator() { }

    virtual BOOL         bad( void ) const { return false; }

    virtual RandomGenerator  *ReCreate( void ) const = 0;
    virtual RandomGenerator  *Clone( void ) const;

    virtual RandGenToken   CreateToken( void ) const = 0;
    virtual int     SetToken( const RandGenToken &Token ) = 0;

    virtual void    Reset( void ) { }

    virtual  void        IntSeed( size_rand seed ) = 0;
    virtual  size_rand   MaxRandom( void ) const { return 0xffffffffUL; }
    virtual  size_rand   Number( void ) = 0;
    virtual  double      FloatNumber( void )
     {
      return ((double)Number()/((double)MaxRandom()+1));
     }
    virtual  size_rand   LimitedNumber( size_rand limit )
     {
      return (size_rand)(((double)Number()*limit)/((double)MaxRandom()+1.0));
     }
   } ;

#endif
