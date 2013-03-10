/*
CORDIC LIBRARY
integer based trigonometric functions
based on http://www.andreadrian.de/c-workshop/index.html
rudi 2012/12/04

trigonometric functions
    angel as DEG:
    sind, cosd, tand, asind, acosd, atand, recd, pold
    angel as RAD:
    sinr, cosr, tanr, asinr, acosr, atanr, recr, polr

additional functins
    integer calculation (a * b / c):
    fixed muldivScaled(fixed a , fixed b, fixed c)

all values in CORDIC routines are from type 'fixed' (4 byte integer)
    makros to convert values:
    FIXED(X) ...... convert double to cordic fixed
    FLOAT(X) ...... convert cordic fixed to double
    INT2FIXED(X) .. convert integer (value *1000) to cordic fixed
    INT2FIXEDR(X) . equal to INT2FIXED(X) with round
    FIXED2INT(X) .. convert cordic fixed to integer (value * 1000)
    FIXED2INTR(X) . equal to FIXED2INT(X) with round
*/

typedef long fixed;
typedef int int4b; //4 byte integer
enum fcordic {ROTATE, VECTOR};
typedef int fcordic;
enum tangel {RAD, DEG};
typedef int tangel;

enum {
    FRACTIONBITS = 17,
    N = 17,
    M = 9,
    CORDIC_SCALE = 1 << FRACTIONBITS,
    INT_SCALE = 1000,
    ROUND_IN = (INT_SCALE / CORDIC_SCALE) >> 1,
    ROUND_OUT = (CORDIC_SCALE / INT_SCALE) >> 1,
};

#include "limits.h"

#define FIXED(X)        (floatToFixed((X)))
#define FLOAT(X)        ((X) / (double)CORDIC_SCALE)
#define INT2FIXED(X)    (intToFixed((X), 0))
#define INT2FIXEDR(X)   (intToFixed((X), 1))
#define FIXED2INT(X)    (fixedToInt((X), 0))
#define FIXED2INTR(X)   (fixedToInt((X), 1))

//intern used functions
LUALIB_API void cordic(tangel t, fcordic f, fixed *x, fixed *y, fixed *z);
LUALIB_API fixed mulScaled(fixed a, fixed b);
LUALIB_API fixed divScaled(fixed a, fixed b);
LUALIB_API int convertToQ1(fixed *x, fixed *y);
LUALIB_API void convertFromQ1(fixed *x, fixed *y, int q);
LUALIB_API int rotateToQ1(tangel t, fixed *phi);
LUALIB_API void rotateFromQ1(tangel t, fixed *phi, int q);
LUALIB_API fixed cathetus(fixed x);
/* base CIRCULAR mode, ROTATE */
LUALIB_API void sincosCordic(tangel t, fixed phi, fixed *sinphi, fixed *cosphi);
/* base CIRCULAR mode, VECTOR */
LUALIB_API void atanhypCordic(tangel t, fixed px, fixed py, fixed *phi, fixed *hyp);
/* functions CIRCULAR mode, ROTATE */
LUALIB_API fixed sinCordic(tangel t, fixed phi);
LUALIB_API fixed cosCordic(tangel t, fixed phi);
LUALIB_API fixed tanCordic(tangel t, fixed phi);
LUALIB_API void recCordic(tangel t, fixed r, fixed theta, fixed *px, fixed *py);
/* functions CIRCULAR mode, VECTOR */
LUALIB_API fixed asinCordic(tangel t, fixed x);
LUALIB_API fixed acosCordic(tangel t, fixed x);
LUALIB_API fixed atanCordic(tangel t, fixed x);
LUALIB_API void polCordic(tangel t, fixed px, fixed py, fixed *r, fixed *theta);

// extern
// PI/2, PI, 2*PI
LUALIB_API fixed FULL_CIRCLE[];
LUALIB_API fixed HALF_CIRCLE[];
LUALIB_API fixed QUART_CIRCLE[];
//used by macro
LUALIB_API fixed floatToFixed(double a);
LUALIB_API fixed intToFixed(int4b a, int round);
LUALIB_API int4b fixedToInt(fixed a, int round);
//additional
LUALIB_API fixed muldivScaled(fixed a, fixed b, fixed c);
// DEG
LUALIB_API fixed sind(fixed phi);
LUALIB_API fixed cosd(fixed phi);
LUALIB_API fixed tand(fixed phi);
LUALIB_API void recd(fixed r, fixed theta, fixed *px, fixed *py);
LUALIB_API fixed asind(fixed x);
LUALIB_API fixed acosd(fixed x);
LUALIB_API fixed atand(fixed x);
LUALIB_API void pold(fixed px, fixed py, fixed *r, fixed *theta);
// RAD
LUALIB_API fixed sinr(fixed phi);
LUALIB_API fixed cosr(fixed phi);
LUALIB_API fixed tanr(fixed phi);
LUALIB_API void recr(fixed r, fixed theta, fixed *px, fixed *py);
LUALIB_API fixed asinr(fixed x);
LUALIB_API fixed acosr(fixed x);
LUALIB_API fixed atanr(fixed x);
LUALIB_API void polr(fixed px, fixed py, fixed *r, fixed *theta);
