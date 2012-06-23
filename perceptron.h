/*
 * Neural Network Library
 * Copyright 2012, Mickael Lebedev
 */

#ifndef PERCEPTRON_H_
#define PERCEPTRON_H_

#include "./genotype.h"

namespace NeuralNetwork {

class Perceptron {
 private:
  const double learning_rate_;
  double (*activation)(double);
  std::vector<double> weights_;
  std::vector<double> inputs_;
  double threshold_;
  int size_;

 public:
  explicit Perceptron(int inputs_nb);
  double getOutput(const std::vector<double>& inputs);
  void updateWeights(double delta);
  void randomizeWeights(int left_limit = -1.0, int right_limit = 1.0);
  const std::vector<double>& getWeights() const;
  double getThreshold() const;
  virtual ~Perceptron();
};
}

#endif  // PERCEPTRON_H_
