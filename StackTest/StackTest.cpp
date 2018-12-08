#include <gtest.h>
#include"Stack.h"

TEST(Stack, can_create) {
	ASSERT_NO_THROW(TStack<double> S(5));
}

TEST(Stack, can_not_create_with_negative_length) {
	ASSERT_ANY_THROW(TStack<double> S(-5));
}

TEST(Stack, IsFull_is_work) {
	TStack<double> S(5);
	S.Put(5);
	S.Put(5);
	S.Put(5);
	S.Put(5);
	S.Put(5);
	ASSERT_TRUE(S.IsFull());
}

TEST(Stack, IsEmpty_is_work) {
	TStack<double> S(5);
	S.Put(5);
	S.Get();
	ASSERT_TRUE(S.IsEmpty());
}

TEST(Stack, can_put_and_get) {
	TStack<double> S(5);
	S.Put(5);
	int k=S.Get();
	ASSERT_EQ(5, k);
}

TEST(Stack, can_not_put_in_full_stack) {
	TStack<double> S(5);
	S.Put(5);
	S.Put(5);
	S.Put(5);
	S.Put(5);
	S.Put(5);
	ASSERT_ANY_THROW(S.Put(5));
}
TEST(Stack, can_not_get_from_empty_stack) {
	TStack<double> S(5);
	S.Put(5);
	S.Get();
	ASSERT_ANY_THROW(S.Get());
}
