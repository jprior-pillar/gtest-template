#include "my_string.h"

#include "gtest/gtest.h"

/**\file my_string_test.cc
 *
 * \test MyString Test Suite
 *
 * Type     | Test                   | Description
 * :------- | :-------               | :---------
 * Negative | DefaultConstructor     | c_string() returns NULL by default
 * Positive | ConstructorFromCString | Verifies that the constructor accepts a C string
 * Positive | CopyConstructor        | Verifies the copy constructor
 * Positive | SetSimple              | Tests the Set method
 * Positive | SetSame                | Tests the Set method using pointer to same input already in object
 * Negative | SetNullPtr             | Tests the Set method with a nullptr
 */
namespace MyStringTests {
    ////////////////////////////////////////////////////////////
    // Constants
    const char kHelloString[] = "Hello, world!";

    TEST(MyString, DefaultConstructor) {
        const MyString s;

        EXPECT_STREQ(nullptr, s.c_string());
        EXPECT_EQ(0u, s.Length());
    }

    TEST(MyString, ConstructorFromCString) {
        const MyString s(kHelloString);

        EXPECT_EQ(0, strcmp(s.c_string(), kHelloString));
        EXPECT_EQ(sizeof(kHelloString) / sizeof(kHelloString[0]) - 1, s.Length());
    }

    TEST(MyString, CopyConstructor) {
        const MyString s1(kHelloString);

        const MyString s2 = s1;

        EXPECT_EQ(0, strcmp(s2.c_string(), kHelloString));
    }

    TEST(MyString, SetSimple) {
        MyString s;

        s.Set(kHelloString);

        EXPECT_EQ(0, strcmp(s.c_string(), kHelloString));
    }

    TEST(MyString, SetSame) {
        MyString s;
        s.Set(kHelloString);
        EXPECT_EQ(0, strcmp(s.c_string(), kHelloString));

        s.Set(s.c_string());

        EXPECT_EQ(0, strcmp(s.c_string(), kHelloString));
    }

    TEST(MyString, SetNullPtr) {
        MyString s;

        s.Set(kHelloString);
        s.Set(nullptr);

        EXPECT_STREQ(nullptr, s.c_string());
    }
}
