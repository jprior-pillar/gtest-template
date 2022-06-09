// A sample program demonstrating using Google C++ testing framework.
// Code examples from Google Test's code samples. https://github.com/google/googletest/tree/main/googletest/samples

#ifndef GOOGLETEST_SAMPLES_SAMPLE1_H_
#define GOOGLETEST_SAMPLES_SAMPLE1_H_

/// Factorial
///
/// Factorial, in mathematics, the product of all positive integers less than or equal to a
/// given positive integer and denoted by that integer and an exclamation point.
///
/// \param n - Positive integer greater than 0.
/// \return int - Returns n! (the factorial of n).  For negative n, n! is defined to be 1.
int Factorial(int n);

///
bool IsPrime(int n);

#endif  // GOOGLETEST_SAMPLES_SAMPLE1_H_
