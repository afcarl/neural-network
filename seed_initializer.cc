/*
 * Neural Network Library
 * Copyright 2012, Mickael Lebedev
 */

#include <time.h>
#include <cstdlib>
#include "./seed_initializer.h"

bool SeedInitializer::_initialized = false;

void SeedInitializer::initialize() {
  if (!_initialized) {
    srand((unsigned)time(0));
    _initialized = true;
  }
}

double SeedInitializer::rand(double a, double b) {
  return (double)(::rand() / (double)RAND_MAX * (b - a) + a);
}
