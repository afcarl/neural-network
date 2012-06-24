#include <iostream>
#include "../multilayer_perceptron.h"

void create_training_data(std::vector<std::vector<double> >& input_data,
std::vector<std::vector<double> >& output_data) {
	double input_arr[4][2] =
	{0, 0,
	 1, 0,
	 0, 1,
	 1, 1};
	double output_arr[4][1] = {0, 1, 1, 0};
	
	for (int i = 0; i < 4; i++) {
		input_data[i].assign(input_arr[i], input_arr[i] + sizeof(input_arr[i]) / sizeof(double));
		output_data[i].assign(output_arr[i], output_arr[i] + sizeof(output_arr[i]) / sizeof(double));
	}
}

int main(void) {
	NeuralNetwork::MultilayerPerceptron mlp(2, 2, 1);	
	std::vector<std::vector<double> > input_data(4);
	std::vector<std::vector<double> > output_data(4);
	create_training_data(input_data, output_data);
	
	std::cout << "Untrained mlp:" << std::endl;
	for (int i = 0; i < 4; i++) {
		std::cout << "input vector: " << input_data[i][0] << " "<< input_data[i][1] << ", ";
		std::cout << "expected output: " << output_data[i][0] << ", ";
		std::cout << "output: " << mlp.getOutput(input_data[i])[0] << std::endl;
	}

	mlp.trainOnData(input_data, output_data, 10000, 0.001);

	std::cout << std::endl << "After training:" << std::endl;
	for (int i = 0; i < 4; i++) {
		std::cout << "input vector: " << input_data[i][0] << " "<< input_data[i][1] << ", ";
		std::cout << "expected output: " << output_data[i][0] << ", ";
		std::cout << "output: " << mlp.getOutput(input_data[i])[0] << std::endl;
	}

	return 0;
}