/*
 * Neural Network Library
 * Copyright 2012, Mickael Lebedev
 */

#include <math.h>
#include "./activation_function.h"

using namespace NeuralNetwork;

double ActivationFunction::sigmoid(double x) {
  return (1 / (1 + exp(-x)));
}

double ActivationFunction::heavyside(double x) {
	return 1 ? x >= 0 : 0;
}