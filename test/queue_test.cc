#include "../src/queue.cc"
#include "gtest/gtest.h"

/**\file queue_test.cc
 *
 * \test Google Test Example with a Test Fixture
 *
 * Provide an overview of the types of tests that are included in the test suite
 *
 * Type     | Test Name          | Description
 * :------- | :----------------- | :---------
 * Negative | DefaultConstructor | Validate default constructor
 * Negative | DequeueNull        | Validate returns nullptr on empty queue
 * Positive | DequeueOne         | Validate decrements and returns value on queue of 1
 * Positive | DequeueTwo         | Validate decrements and returns value on queue of 2
 * Positive | Map                | Validates Queue's Map capabilities
 */
namespace QueueTests {
    class QueueTest : public testing::Test {
    protected:
        void SetUp() override {
            q1_.Enqueue(1);
            q2_.Enqueue(2);
            q2_.Enqueue(3);
        }

        virtual void TearDown() override {
        }

        static int Double(int n) { return 2 * n; }

        void MapTester(const Queue<int>* q) {
            const Queue<int>* const new_q = q->Map(Double);

            ASSERT_EQ(q->Size(), new_q->Size());

            for (const QueueNode<int>*n1 = q->Head(), *n2 = new_q->Head();
                 n1 != nullptr; n1 = n1->next(), n2 = n2->next()) {
                EXPECT_EQ(2 * n1->element(), n2->element());
            }

            delete new_q;
        }

        // Declares the variables your tests want to use.
        Queue<int> q0_;
        Queue<int> q1_;
        Queue<int> q2_;
    };

    TEST_F(QueueTest, DefaultConstructor) {
        EXPECT_EQ(0u, q0_.Size());
    }

    TEST_F(QueueTest, DequeueNull) {
        int* n = q0_.Dequeue();

        EXPECT_TRUE(n == nullptr);
    }

    TEST_F(QueueTest, DequeueOne) {
        int* n = q1_.Dequeue();

        ASSERT_TRUE(n != nullptr);
        EXPECT_EQ(1, *n);
        EXPECT_EQ(0u, q1_.Size());
    }

    TEST_F(QueueTest, DequeueTwo) {
        int* n = q2_.Dequeue();

        ASSERT_TRUE(n != nullptr);
        EXPECT_EQ(2, *n);
        EXPECT_EQ(1u, q2_.Size());
    }

    TEST_F(QueueTest, Map) {
        MapTester(&q0_);
        MapTester(&q1_);
        MapTester(&q2_);
    }
}
