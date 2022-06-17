#include "factorial.h"
#include "gtest/gtest.h"

/**\file factorial_para_test.cc
 *
 * This is an example of taking Google's original
 * [sample 1 factorial tests](https://github.com/google/googletest/blob/main/googletest/samples/sample1_unittest.cc)
 * and rewriting them as parameterized tests.
 *
 * ## Resources:
 *
 * * Advanced googletest Topics > [ How to Write Value-Parameterized Tests](https://github.com/google/googletest/blob/main/docs/advanced.md#user-content-value-parameterized-tests)
 * * [Parameterized testing with GTest](https://www.sandordargo.com/blog/2019/04/24/parameterized-testing-with-gtest)
 */

/**
 * \test Factorial_Param_Tests Test Suite
 *
 * Type               | Test Name                    | Description
 * :----------------  | :--------------------------- | :---------
 * Parameterized      | Factorial_Param_Test         | Parameterized positive boundary tests
 * Parameterized      | Factorial_ParamNegative_Test | Parameterized negative boundary tests
 */
namespace Factorial_Param_Tests {
    class Factorial_Param_Test : public ::testing::TestWithParam<std::tuple<int, int>> {
    };

    class Factorial_ParamNegative_Test : public ::testing::TestWithParam<int> {
    };

    TEST_P(Factorial_Param_Test, Param_Positive) {
        int expected = std::get<0>(GetParam());
        int i = std::get<1>(GetParam());

        EXPECT_EQ(expected, Factorial(i));
    }

    INSTANTIATE_TEST_SUITE_P(Factorial_Param_Test_Instantiate,
                             Factorial_Param_Test,
                             testing::Values(
                                     std::make_tuple(1, 1),
                                     std::make_tuple(2, 2),
                                     std::make_tuple(6, 3),
                                     std::make_tuple(40320, 8)
                             ));

    TEST_P(Factorial_ParamNegative_Test, Param_Negative) {
        EXPECT_EQ(1, Factorial(GetParam()));
    }

    INSTANTIATE_TEST_SUITE_P(Factorial_ParamNegative_Test_Instantiate,
                             Factorial_ParamNegative_Test,
                             testing::Values(-5, -1, 0, 1));
}

/**
 *
 * \test IsPrime_Param_Tests Test Suite
 *
 * Type               | Test Name                  | Description
 * :----------------  | :------------------------- | :---------
 * Parameterized      | IsPrime_Param_Test         | Parameterized positive boundary tests
 * Parameterized      | IsPrime_ParamNegative_Test | Parameterized negative boundary tests
 */
namespace IsPrime_Param_Tests {
    class IsPrime_Param_Test : public ::testing::TestWithParam<int> {
    };

    class IsPrime_ParamNegative_Test : public ::testing::TestWithParam<int> {
    };

    TEST_P(IsPrime_Param_Test, Positive) {
        EXPECT_TRUE(IsPrime(GetParam()));
    }

    INSTANTIATE_TEST_SUITE_P(IsPrime_Param_Test_Instantiate,
                             IsPrime_Param_Test,
                             testing::Values(2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71,
                                             73, 79, 83, 89, 97));

    TEST_P(IsPrime_ParamNegative_Test, Negative) {
        EXPECT_FALSE(IsPrime(GetParam()));
    }

    INSTANTIATE_TEST_SUITE_P(IsPrime_ParamNegative_Test_Instantiate,
                             IsPrime_ParamNegative_Test,
                             testing::Values(INT_MIN, -1, -2, 0, 1, 4, 6));
}
