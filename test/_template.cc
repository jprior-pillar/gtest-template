#include "gtest/gtest.h"

/**\file _template.cc
 *
 * \test Google Test Template
 *
 * Provide an overview of the types of tests that are included in the test suite
 *
 * Type               | Test Name       | Description
 * :----------------  | :-------------- | :---------
 * Positive           | Positive        | Validate expected input
 * Negative           | Negative        | Validate inputs outside of expectations
 * Positive           | PositiveFixture | Validate expected input using Test Fixture
 * Exception          | Exception       | Validate system throwing proper exceptions
 * Death              | Death           | Verify proper shutdown on system failure
 * Parameterized      | Param           | Series of tests of a specific type parameterized
 *
 * ### TODO: Technical Debt
 *
 * List any examples of technical debt within the test code, or system under test.
 */
namespace TemplateTests {
    ////////////////////////////////////////////////////////////
    // Constants

    const int constantInteger = 1;

    ////////////////////////////////////////////////////////////
    // Test Fixtures
    class TemplateTestFixture : public testing::Test {
    protected:
        void SetUp() override {

        }

        virtual void TearDown() override {

        }

        static int HelperFunction(int n) {
            return n + 1;
        }
    };

    TEST(TemplateTest, Positive) {
        EXPECT_EQ(constantInteger, 1);
    }

    TEST(TemplateTest, Negative) {
        EXPECT_NE(1, 2);
    }

    // Test using a test fixture need to be in their own test suite.
    TEST_F(TemplateTestFixture, PositiveFixture) {
        EXPECT_EQ(2, HelperFunction(1));
    }
}
