/*
 * Neural Network Library
 * Copyright 2012, Mickael Lebedev
 */

#include "./perceptron.h"
#include "./activation_function.h"
#include "./seed_initializer.h"
#include "./neural_network_exception.h"

using namespace NeuralNetwork;

const double learning_rate = 0.1;

Perceptron::Perceptron(int inputs_nb) :
    learning_rate_(learning_rate),
    activation(ActivationFunction::heavyside),
    weights_(inputs_nb),
    size_(inputs_nb) {
  SeedInitializer::initialize();
}

void Perceptron::randomizeWeights(int left_limit, int right_limit) {
  for (int i = 0; i < size_; ++i) {
    weights_[i] = SeedInitializer::rand(left_limit, right_limit);
  }
  threshold_ = SeedInitializer::rand(left_limit, right_limit);
}

double Perceptron::getOutput(const std::vector<double>& inputs) {
  float sum = 0;

  inputs_ = inputs;
  for (int i = 0; i < size_; ++i) {
    sum += inputs[i] * weights_[i];
  }
  return output_ = activation(sum + threshold_);
}

void Perceptron::updateWeights(double delta) {
  for (int i = 0; i < size_; ++i) {
    weights_[i] += (delta * learning_rate_ * inputs_[i]);
  }
  threshold_ += (delta * learning_rate_);
}

const std::vector<double>& Perceptron::getWeights() const {
  return weights_;
}

double Perceptron::getThreshold() const {
  return threshold_;
}

double Perceptron::getLastOutput() const {
  return output_;	
}

void Perceptron::setActivationFunction(double (*f)(double)) {
  activation = f;	
}

Perceptron::~Perceptron() {}
