/*
 * Neural Network Library
 * Copyright 2012, Mickael Lebedev
 */

#include "./neural_network_exception.h"

NeuralNetworkException::NeuralNetworkException(const char* err) : err_(err) {}

const char* NeuralNetworkException::what() const throw() {
  return err_;
}
