#include "drand48.h"

/*      drand48, etc. pseudo-random number generator
 *      This implementation assumes unsigned short integers of at least
 *      16 bits, long integers of at least 32 bits, and ignores
 *      overflows on adding or multiplying two unsigned integers.
 *      Two's-complement representation is assumed in a few places.
 *      Some extra masking is done if unsigneds are exactly 16 bits
 *      or longs are exactly 32 bits.
 *      An assembly-language implementation would run significantly faster.
 */

#if HAVEFP
double drand48()
{
#if pdp11
        static double two16m; /* old pdp11 cc can't compile an expression */
        two16m = 1.0 / (1L << N); /* in "double" initializer! */
#else
        static double two16m = 1.0 / (1L << N);
#endif
        next();
        return (two16m * (two16m * (two16m * x[0] + x[1]) + x[2]));
}
NEST(double, erand48, drand48);
NEST(long, nrand48, lrand48);
NEST(long, jrand48, mrand48);
#else

long irand48(register unsigned short m)
/* Treat x[i] as a 48-bit fraction, and multiply it by the 16-bit
 * multiplier m.  Return integer part as result.
 */
{
        unsigned r[4], p[2], carry0 = 0;
        next();
        MUL(m, x[0], &r[0]);
        MUL(m, x[2], &r[2]);
        MUL(m, x[1], p);
        if (CARRY(r[1], p[0]))
                ADDEQU(r[2], 1, carry0);
        return (r[3] + carry0 + CARRY(r[2], p[1]));
}

/* same as irand48, except user provides storage in xsubi[] */
long krand48(register unsigned short* xsubi,unsigned short m)
{
        register int i;
        register long iv;
        unsigned temp[3];
        for (i = 0; i < 3; i++) {
           temp[i] = x[i];
           x[i] = xsubi[i];
        }
        iv = irand48(m);
        REST(iv);
}
#endif
long lrand48()
{
        next();
        return (((long)x[2] << (N - 1)) + (x[1] >> 1));
}

long mrand48()
{
        register long l;
        next();
        /* sign-extend in case length of a long > 32 bits
                                                (as on Honeywell) */
        return ((l = ((long)x[2] << N) + x[1]) & HI_BIT ? l | -HI_BIT : l);
}

void next()
{
        unsigned p[2], q[2], r[2], carry0, carry1;
        MUL(a[0], x[0], p);
        ADDEQU(p[0], c, carry0);
        ADDEQU(p[1], carry0, carry1);
        MUL(a[0], x[1], q);
        ADDEQU(p[1], q[0], carry0);
        MUL(a[1], x[0], r);
        x[2] = LOW(carry0 + carry1 + CARRY(p[1], r[0]) + q[1] + r[1] +
                a[0] * x[2] + a[1] * x[1] + a[2] * x[0]);
        x[1] = LOW(p[1] + r[0]);
        x[0] = LOW(p[0]);
}

void srand48(long seedval)
{
        SEED(X0, LOW(seedval), HIGH(seedval));
}

unsigned short * seed48(unsigned short seed16v[3])
{
        SETLOW(lastx, x, 0);
        SEED(LOW(seed16v[0]), LOW(seed16v[1]), LOW(seed16v[2]));
        return (lastx);
}

void lcong48(unsigned short param[7])
{
        SETLOW(x, param, 0);
        SETLOW(a, param, 3);
        c = LOW(param[6]);
}