/* ========================================================================
 *                                MODARITH.H
 * ------------------------------------------------------------------------
 *  Interface file for the modular arithmetic functions.
 *
 *  Version 0.9
 *
 *  Copyright 1995-1997 by G. Wade Johnson
 *   Use of this code is placed in the public domain as long as the
 *   copyright notice is retained.
 */

#if !defined( MODARITH_H )
  #define MODARITH_H

  struct  mod_result
   {
    unsigned long   result;
    unsigned long   carry;
   } ;

  extern unsigned long   mod_add( unsigned long a, unsigned long b,
                                                        unsigned long mod );
  extern unsigned long   mod_mult( unsigned long a, unsigned long b,
                                                        unsigned long mod );
  extern unsigned long   mod_invert( unsigned long num, unsigned long mod );

  extern mod_result      mod_add_c( unsigned long a, unsigned long b,
                                                        unsigned long mod );
  extern mod_result      mod_mult_c( unsigned long a, unsigned long b,
                                                        unsigned long mod );

  extern mod_result      mod_add_c( unsigned long a, unsigned long b );
  extern mod_result      mod_mult_c( unsigned long a, unsigned long b );

#endif
