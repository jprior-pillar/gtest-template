# NEATO Unit Test Coding Template

This project is designed to provide examples of best practices for arranging and documenting tests written 
with GTest.

Includes examples of 

* [Test fixtures](https://github.com/google/googletest/blob/main/docs/primer.md#user-content-test-fixtures-using-the-same-data-configuration-for-multiple-tests-same-data-multiple-tests)
* [Testing exception](https://google.github.io/googletest/reference/assertions.html#exceptions)
* [Death tests](https://github.com/google/googletest/blob/main/docs/advanced.md#user-content-death-tests)

## Getting Started

You will need [cmake](https://cmake.org/) and the ability to build and run C++ code. See the Google Test 
[Quickstart documentation](https://google.github.io/googletest/quickstart-cmake.html) for more information.

```
$> cmake -S . -B build
$> cmake --build build
$> cd build
$build> make test
```

These commands are in the `run` shell script for convenience.

## Documentation

Documentation is created in Use [doxygen](https://www.doxygen.nl/). To generate
the commands, simply install it and run the `doxygen` command.

### Setup

You will need [Doxygen](https://doxygen.nl/index.html) and [Graphviz](http://www.graphviz.org/) to generate the 
documentation.

#### Linux

```
$> sudo apt update
$> sudo apt get doxygen graphviz
$> doxygen
```

#### OSX

```
$> brew install doxygen graphviz
```

## Template

```
#include "gtest/gtest.h"

/**\file template_cc
 *
 * \test Google Test Template
 *
 * Provide an overview of the types of tests that are included in the test suite
 *
 * Type               | Test Name  | Description
 * :----------------  | :--------- | :---------
 * Positive           | Positive   | Validate expected input
 * Negative           | Negative   | Validate inputs outside of expectations
 * Exception          | Exception  | Validate system throwing proper exceptions
 * Death              | Death      | Verify proper shutdown on system failure
 * Parameterized      | Param      | Series of tests of a specific type parameterized
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
```

## Checklist

* Are the test suite names clearly show the SUT (System Under Test)?
* Have they documented the negative and positive boundary conditions?
* Are the individual tests isolated so that they are testing only one thing?
* Are the tests documented so that it is easy for someone new to the project to see what the test is testing?
  * Are the tests structured in a clear [Given-When-Then](https://martinfowler.com/bliki/GivenWhenThen.html) format?
  * If they are not, can they be?

## Glossary

### Boundary Conditions

A boundary condition is a type of test 
A test suite's boundary conditions describe the 

* Positive - Does it handle expected input correctly?
* Negative - Does it handle negative input correctly?
  * [Exception](https://github.com/google/googletest/blob/main/docs/reference/assertions.md#user-content-exception-assertions-exceptions) - Does it throw the correct exception?
  * [Death Test](https://github.com/google/googletest/blob/main/docs/advanced.md#user-content-death-tests) - Does it exit with the correct code and message?
* [Parameterized](https://github.com/google/googletest/blob/main/docs/advanced.md#user-content-value-parameterized-tests)

### Given-When-Then 

Organizing your tests in a Given-When-Then (GWT) format, is one of the easiest way to make sure that your tests are 
easy to follow and well organized. From [Wikipedia](https://en.wikipedia.org/wiki/Given-When-Then):

* **Given** describes the preconditions and initial state before the start of a test and allows for any pre-test setup that may occur. 
* **When** describes actions taken by a user during a test. 
* **Then** describes the outcome resulting from actions taken in the **When** clause.

## Resources

* Confluence
  * [Clean Unit Test Principles](https://acnforgenetwork.atlassian.net/wiki/spaces/NQFUT/pages/121157648839/Clean+Unit+Test+Principles) 
  * [Unit Test Best Practices](https://acnforgenetwork.atlassian.net/wiki/spaces/NQFUT/pages/121157386276/Unit+Test+Best+Practices)
* [CMake](https://cmake.org/)
  * [Awesome CMake](https://github.com/onqtam/awesome-cmake)
  * [CMake Cookbook](https://github.com/dev-cafe/cmake-cookbook)
  * [An Introduction to Modern CMake](https://cliutils.gitlab.io/modern-cmake/)
  * [Modern CMake for C++](https://github.com/PacktPublishing/Modern-CMake-for-Cpp)
* [Doxygen](https://doxygen.nl/index.html)
* Testing
  * Testing Frameworks
    * [GoogleTest](https://github.com/google/googletest)
    * [Boost.Test](https://github.com/boostorg/test)
    * [Catch2](https://github.com/catchorg/Catch2)
    * [doctest](https://github.com/doctest/doctest)
* [xUnit Test Patterns](http://xunitpatterns.com/index.html)
  * [Goals of Test Automation](http://xunitpatterns.com/Goals%20of%20Test%20Automation.html)
