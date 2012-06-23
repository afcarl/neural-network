/*
 * Neural Network Library
 * Copyright 2012, Mickael Lebedev
 */

#include "./neural_network_exception.h"

NeuralNetworkException::NeuralNetworkException(const char* err) : _err(err) {}

const char* NeuralNetworkException::what() const throw() {
  return _err;
}
