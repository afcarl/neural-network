/*
 * Neural Network Library
 * Copyright 2012, Mickael Lebedev
 */

#include <time.h>
#include <cstdlib>
#include "./random.h"

using namespace NeuralNetwork;

/*
 * Random number generator from Numerical Recipes in C, p. 280.
 */
float ran1(long *idum) {
  int j;
  long k;
  static long iy=0;
  static long iv[NTAB];
  float temp;
     
  if (*idum <= 0 || !iy) {
    if (-(*idum) < 1) *idum = 1;
    else *idum = -(*idum);
    for (j=NTAB+7; j>=0; j--) {
      k = (*idum)/IQ;
      *idum=IA*(*idum-k*IQ)-IR*k;
      if (*idum <0) *idum += IM;
      if (j < NTAB) iv[j] = *idum;
    }
    iy = iv[0];
  }
  k = (*idum)/IQ;
  *idum=IA*(*idum-k*IQ)-IR*k;
  if (*idum < 0) *idum += IM;
  j = iy/NDIV;
  iy=iv[j];
  iv[j] = *idum;
  if ((temp=AM*iy) > RNMX) return RNMX;
  else return temp;
}

bool Random::initialized_ = false;
long Random::idum_ = 0;

void Random::initialize() {
  if (!initialized_) {
    idum_ = -time(0);
    initialized_ = true;
  }
}

double Random::rand(double min, double max) {
  return ran1(&idum_) * (max - min) + min;
}
