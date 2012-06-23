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
  double mse_;
  std::vector<Perceptron*> hidden_layer_;
  std::vector<Perceptron*> output_layer_;

 public:
  MLPerceptron(int input_nb, int hidden_layer_size, int output_nb);
  std::vector<double> getOutput(const std::vector<double>& input);
  void trainOnData(const std::vector<std::vector<double> >& input_set,
	const std::vector<std::vector<double> >& target_output_set,
	int max_epochs, double max_mse);
  void train(const std::vector<double>& input, const std::vector<double>& target_output);
  double getMSE() const;
  virtual ~MLPerceptron();
};

}

#endif  // MLPERCEPTRON_H_
