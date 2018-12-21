#include "MStack.h"
#include <gtest.h>

TEST(MulitStack, can_create_MS)
{
	ASSERT_NO_THROW(TMStack<int> MS(20, 5));
}

TEST(MultiStack, can_not_create_MS_with_negative_size)
{
	ASSERT_ANY_THROW(TMStack<int> MS(-5, 5));
}

TEST(MultiStack, can_not_create_MS_with_negative_Stack_number)
{
	ASSERT_ANY_THROW(TMStack<int> MS(5, -5));
}

TEST(MultiStack, can_put_and_get_at_MS_with_one_stack)
{
	TMStack<int> MS(1, 5);
	MS.Put(0, 3);
	ASSERT_EQ(MS.Get(0), 3);
}

TEST(MultiStack, IsFull_is_correct_for_MS_with_one_stack)
{
	TMStack<int> MS(1, 5);
	MS.Put(0, 3);
	MS.Put(0, 3);
	MS.Put(0, 3);
	MS.Put(0, 3);
	MS.Put(0, 3);
	ASSERT_TRUE(MS.IsFull(0));
}

TEST(MultiStack, IsEmpty_is_correct_for_MS_with_one_stack)
{
	TMStack<int> MS(1, 5);
	MS.Put(0, 3);
	MS.Put(0, 3);
	MS.Get(0);
	MS.Get(0);
	ASSERT_TRUE(MS.IsEmpty(0));
}


TEST(MultiStack, can_put_and_get_at_MS_with_some_stack)
{
	TMStack<int> MS(5, 5);
	MS.Put(0, 0);
	MS.Put(1, 1);
	MS.Put(2, 2);
	MS.Put(3, 3);
	MS.Put(4, 4);
	ASSERT_EQ(MS.Get(3), 3);
}

TEST(MultiStack, IsFull_is_correct_for_MS_with_some_stack)
{
	TMStack<int> MS(5, 5);
	MS.Put(0, 3);
	MS.Put(1, 3);
	MS.Put(2, 3);
	MS.Put(3, 3);
	MS.Put(4, 3);
	ASSERT_TRUE(MS.IsFull(0));
}

TEST(MultiStack, IsEmpty_is_correct_for_MS_with_some_stack)
{
	TMStack<int> MS(5, 5);
	MS.Put(0, 3);
	MS.Put(1, 3);
	MS.Put(2, 3);
	MS.Put(3, 3);
	MS.Put(4, 3);
	MS.Get(0);
	MS.Get(1);
	MS.Get(2);
	MS.Get(3);
	MS.Get(4);
	ASSERT_TRUE(MS.IsEmpty(0));
}

TEST(MultiStack, repack_for_2_stacks)
{
	TMStack<int> MS(2, 5);
	MS.Put(0, 1);
	MS.Put(0, 2);
	MS.Put(0, 3);
	ASSERT_NO_THROW(MS.Put(0, 4));
}

TEST(MultiStack, repark_for_many_stacks)
{
	TMStack<int> MS(6, 12);
	MS.Put(0, 1);
	MS.Put(0, 2);
	MS.Put(0, 3);
	MS.Put(1, 4);
	MS.Put(1, 5);
	MS.Put(1, 6);
	MS.Put(2, 7);
	MS.Put(2, 8);
	MS.Put(2, 9);
	MS.Put(1, 10);
	MS.Put(1, 11);
	MS.Put(1, 12);
	ASSERT_EQ(MS.GetFreeMem(), 0);
	ASSERT_EQ(MS.Get(1), 12);
	ASSERT_EQ(MS.Get(1), 11);
	ASSERT_EQ(MS.Get(1), 10);
	ASSERT_EQ(MS.Get(1), 6);
	ASSERT_EQ(MS.Get(1), 5);
	ASSERT_EQ(MS.Get(1), 4);
	ASSERT_EQ(MS.Get(2), 9);
	ASSERT_EQ(MS.Get(2), 8);
	ASSERT_EQ(MS.Get(2), 7);
	ASSERT_EQ(MS.Get(0), 3);
	ASSERT_EQ(MS.Get(0), 2);
	ASSERT_EQ(MS.Get(0), 1);
	ASSERT_EQ(MS.GetFreeMem(), 12);

}
