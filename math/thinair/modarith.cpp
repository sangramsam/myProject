/* ========================================================================
 *                               MODARITH.CPP
 * ------------------------------------------------------------------------
 *  Implementation file for the modular arithmetic functions
 *
 *  Version 0.9
 *
 *  Copyright 1995-1997 by G. Wade Johnson
 *   Use of this code is placed in the public domain as long as the
 *   copyright notice is retained.
 */

#include "environ.h"

#include "modarith.h"

static unsigned long  c;

#define  mod_add_i( a, b, mod )   (c=a+b,c=(c>mod||c<a||c<b)?c-mod:c,c)



unsigned long   mod_add( unsigned long a, unsigned long b, unsigned long mod )
 {
#if defined( _HAS_INT64 )
  return (((Int64)a+(Int64)b)%(Int64)mod);
#else
  if(a >= mod) a%=mod;
  if(b >= mod) b%=mod;

  return mod_add_i( a, b, mod );
#endif
 }







unsigned long   mod_mult( unsigned long a, unsigned long b, unsigned long mod )
 {
#if defined( _HAS_INT64 )
  return (((Int64)a*(Int64)b)%(Int64)mod);
#else
  unsigned long  result, result2;
  unsigned long  mask = 0x80000000UL;

  if(a >= mod) a%=mod;
  if(b >= mod) b%=mod;

  if(0UL == a || 0UL == b)
    return 0UL;

  if(b > a)
   {
    result = b;
    b = a;
    a = result;
   }

  while(0 == (b&mask))
    mask >>= 1;

  result = 0L;

  do
   {
    result2 = result << 1;

    if(result2 > mod || result2 < result)
      result = result2 - mod;
    else
      result = result2;

    if(b&mask)
     {
      result = mod_add_i( result, a, mod );
     }

   } while(0 != (mask >>= 1));

  return result;
#endif
 }




/* =========================================================================
 *  Inversion routine written by Rick Hoselton.
 */

unsigned long   mod_invert( unsigned long num, unsigned long mod )
 {
  unsigned long   Quot, Rem, Temp, Thing1, Thing2;
  long            Factor1, Factor2;

  Thing1 = mod;
  Thing2 = num;

  if(Thing2 == 0 || Thing2 == 1 || Thing2 == Thing1)  // Simple cases
    return Thing2;

  Factor1 = 0;
  Factor2 = 1;

  while(Thing2 != 0)
   {
    Quot    = Thing1/Thing2;
    Rem     = Thing1%Thing2;
    Thing1  = Thing2;
    Thing2  = Rem;
    Temp    = (unsigned long)Factor1 - Quot*(unsigned long)Factor2;
    Factor1 = Factor2;
    Factor2 = (long)Temp;
   }

  if(Thing1 != 1)
    return 0UL;

  if(Factor1 > 0)
    return (unsigned long)Factor1;
  else
    return (unsigned long)(Factor1+mod);
 }



mod_result      mod_add_c( unsigned long a, unsigned long b, unsigned long mod )
 {
  mod_result  result = {0,0};

#if defined( _HAS_INT64 )
  Int64  sum = (Int64)a + (Int64)b;
  result.carry  = (unsigned long)(sum / (Int64)mod);
  result.result = (unsigned long)(sum % (Int64)mod);
#else
  if(a >= mod)
   {
    result.carry += a/mod;
    a %= mod;
   }
  if(b >= mod)
   {
    result.carry += b/mod;
    b %= mod;
   }

  result.result = a + b;
  if(result.result>mod||result.result<a||result.result<b)
   {
    result.result -= mod;
    result.carry++;
   }
#endif

  return result;
 }







mod_result     mod_mult_c( unsigned long a, unsigned long b, unsigned long mod )
 {
  mod_result     result={0,0};
#if defined( _HAS_INT64 )
  Int64  prod = (Int64)a * (Int64)b;
  result.carry  = (unsigned long)(prod / (Int64)mod);
  result.result = (unsigned long)(prod % (Int64)mod);
#else
  mod_result     result2={0,0};
  unsigned long  mask = 0x80000000UL;

  result.carry = 0L;
  if(a >= mod)
   {
    result.carry += a/mod;
    a %= mod;
   }
  if(b >= mod)
   {
    result.carry += b/mod;
    b %= mod;
   }

  if(0UL == a || 0UL == b)
    return result;

  if(b > a)
   {
    result.result = b;
    b = a;
    a = result.result;
   }

  while(0 == (b&mask))
    mask >>= 1;

  result.result = 0L;

  do
   {
    result2.result = result.result << 1;
    result.carry <<= 1;

    if(result2.result > mod || result2.result < result.result)
     {
      result.result = result2.result - mod;
      result.carry++;
     }
    else
     {
      result.result = result2.result;
     }

    if(b&mask)
     {
      result2 = mod_add_c( result.result, a, mod );
      result.result = result2.result;
      result.carry += result2.carry;
     }

   } while(0 != (mask >>= 1));
#endif

  return result;
 }



mod_result      mod_add_c( unsigned long a, unsigned long b )
 {
  mod_result  result = {0,0};

#if defined( _HAS_INT64 )
  Int64  sum = (Int64)a + (Int64)b;
  result.carry  = (unsigned long)(sum >> 32);
  result.result = (unsigned long)(sum & 0xFFFFFFFFUL);
#else
  result.result = a + b;
  if(result.result<a||result.result<b)
   {
    result.carry++;
   }
#endif

  return result;
 }







