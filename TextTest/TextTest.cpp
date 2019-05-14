#include <gtest.h>
#include "Text.h"
#include "../TextLib/MyString.h"

TEST(Node, can_create_char)
{
	ASSERT_NO_THROW(TNode A('c'));
}

TEST(Node, can_create_string)
{
	TMyString B;
	B = "This is string";
	ASSERT_NO_THROW(TNode A(B));
}

TEST(Node, can_create_level)
{
	ASSERT_NO_THROW(TNode T1(1));
	ASSERT_NO_THROW(TNode T2(2));
	ASSERT_NO_THROW(TNode T3(3));
	ASSERT_ANY_THROW(TNode T4(4));
}

TEST(Node, can_assign)
{
	TNode A('c');
	TNode B = A;
	ASSERT_EQ(B.GetLevel(), 3);
	ASSERT_EQ(B.GetData(), 'c');
}

//TEST(Node, can_add_char)
//{
//}
//
//TEST(Node, can_add_string)
//{
//
//}

TEST(Node, to_string)
{
	TMyString S;
	S = "This is string";
	TNode A(S);
	char* C = A.ToStr();
	TMyString S2(C);
	ASSERT_TRUE(S == S2);
}

