/*
 * Neural Network Library
 * Copyright 2012, Mickael Lebedev
 */

#include <math.h>
#include "./activation_function.h"

double ActivationFunction::sigmoid(double x) {
  return (1 / (1 + exp(-x)));
}
