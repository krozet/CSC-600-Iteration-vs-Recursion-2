/*
Keawa Rozet
CSc 600-01 - Programming Languages
Homework #2
Iteration vs Recursion 2
*/

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <limits>

typedef std::numeric_limits< double > dbl;

unsigned long long Frec(unsigned int n);
unsigned long long Fit(unsigned int n);
void fibTimeMeasurement(unsigned int n);

int main(int argc, char const** argv) {
  fibTimeMeasurement(30);

  return 0;
}

unsigned long long Frec(unsigned int n) {
  return (n < 2) ? n : Frec(n-1) + Frec(n-2);
}

unsigned long long Fit(unsigned int n) {
  int i, zero = 0, first = 1, second = n;
  for (i = 2; i <= n; i++) {
    second = first + zero;
    zero = first;
    first = second;
  }
  return second;
}

void fibTimeMeasurement(unsigned int n) {
  //first test binarySearchIteration
  clock_t begin = clock();
  unsigned long long value = Fit(n);
  clock_t end = clock();
  double fit_elapsed_secs = double(end - begin)/CLOCKS_PER_SEC;
  std::cout.precision(dbl::max_digits10);
  std::cout << "Fib Iteration = " << value << " for n=" << n <<": " << std::fixed << fit_elapsed_secs << " seconds." << std::endl;

  //second test binarySearchRecursion
  clock_t begin2 = clock();
  unsigned long long value2 = Frec(n);
  clock_t end2 = clock();
  double frec_elapsed_secs = double(end2 - begin2)/CLOCKS_PER_SEC;
  std::cout.precision(dbl::max_digits10);
  std::cout << "Fib Recursion = " << value2 << " for n=" << n <<": " << std::fixed << frec_elapsed_secs << " seconds." << std::endl;
  }
