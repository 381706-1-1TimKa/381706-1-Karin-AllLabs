#include <gtest.h>
#include"StackList.h"

TEST(StackList, can_create) {
	ASSERT_NO_THROW(TStackList<double> S);
}

TEST(StackList, copy_constructor)
{
	TStackList<int> S;
	S.Put(5);
	S.Put(6);
	S.Put(7);
	TStackList<int> A(S);
	ASSERT_EQ(A.Get(), 7);
	ASSERT_EQ(A.Get(), 6);
	ASSERT_EQ(A.Get(), 5);
}


TEST(StackList, IsEmpty_is_work) {
	TStackList<double> S;
	S.Put(5);
	S.Get();
	ASSERT_TRUE(S.IsEmpty());
}

TEST(StackList, can_put_and_get) {
	TStackList<double> S;
	S.Put(5);
	int k = S.Get();
	ASSERT_EQ(5, k);
}

TEST(StackList, can_not_get_from_empty_stack) {
	TStackList<double> S;
	S.Put(5);
	S.Get();
	ASSERT_ANY_THROW(S.Get());
}