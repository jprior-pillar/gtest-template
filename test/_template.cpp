#include "gtest/gtest.h"

namespace Tests {
    class TemplateTestFixture : public testing::Test {
    protected:
        void SetUp() override {

        }

        virtual void TearDown() override {

        }

        // A helper function that some test uses.
        // For examples of helper functions see the Queue example
        static int HelperFunction(int n) {
            return n + 1;
        }
    }
}
