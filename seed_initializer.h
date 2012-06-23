/*
 * Neural Network Library
 * Copyright 2012, Mickael Lebedev
 */

#ifndef SEED_INITIALIZER_H_
#define SEED_INITIALIZER_H_

class SeedInitializer {
 public:
  static void initialize();
  static double rand(double a, double b);
  static int rand(int a, int b);

 private:
  static bool _initialized;
  SeedInitializer() {}
};

#endif  // SEED_INITIALIZER_H_
