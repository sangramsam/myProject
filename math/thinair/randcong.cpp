/* =========================================================================
 *                                 RANDCONG.CPP
 * -------------------------------------------------------------------------
 *  Implementation file for an abstract congruential pseudo-random number
 *  generator with a modulus of 2^32 as an object.
 *
 *  Version 0.9
 *
 *  Copyright 1995-1997 by G. Wade Johnson
 *   Use of this code is placed in the public domain as long as the
 *   copyright notice is retained.
 */

#include "environ.h"
#include _STRING_HEADER
#include _STRSTREAM_HEADER

#include "randcong.h"


class  CongRandGenToken : public RandGenTokenImpl
 {
  private:
    // protect the = operator and copy constructor so they cannot be used.
    CongRandGenToken &operator=( const CongRandGenToken & /* rhs */ );
    CongRandGenToken( const CongRandGenToken & );

public:
  virtual   ~CongRandGenToken( void ) { }

  virtual _STRING  CreateInitString( void ) const;
  virtual int   Initialize( istream &InitStream );
  virtual DIFFRET(RandGenTokenImpl,CongRandGenToken)   *Clone() const
   {
    return new CongRandGenToken( myBaseSeed, myCurrSeed );
   }

  void       Print( ostream &os ) const
   {
    os << '(' << myBaseSeed << ',' << myCurrSeed << ')' << flush;
   }
  void       Read( istream &is )
   {
    char  dummy;
    is >> dummy >> myBaseSeed >> dummy >> myCurrSeed >> dummy;
   } 

private:
  friend class CongruentialRandGen;
  CongRandGenToken( size_rand baseSeed, size_rand currSeed ) :
    myBaseSeed( baseSeed ), myCurrSeed( currSeed )
   { }
  size_rand   myBaseSeed;
  size_rand   myCurrSeed;
 } ;





_STRING   CongRandGenToken::CreateInitString( void ) const
 {
  ostrstream  String;

  String << myBaseSeed << ends;

  return _STRING( String.str() );
 }




int   CongRandGenToken::Initialize( istream &InitStream )
 {
  InitStream >> ws >> myBaseSeed;
  myCurrSeed = myBaseSeed;

  return 1;
 }



RandGenToken    CongruentialRandGen::CreateToken( void ) const
 {
  return  RandGenToken( new CongRandGenToken( mySeed, myCurrSeed ) );
 }



int   CongruentialRandGen::SetToken( const RandGenToken &tok )
 {
  const CongRandGenToken  *pToken =
                DYNACAST( const CongRandGenToken * )(tok.Implementation());

  if(pToken)
   {
    SetSeed( pToken->myBaseSeed );
    SetCurrSeed( pToken->myCurrSeed );
    return 1;
   }

  return 0;
 }



void    CongruentialRandGen::IntSeed( size_rand seed )
 {
  SetSeed( seed );
  Reset();
 }
