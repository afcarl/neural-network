/*
 * Neural Network Library
 * Copyright 2012, Mickael Lebedev
 */

#ifndef PERCEPTRON_H_
#define PERCEPTRON_H_

#include <vector>

namespace NeuralNetwork {

class Perceptron {
 private:
  const double learning_rate_;
  double (*activation)(double);
  std::vector<double> weights_;
  std::vector<double> inputs_;
  double threshold_;
  double output_;
  int size_;

 public:
  explicit Perceptron(int inputs_nb);
  double getOutput(const std::vector<double>& inputs);
  void updateWeights(double delta);
  void trainOnData(const std::vector<std::vector<double> >& input_set,
                   const std::vector<double>& target_output_set,
                   int max_epochs);
  void randomizeWeights(int min = -1.0, int max = 1.0);
  const std::vector<double>& getWeights() const;
  double getLastOutput() const;
  double getThreshold() const;
  void setActivationFunction(double (*f)(double));
  virtual ~Perceptron();
};
}

#endif  // PERCEPTRON_H_
