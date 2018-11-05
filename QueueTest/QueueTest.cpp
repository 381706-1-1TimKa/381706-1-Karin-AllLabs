#include "Queue.h"
#include <gtest.h>

TEST(Queue, can_create_queue) {
	ASSERT_NO_THROW(TQueue<float> A(5));
}

TEST(Queue, can_not_create_with_negative_length) {
	ASSERT_ANY_THROW(TQueue <double> A(-5));
}

TEST(Queue, can_put_and_get) {
	TQueue<int> A(5);
	A.put(7);
	int B = A.Get();
	ASSERT_EQ(7, B);
}

TEST(Queue, can_recognize_Full_Queue) {
	TQueue<int> A(5);
	A.put(1);
	A.put(2);
	A.put(3);
	A.put(4);
	A.put(5);
	ASSERT_ANY_THROW(A.put(6));
}

TEST(Queue, can_recognize_Empty_Queue) {
	TQueue<int> A(5);
	A.put(1);
	A.put(2);
	A.put(3);
	A.Get();
	A.Get();
	A.Get();
	ASSERT_ANY_THROW(A.Get());
}

TEST(Queue, can_write_many_cycles) {
	TQueue<int> A(5);
	A.put(1);
	A.put(2);
	A.put(3);
	A.Get();
	A.Get();
	A.put(5);
	A.put(7);
	A.Get();
	A.Get();
	A.put(8);
	A.put(9);
	A.put(10);
	A.put(11);
	A.Get();
	A.Get();
	A.Get();
	int S = A.Get();
	ASSERT_EQ(S, 10);
}
