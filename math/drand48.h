/*      drand48, etc. pseudo-random number generator
 *      This implementation assumes unsigned short integers of at least
 *      16 bits, long integers of at least 32 bits, and ignores
 *      overflows on adding or multiplying two unsigned integers.
 *      Two's-complement representation is assumed in a few places.
 *      Some extra masking is done if unsigneds are exactly 16 bits
 *      or longs are exactly 32 bits.

 *      An assembly-language implementation would run significantly faster.
 */
#ifndef drand48_h
#define drand48_h
#ifndef HAVEFP
#define HAVEFP 1
#endif
#define N       16
#define MASK    ((unsigned)(1 << (N - 1)) + (1 << (N - 1)) - 1)
#define LOW(x)  ((unsigned)(x) & MASK)
#define HIGH(x) LOW((x) >> N)
#define MUL(x, y, z)    { long l = (long)(x) * (long)(y); \
                (z)[0] = LOW(l); (z)[1] = HIGH(l); }
#define CARRY(x, y)     ((long)(x) + (long)(y) > MASK)
#define ADDEQU(x, y, z) (z = CARRY(x, (y)), x = LOW(x + (y)))
#define X0      0x330E
#define X1      0xABCD
#define X2      0x1234
#define A0      0xE66D
#define A1      0xDEEC
#define A2      0x5
#define C       0xB
#define SET3(x, x0, x1, x2)     ((x)[0] = (x0), (x)[1] = (x1), (x)[2] = (x2))
#define SETLOW(x, y, n) SET3(x, LOW((y)[n]), LOW((y)[(n)+1]), LOW((y)[(n)+2]))
#define SEED(x0, x1, x2) (SET3(x, x0, x1, x2), SET3(a, A0, A1, A2), c = C)
#define REST(v) for (i = 0; i < 3; i++) { xsubi[i] = x[i]; x[i] = temp[i]; } \
                return (v);

#define NEST(TYPE, f, F)        TYPE f(register unsigned short* xsubi) { \
        register int i; register TYPE v; unsigned temp[3]; \
        for (i = 0; i < 3; i++) { temp[i] = x[i]; x[i] = LOW(xsubi[i]); }  \
        v = F(); REST(v); }
#define HI_BIT  (1L << (2 * N - 1))
static unsigned x[3] = { X0, X1, X2 }, a[3] = { A0, A1, A2 }, c = C;
static unsigned short lastx[3];
static void next();
#if HAVEFP
double drand48();
double erand48(unsigned short xsubi[3]);
#else
long irand48(register unsigned short m);
long krand48(register unsigned short* xsubi,unsigned short m)
#endif
long lrand48();
long nrand48(unsigned short xsubi[3]);
long mrand48();
long jrand48(unsigned short xsubi[3]);
void next();
void srand48(long seedval);
unsigned short * seed48(unsigned short seed16v[3]);
void lcong48(unsigned short param[7]);
#endif
