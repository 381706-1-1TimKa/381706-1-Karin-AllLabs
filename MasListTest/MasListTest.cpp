#include <gtest.h>
#include "MasList.h"

TEST(MasList, can_create_MasList)
{
	ASSERT_NO_THROW(TMasList<int> A(5));
}

TEST(MasList, can_not_create_with_negative_size)
{
	ASSERT_ANY_THROW(TMasList<int> B(-5));
}

TEST(MasList, can_put_element_in_start)
{
	TMasList<int> A(5);
	ASSERT_NO_THROW(A.PushStart(10));
}

TEST(MasList, can_get_first_element)
{
	TMasList<int> A(5);
	A.PushStart(10);
	A.PushStart(11);
	A.PushStart(12);
	ASSERT_EQ(A.PullStart(), 12);
	ASSERT_EQ(A.PullStart(), 11);
	ASSERT_EQ(A.PullStart(), 10);
}

TEST(MasList, can_put_element_in_finish)
{
	TMasList<int> A(5);
	ASSERT_NO_THROW(A.PushFinish(10));
}

TEST(MasList, can_get_last_element)
{
	TMasList<int> A(5);
	A.PushFinish(6);
	ASSERT_EQ(A.PullFinish(), 6);
}

TEST(MasList, check_for_emptyness)
{
	TMasList<int> A(5);
	ASSERT_TRUE(A.IsEmpty());
}

TEST(MasList, check_for_fullness)
{
	TMasList<int> A(5);
	A.PushFinish(1);
	A.PushFinish(2);
	A.PushStart(3);
	A.PushStart(4);
	A.PushFinish(5);
	ASSERT_TRUE(A.IsFull());
}

TEST(MasList, check_for_fullness_for_double)
{
	TMasList<double> A(5);
	A.PushFinish(1.1);
	A.PushFinish(2.1);
	A.PushStart(3.1);
	A.PushStart(4.1);
	A.PushFinish(5.1);
	ASSERT_TRUE(A.IsFull());
}