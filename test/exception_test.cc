#include <cmath>
#include <iostream>
#include "gtest/gtest.h"

/**\file exception_test.cc
 *
 * \test Exception Test Example
 *
 * Example of a Google Test [Exception Assertions](https://google.github.io/googletest/reference/assertions.html#exceptions).
 *
 *  * Type   | Test Name          | Description
 * :-------- | :----------------- | :---------
 * Exception | LessThanZeroThrows | Validate square_root throws exception on less than zero
 *
 */
namespace ExceptionTests {

    /**
     * Throws a `std::runtime_error` if a `double` less than zero is passed in.
     *
     * @param num
     * @return square root
     */
    double square_root(double num) {
        if (num < 0.0) {
            throw std::runtime_error("Error: Negative Input");
        }
        return sqrt(num);
    }

    TEST(ExceptionTest, LessThanZeroThrows) {
        EXPECT_ANY_THROW(ExceptionTests::square_root(-1.0));
        EXPECT_THROW(ExceptionTests::square_root(-1.0), std::runtime_error);
    }
}
