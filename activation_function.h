/*
 * Neural Network Library
 * Copyright 2012, Mickael Lebedev
 */

#ifndef ACTIVATION_FUNCTION_H_
#define ACTIVATION_FUNCTION_H_

namespace NeuralNetwork {

class ActivationFunction  {
 public:
  static double sigmoid(double x);
  static double heavyside(double x);
};
}

#endif  // ACTIVATION_FUNCTION_H_
