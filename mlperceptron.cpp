/*
 * Neural Network Library
 * Copyright 2012, Mickael Lebedev
 */

#include <vector>
#include "./perceptron.h"
#include "./mlperceptron.h"
#include "./activation_function.h"
#include "./neural_network_exception.h"

using namespace NeuralNetwork;

MLPerceptron::MLPerceptron(int input_nb, int hidden_layer_size, int output_nb) :
	input_nb_(input_nb), hidden_layer_(hidden_layer_size), output_layer_(output_nb) {
	for (int i = 0; i < hidden_layer_size; ++i) {
		hidden_layer_[i] = new Perceptron(input_nb);
		hidden_layer_[i]->randomizeWeights();
		hidden_layer_[i]->setActivationFunction(ActivationFunction::sigmoid);
	}
	for (int i = 0; i < output_nb; ++i) {
		output_layer_[i] = new Perceptron(hidden_layer_size);
		output_layer_[i]->randomizeWeights();
		output_layer_[i]->setActivationFunction(ActivationFunction::sigmoid);
	}
}

std::vector<double> MLPerceptron::getOutput(const std::vector<double>& input) {
	if (input.size() != (unsigned int)input_nb_) {
		throw NeuralNetworkException("Input layer size mismatch");
	}

	std::vector<double> tmp(hidden_layer_.size()), out(output_layer_.size());
		
	for (unsigned int i = 0; i < hidden_layer_.size(); ++i) {
		tmp[i] = hidden_layer_[i]->getOutput(input);
	}
	for (unsigned int i = 0; i < output_layer_.size(); ++i) {
		out[i] = output_layer_[i]->getOutput(tmp);
	}
	return out;
}

void MLPerceptron::backPropagate(const std::vector<double>& input, double target) {
	float sum;
	std::vector<double> delta(output_layer_.size()), output;
		
	output = this->getOutput(input);
	for (unsigned int i = 0; i < output_layer_.size(); ++i) {
		delta[i] = (target - output[i]) * output[i] * (1 - output[i]);
		output_layer_[i]->updateWeights(delta[i]);
	}
	
	for (unsigned int i = 0; i < hidden_layer_.size(); ++i) {
		sum = 0;
		for (unsigned int j = 0; j < output_layer_.size(); ++j) {
			sum += delta[j] * output_layer_[j]->getWeights()[i];
		}
		hidden_layer_[i]->updateWeights(sum * hidden_layer_[i]->getLastOutput() * (1 - hidden_layer_[i]->getLastOutput()));
	}
}

MLPerceptron::~MLPerceptron() {	
	for (unsigned int i = 0; i < hidden_layer_.size(); ++i) {
		delete hidden_layer_[i];
	}
	for (unsigned int i = 0; i < output_layer_.size(); ++i) {
		delete output_layer_[i];
	}
}

