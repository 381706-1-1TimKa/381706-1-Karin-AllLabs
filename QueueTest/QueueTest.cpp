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
	A.Put(7);
	A.Put(8);
	ASSERT_EQ(7, A.Get());
	ASSERT_EQ(8, A.Get());
}


TEST(Queue, can_recognize_Full_Queue) {
	TQueue<int> A(5);
	A.Put(1);
	A.Put(2);
	A.Put(3);
	A.Put(4);
	A.Put(5);
	ASSERT_ANY_THROW(A.Put(6));
}

TEST(Queue, can_recognize_Empty_Queue) {
	TQueue<int> A(5);
	A.Put(1);
	A.Put(2);
	A.Put(3);
	A.Get();
	A.Get();
	A.Get();
	ASSERT_ANY_THROW(A.Get());
}

TEST(Queue, can_write_many_cycles) {
	TQueue<int> A(5);
	A.Put(1);
	A.Put(2);
	A.Put(3);
	A.Get();
	A.Get();
	A.Put(5);
	A.Put(7);
	A.Get();
	A.Get();
	A.Put(8);
	A.Put(9);
	A.Put(10);
	A.Put(11);
	A.Get();
	A.Get();
	A.Get();
	int S = A.Get();
	ASSERT_EQ(S, 10);
}
