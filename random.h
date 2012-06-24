/*
 * Neural Network Library
 * Copyright 2012, Mickael Lebedev
 */

#ifndef RANDOM_H_
#define RANDOM_H_

#define IA 16807
#define IM 2147483647
#define AM (1.0/IM)
#define IQ 127773
#define IR 2836
#define NTAB 32
#define NDIV (1+(IM-1)/NTAB)
#define EPS 1.2e-7
#define RNMX (1.0-EPS)

namespace NeuralNetwork {

class Random {
 public:
  static void initialize();
  static double rand(double min, double max);

 private:
  static bool initialized_;
  static long idum_;
  Random() {}
};

}

#endif  // RANDOM_H_
