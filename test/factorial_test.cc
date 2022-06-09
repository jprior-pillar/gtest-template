#include "factorial.h"
#include <limits.h>
#include "gtest/gtest.h"

namespace FactorialTests {

    /**\file factorial_test.cc
     *
     * \test FactorialTest Test Suite
     *
     * Boundary Condition | Test     | Description
     * :----------------  | :------- | :---------
     * Positive           | Positive | Verify that normal input is handled as expected.
     * Negative           | Negative | Verify that it returns 1 for values less than zero
     * Negative           | Zero     | Verify that it returns 1 for values of zero
     *
     * **TODO: Technical Debt**
     *
     * This class does not do X because it has private interdependecies
     */
    TEST(FactorialTest, Positive) {
        EXPECT_EQ(1, Factorial(1));
        EXPECT_EQ(2, Factorial(2));
        EXPECT_EQ(6, Factorial(3));
        EXPECT_EQ(40320, Factorial(8));
    }

    TEST(FactorialTest, Negative) {
        /// This test is named "Negative", and belongs to the "FactorialTest"
        /// test case.
        EXPECT_EQ(1, Factorial(-5));
        EXPECT_EQ(1, Factorial(-1));
        EXPECT_GT(Factorial(-10), 0);
    }

    TEST(FactorialTest, Zero) { EXPECT_EQ(1, Factorial(0)); }
}

namespace IsPrimeTests {

    /**\file factorial_test.cc
     *
     * \test IsPrimeTest Test Suite
     *
     * Boundary Condition | Test     | Description
     * :----------------  | :------- | :---------
     * Negative           | Negative | Verify that it returns 1 for values less than zero
     * Negative           | Trivial  | Verify that it returns 1 for values of zero
     * Positive           | Positive | Verify that normal input is handled as expected.
     * Exception          | NullPntr | Verify that it throws a YadaYadaException when null is passed in
     */
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
