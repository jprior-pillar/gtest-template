#include <cmath>
#include <iostream>
#include "gtest/gtest.h"

/**\file death_test.cc
 *
 * \test Death Test Example
 *
 * Example of a Google Test [Death Test](https://github.com/google/googletest/blob/main/docs/advanced.md#user-content-death-tests).
 *
 * The [Google Test maintainers](https://github.com/google/googletest/blob/main/docs/advanced.md#user-content-death-test-naming)
 * "strongly recommend you to follow the convention of naming your test suite (not test) *DeathTest when it
 * contains a death test..."
 *
 * Type  | Test Name               | Description
 * :---- | :---------------------- | :---------
 * Death | LessThanZeroCausesDeath | Verify program exits on less than zero
 *
 */
namespace DeathTests {

    ////////////////////////////////////////////////////////////
    // Constants

    const int NEGATIVE_ONE_8BIT = 255;

    /**
     * Exits the program if a `double` less than zero is passed in.
     *
     * @param num
     * @return square root
     */
    double square_root(double num) {
        if (num < 0.0) {
            std::cerr << "Error: Negative Input\n";
            exit(-1);
        }
        return sqrt(num);
    }

    /**
     * Validate that `DeathTests::square_root()` dies with the proper exit code and message when a number less than
     * zero is passed in.
     *
     * In the `EXPECT_EXIT` example it tests for an exit code of 255 because in UNIX/POSIX, the exit code of a program
     * is defined to be an unsigned 8-bit value. Converting -1 to unsigned 8-bit gives 255.
     */
    TEST (MyDeathTest, LessThanZeroCausesDeath) {
        EXPECT_DEATH(DeathTests::square_root(-1.0), "Error: Negative Input");
        EXPECT_EXIT(DeathTests::square_root(-22.0), testing::ExitedWithCode(DeathTests::NEGATIVE_ONE_8BIT),
                    "Error: Negative Input");
    }
}