mod_result     mod_mult_c( unsigned long a, unsigned long b )
 {
  mod_result     result={0,0};

#if defined( _HAS_INT64 )
  Int64  prod = (Int64)a * (Int64)b;
  result.carry  = (unsigned long)(prod >> 32);
  result.result = (unsigned long)(prod & 0xFFFFFFFFUL);
#else
  mod_result     result2={0,0};
  unsigned long  mask = 0x80000000UL;

  result.carry = 0L;

  if(0UL == a || 0UL == b)
    return result;

  if(b > a)
   {
    result.result = b;
    b = a;
    a = result.result;
   }

  while(0 == (b&mask))
    mask >>= 1;

  result.result = 0L;

  do
   {
    result2.result = result.result << 1;
    result.carry <<= 1;

    if(result2.result < result.result)
      result.carry++;

    result.result = result2.result;

    if(b&mask)
     {
      result2 = mod_add_c( result.result, a );
      result.result = result2.result;
      result.carry += result2.carry;
     }

   } while(0 != (mask >>= 1));
#endif

  return result;
 }



#if defined( STANDALONE )

#include _IOSTREAM_HEADER


void   add_test( unsigned long a, unsigned long b, unsigned long mod,
                 unsigned long ans )
 {
  unsigned long   result = mod_add(a,b,mod);

  cout << a << " + " << b << " mod " << mod << " = " << result
       << ((result==ans)?" Correct!!":" Wrong!!") << endl;
 }


void   mult_test( unsigned long a, unsigned long b, unsigned long mod,
                  unsigned long ans )
 {
  unsigned long   result = mod_mult(a,b,mod);

  cout << a << " * " << b << " mod " << mod << " = " << result
       << ((result==ans)?" Correct!!":" Wrong!!") << endl;
 }


void   add_test_c( unsigned long a, unsigned long b, unsigned long mod,
                   unsigned long ans, unsigned long carry )
 {
  mod_result   result = mod_add_c(a,b,mod);

  cout << a << " + " << b << " mod " << mod << " = " << result.result
       << ", carry = " << result.carry
       << ((result.result==ans&&result.carry==carry)?" Correct!!":" Wrong!!")
       << endl;
 }


void   mult_test_c( unsigned long a, unsigned long b, unsigned long mod,
                  unsigned long ans, unsigned long carry )
 {
  mod_result   result = mod_mult_c(a,b,mod);

  cout << a << " * " << b << " mod " << mod << " = " << result.result
       << ", carry = " << result.carry
       << ((result.result==ans&&result.carry==carry)?" Correct!!":" Wrong!!")
       << endl;
 }


void   add_test_c( unsigned long a, unsigned long b, unsigned long ans,
                   unsigned long carry )
 {
  mod_result   result = mod_add_c(a,b);

  cout << a << " + " << b << " mod 2^32 = " << result.result
       << ", carry = " << result.carry
       << ((result.result==ans&&result.carry==carry)?" Correct!!":" Wrong!!")
       << endl;
 }


void   mult_test_c( unsigned long a, unsigned long b, unsigned long ans,
                    unsigned long carry )
 {
  mod_result   result = mod_mult_c(a,b);

  cout << a << " * " << b << " mod 2^32 = " << result.result
       << ", carry = " << result.carry
       << ((result.result==ans&&result.carry==carry)?" Correct!!":" Wrong!!")
       << endl;
 }


int  main( void )
 {
  add_test( 1000, 500, 0x10000000UL, 1500UL );
  add_test( 1000, 0x10000000UL-1, 0x10000000UL, 999UL );
  add_test( 0xFFFFFFFFUL, 0x10000000UL-1, 0x10000001UL, 268435438UL );

  mult_test( 1000, 500, 0x10000000UL, 500000UL );
  mult_test( 10000, 5000, 0x10000000UL, 50000000UL );
  mult_test( 1000, 0x10000000UL-1, 0x10000000UL, 268434456UL );

  cout << "\n";

  add_test_c( 1000, 500, 0x10000000UL, 1500UL, 0UL );
  add_test_c( 1000, 0x10000000UL-1, 0x10000000UL, 999UL, 1UL );
  add_test_c( 0xFFFFFFFFUL, 0x10000000UL-1, 0x10000001UL, 268435438UL, 16UL );

  mult_test_c( 1000, 500, 0x10000000UL, 500000UL, 0 );
  mult_test_c( 10000, 5000, 0x10000000UL, 50000000UL, 0 );
  mult_test_c( 1000, 0x10000000UL-1, 0x10000000UL, 268434456UL, 999UL );

  cout << "\n";

  add_test_c( 1000UL, 500UL, 1500UL, 0UL );
  add_test_c( 0xFFFFFFFFUL, 0xFFFFFFFFUL, 0xFFFFFFFEUL, 1UL );
  add_test_c( 0xFFFFFFFFUL, 1UL, 0UL, 1UL );

  mult_test_c( 1000, 500, 500000UL, 0 );
  mult_test_c( 0xFFFFFFFFUL, 0xFFFFFFFFUL, 1UL, 0xFFFFFFFEUL );
  mult_test_c( 0xFFFFFFFFUL, 0x10000000UL, 0xF0000000UL, 0x0FFFFFFFUL );

  return 0;
 }
#endif
