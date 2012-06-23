/*
 * Neural Network Library
 * Copyright 2012, Mickael Lebedev
 */

#ifndef NEURAL_NETWORK_EXCEPTION_H_
#define NEURAL_NETWORK_EXCEPTION_H_

#include <exception>

class NeuralNetworkException: public std::exception {
 private:
  const char* err_;
  virtual const char* what() const throw();

 public:
  explicit NeuralNetworkException(const char* err);
};

#endif  // NEURAL_NETWORK_EXCEPTION_H_
