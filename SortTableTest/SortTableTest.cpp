#include "SortTable.h"
#include <gtest.h>

TEST(SortElem, can_create)
{
	ASSERT_NO_THROW(TSortElem<int> A("key", 12));
}

TEST(SortElem, can_compare)
{
	TSortElem<int> A("key", 12);
	TSortElem<int> B("abc", 13);
	TSortElem<int> C("abcd", 13);
	TSortElem<int> D("key", 15);
	ASSERT_TRUE(A > B);
	ASSERT_TRUE(C < B);
	ASSERT_TRUE(A == D);
}

TEST(SortTable, can_create_with_int_parametr)
{
	ASSERT_NO_THROW(TSortTable<int> ST(20));
}

TEST(SortTable, can_not_create_with_negative_size)
{
	ASSERT_ANY_THROW(TSortTable<int> ST(-20));
}

TEST(SortTable, can_create_with_array_parametr)
{
	int p[] = { 1, 2, 3, 4, 5 };
	TString S[] = { "a", "b", "c", "d", "e" };
	ASSERT_NO_THROW(TSortTable<int> ST(S, p, 5, 1));
}

TEST(SortTable, Bubble_sort_is_right)
{
	int p[] = { 1, 2, 3, 4, 5 };
	TString S[] = { "one", "two", "three", "four", "five" };
	TSortTable<int> ST(S, p, 5, 1);
	ASSERT_TRUE(ST[0].GetKey() == (TString)"five");
	ASSERT_TRUE(ST[1].GetKey() == (TString)"four");
	ASSERT_TRUE(ST[2].GetKey() == (TString)"one");
	ASSERT_TRUE(ST[3].GetKey() == (TString)"three");
	ASSERT_TRUE(ST[4].GetKey() == (TString)"two");
}

TEST(SortTable, Insert_sort_is_right)
{
	int p[] = { 1, 2, 3, 4, 5 };
	TString S[] = { "one", "two", "three", "four", "five" };
	TSortTable<int> ST(S, p, 5, 2);
	ASSERT_TRUE(ST[0].GetKey() == (TString)"five");
	ASSERT_TRUE(ST[1].GetKey() == (TString)"four");
	ASSERT_TRUE(ST[2].GetKey() == (TString)"one");
	ASSERT_TRUE(ST[3].GetKey() == (TString)"three");
	ASSERT_TRUE(ST[4].GetKey() == (TString)"two");
}

TEST(SortTable, Quick_sort_is_right)
{
	int p[] = { 1, 2, 3, 4, 5 };
	TString S[] = { "one", "two", "three", "four", "five" };
	TSortTable<int> ST(S, p, 5, 3);
	ASSERT_TRUE(ST[0].GetKey() == (TString)"five");
	ASSERT_TRUE(ST[1].GetKey() == (TString)"four");
	ASSERT_TRUE(ST[2].GetKey() == (TString)"one");
	ASSERT_TRUE(ST[3].GetKey() == (TString)"three");
	ASSERT_TRUE(ST[4].GetKey() == (TString)"two");
}

TEST(SortTable, can_put_and_get)
{
	TSortTable<int> ST(10);
	ST.Put("i", 1);
	ST.Put("like", 2);
	ST.Put("write", 3);
	ST.Put("code", 4);
	ASSERT_TRUE(ST["code"].GetData() == 4);
	ASSERT_TRUE(ST["i"].GetData() == 1);
	ASSERT_TRUE(ST["like"].GetData() == 2);
	ASSERT_TRUE(ST["write"].GetData() == 3);
}

TEST(SortTable, can_sort)
{
	TSortTable<int> ST(10);
	ST.Put("i", 1);
	ST.Put("like", 2);
	ST.Put("write", 3);
	ST.Put("code", 4);
	ASSERT_TRUE(ST[0].GetData() == 4);
	ASSERT_TRUE(ST[1].GetData() == 1);
	ASSERT_TRUE(ST[2].GetData() == 2);
	ASSERT_TRUE(ST[3].GetData() == 3);
}


TEST(SortTable, can_resize)
{
	TSortTable<int> ST(2);
	ST.Put("i", 1);
	ST.Put("like", 2);
	ST.Put("write", 3);
	ST.Put("code", 4);
	ASSERT_TRUE(ST["code"].GetData() == 4);
	ASSERT_TRUE(ST["i"].GetData() == 1);
	ASSERT_TRUE(ST["like"].GetData() == 2);
	ASSERT_TRUE(ST["write"].GetData() == 3);
	ASSERT_EQ(ST.GetCount(), 4);
}

TEST(SortTable, can_delete)
{
	TSortTable<int> ST(2);
	ST.Put("i", 1);
	ST.Put("like", 2);
	ST.Put("write", 3);
	ST.Put("code", 4);
	ASSERT_NO_THROW(ST.Del("i"));
	ASSERT_NO_THROW(ST.Del("write"));
	ASSERT_TRUE(ST["code"].GetData() == 4);
	ASSERT_ANY_THROW(ST["i"].GetData() == 1);
	ASSERT_TRUE(ST["like"].GetData() == 2);
	ASSERT_ANY_THROW(ST["write"].GetData() == 3);
	ASSERT_EQ(ST.GetCount(), 2);

	ASSERT_NO_THROW(ST.Del("like"));
	ASSERT_NO_THROW(ST.Del("code"));
}

TEST(SortTable, can_find)
{
	TSortTable<int> ST(10);
	ST.Put("i", 1);
	ST.Put("like", 2);
	ST.Put("write", 3);
	ST.Put("code", 4);

	TSortElem<int> A=ST.Search("i");
	ASSERT_TRUE(A.GetData() == 1);
	ASSERT_TRUE(A.GetKey() == (TString)"i");
	
	TSortElem<int> B = ST.Search("code");
	ASSERT_TRUE(B.GetData() == 4);
	ASSERT_TRUE(B.GetKey() == (TString)"code");
}

TEST(SortTable, can_not_find_not_exist)
{
	TSortTable<int> ST(10);
	ST.Put("i", 1);
	ST.Put("like", 2);
	ST.Put("write", 3);
	ST.Put("code", 4);
	ASSERT_TRUE(ST.Search("don't") == ST.not_find);
}