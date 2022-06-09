# NEATO Unit Test Coding Template

## Setup

```
$> sudo apt get doxygen
```

### Documentation

Documentation is created in Use [doxygen](https://www.doxygen.nl/). To generate
the commands, simply install it and run the `doxygen` command.

## Getting Started

```
$> cmake -S . -B build
$> cmake --build build
$> cd build
$build> make test
```

These commands are in the `run` shell script for convenience. 

## Template

```c++
namespace Tests {
    class TemplateTestFixture : public testing::Test {
 protected:  
  void SetUp() override {
    
  }
  
  virtual void TearDown() {
  
  }

  // A helper function that some test uses.
  static int HelperFunction(int n) { return 2 * n; }

  // A helper function for testing Queue::Map().
  void MapTester(const Queue<int>* q) {
    // Creates a new queue, where each element is twice as big as the
    // corresponding one in q.
    const Queue<int>* const new_q = q->Map(Double);

    // Verifies that the new queue has the same size as q.
    ASSERT_EQ(q->Size(), new_q->Size());

    // Verifies the relationship between the elements of the two queues.
    for (const QueueNode<int>*n1 = q->Head(), *n2 = new_q->Head();
         n1 != nullptr; n1 = n1->next(), n2 = n2->next()) {
      EXPECT_EQ(2 * n1->element(), n2->element());
    }

    delete new_q;
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

* Positive - Does it handle expected input correctly
* Negative - Does it handle handle negative input correctly
  * Exception - Does it throw the correct exception
  * Trip

### Given-When-Then 

Organizing your tests in a Given-When-Then (GWT) format, is one of the easiest way to make sure that your tests are 
easy to follow and well organized. From [Wikipedia](https://en.wikipedia.org/wiki/Given-When-Then):

* **Given** describes the preconditions and initial state before the start of a test and allows for any pre-test setup that may occur. 
* **When** describes actions taken by a user during a test. 
* **Then** describes the outcome resulting from actions taken in the **When** clause.

#### Structuring Individual Tests



### Test-Driving

The concept of test-driving is central to the craft of TDD. 

## Examples in Neato Code

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
