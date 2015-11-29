#include "math.h"

extern double _pow(double x, double y);
extern double _log(double x);
extern double _log10(double x);
extern double _sqrt(double x);

double pow(double x, double y)  {   return d2d( _pow( d2d(x), d2d(y) ) );   }

double sqrt(double x)           {   return d2d( _sqrt( d2d(x) ) );  }

double log(double x)            {   return d2d( _log( d2d(x) ) );   }

double log10(double x)          {   return d2d( _log10( d2d(x) ) ); }

// log2(x) = log(x) * (1 / log(2))
double log2(double x)           {   return (log(x) * ((double)1.44269504088906));   }
