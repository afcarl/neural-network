/*
 * Neural Network Library
 * Copyright 2012, Mickael Lebedev
 */

#ifndef MLPERCEPTRON_H_
#define MLPERCEPTRON_H_

#include "./perceptron.h"

namespace NeuralNetwork {

class MLPerceptron {
 private:
  int input_nb_;
  std::vector<Perceptron*> hidden_layer_;
  std::vector<Perceptron*> output_layer_;

 public:
  MLPerceptron(int input_nb, int hidden_layer_size, int output_nb);
  std::vector<double> getOutput(const std::vector<double>& input);
  void backPropagate(const std::vector<double>& input, double target);
  virtual ~MLPerceptron();
};

}

#endif  // MLPERCEPTRON_H_
