/* =========================================================================
 *                                 RANDCOMP.CPP
 * -------------------------------------------------------------------------
 *  Implementation file for a random number generator class based on the
 *  rand() function in the current library.
 *
 *  Version 0.9
 *
 *  Copyright 1995-1997 by G. Wade Johnson
 *   Use of this code is placed in the public domain as long as the
 *   copyright notice is retained.
 */

#include <stdlib.h>
#include "environ.h"
#include _STRING_HEADER

#include _STRSTREAM_HEADER

#include "randcomp.h"


class  CompilerRandGenToken : public RandGenTokenImpl
 {
public:
  virtual   ~CompilerRandGenToken( void ) { }

  virtual _STRING  CreateInitString( void ) const;
  virtual int   Initialize( istream &InitStream );
  virtual DIFFRET(RandGenTokenImpl,CompilerRandGenToken)   *Clone() const
   {
    return new CompilerRandGenToken( mySeed, myCount );
   }

  void       Print( ostream &os ) const
   {
    os << '(' << mySeed << ',' << myCount << ')' << flush;
   }
  void       Read( istream &is )
   {
    char  dummy;
    is >> dummy >> mySeed >> dummy >> myCount >> dummy;
   } 

private:
  friend class CompilerRandGen;
  CompilerRandGenToken( size_rand Seed, unsigned long Count )
   : mySeed(Seed), myCount(Count)
   { }
  size_rand       mySeed;
  unsigned long   myCount;
 } ;





_STRING   CompilerRandGenToken::CreateInitString( void ) const
 {
  ostrstream  String;

  String << mySeed << ends;

  return _STRING( String.str() );
 }




int   CompilerRandGenToken::Initialize( istream &InitStream )
 {
  InitStream >> ws >> mySeed;
  myCount = 0L;

  return 1;
 }



DIFFRET(RandomGenerator,CompilerRandGen)
                                       *CompilerRandGen::ReCreate( void ) const
 {
  return new CompilerRandGen( mySeed );
 }



void           CompilerRandGen::RunTo( unsigned long cnt )
 {
  for(unsigned long i=myCount;i<cnt;++i)
    rand();

  myCount = cnt;
 }

RandGenToken    CompilerRandGen::CreateToken( void ) const
 {
  return  RandGenToken( new CompilerRandGenToken( mySeed, myCount ) );
 }



int   CompilerRandGen::SetToken( const RandGenToken &tok )
 {
  const CompilerRandGenToken  *pToken =
                DYNACAST( const CompilerRandGenToken * )(tok.Implementation());

  if(pToken)
   {
    SetSeed( pToken->mySeed );
    Reset();
    RunTo( pToken->myCount );

    return 1;
   }

  return 0;
 }



void    CompilerRandGen::IntSeed( size_rand seed )
 {
  SetSeed( seed );
  Reset();
 }




void        CompilerRandGen::Reset( void )
 {
  srand( (unsigned)mySeed );
  myCount = 0L;
 }




size_rand   CompilerRandGen::MaxRandom( void ) const
 {
  return RAND_MAX;
 }





size_rand    CompilerRandGen::Number( void )
 {
  ++myCount;
  return (size_rand)rand();
 }
