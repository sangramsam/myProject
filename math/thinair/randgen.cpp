/* =========================================================================
 *                              RANDGEN.CPP
 * -------------------------------------------------------------------------
 *  Implementation file for the Random Number generator base class.
 *
 *  Version 0.9
 *
 *  Copyright 1995-1997 by G. Wade Johnson
 *   Use of this code is placed in the public domain as long as the
 *   copyright notice is retained.
 */

#include "environ.h"

//#include _STRSTREAM_HEADER
#include <strstream>

#include "randgen.h"


istream &operator>>( istream &is, RandGenToken &Token )
 {
  Token.Read( is );
  return is;
 }


ostream &operator<<( ostream &os, RandGenToken const &Token )
 {
  Token.Print( os );
  return os;
 }





int   RandGenToken::Initialize( const _STRING &InitString )
 {
  istrstream  String( CONSTCAST(char *)(InitString.c_str()) );

  return myImpl->Initialize( String );
 }






RandomGenerator  *RandomGenerator::Clone( void ) const
 {
  RandomGenerator *pclone = ReCreate();

  if(!pclone->SetToken( CreateToken() ))
   {
    delete pclone;
    pclone = 0;
   }

  return pclone;
 }
