#include "factorial.h"
#include <limits.h>
#include "gtest/gtest.h"

/**\file factorial_test.cc
 *
 * Test Suites related to the `factorial.cc`.
 */

/**
 * \test FactorialTest Test Suite
 *
 * Type     | Test     | Description
 * :------- | :------- | :---------
 * Positive | Positive | Verify that normal input is handled as expected.
 * Negative | Negative | Verify that it returns 1 for values less than zero
 * Negative | Zero     | Verify that it returns 1 for values of zero
 *
 * **TODO: Technical Debt**
 *
 * * No tests for handling nullptr.
 */
namespace FactorialTests {
    TEST(FactorialTest, Positive) {
        EXPECT_EQ(1, Factorial(1));
        EXPECT_EQ(2, Factorial(2));
        EXPECT_EQ(6, Factorial(3));
        EXPECT_EQ(40320, Factorial(8));
    }

    TEST(FactorialTest, Negative) {
        EXPECT_EQ(1, Factorial(-5));
        EXPECT_EQ(1, Factorial(-1));
        EXPECT_GT(Factorial(-10), 0);
    }

    TEST(FactorialTest, Zero) { EXPECT_EQ(1, Factorial(0)); }
}

/**
 *
 * \test IsPrimeTest Test Suite
 *
 * Type     | Test     | Description
 * :------- | :------- | :---------
 * Negative | Negative | Verify that it returns 1 for values less than zero
 * Negative | Trivial  | Verify that it returns 1 for values of zero
 * Positive | Positive | Verify that normal input is handled as expected.
 */
namespace IsPrimeTests {
    TEST(IsPrimeTest, Negative) {
        EXPECT_FALSE(IsPrime(-1));
        EXPECT_FALSE(IsPrime(-2));
        EXPECT_FALSE(IsPrime(INT_MIN));
    }

    TEST(IsPrimeTest, Trivial) {
        EXPECT_FALSE(IsPrime(0));
        EXPECT_FALSE(IsPrime(1));
        EXPECT_TRUE(IsPrime(2));
        EXPECT_TRUE(IsPrime(3));
    }

    TEST(IsPrimeTest, Positive) {
        EXPECT_FALSE(IsPrime(4));
        EXPECT_TRUE(IsPrime(5));
        EXPECT_FALSE(IsPrime(6));
        EXPECT_TRUE(IsPrime(23));
    }
}
