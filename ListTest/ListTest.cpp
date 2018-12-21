#include <gtest.h>
#include "List.h"
#include "Elem.h"
using namespace std;

TEST(Elem, can_create) 
{
	ASSERT_NO_THROW(TElem<int> A(5, 0));
}

TEST(Elem, can_copy) 
{
	TElem<int> A(5, 0);
	ASSERT_NO_THROW(TElem<int> B(A););
}

TEST(Elem, can_get_elem)
{
	TElem<int> A(5, 0);
	ASSERT_EQ(A.Get(), 5);
}

TEST(Elem, can_set_elem)
{
	TElem<int> A(5, 0);
	A.Set(10);
	ASSERT_EQ(A.Get(), 10);
}


TEST(Elem, can_get_next)
{
	TElem<int> A(5, 0);
	TElem<int> B(7, &A);
	TElem<int> C = *(B.GetNext());
	ASSERT_EQ(A.Get(), C.Get());
}

TEST(Elem, can_set_next)
{
	TElem<int> A(5, 0);
	TElem<int> B(7, 0);
	B.SetNext(&A);
	TElem<int> C = *(B.GetNext());
	ASSERT_EQ(A.Get(), C.Get());
}


TEST(List, can_create_empty_list)
{
	ASSERT_NO_THROW(TList<int> A);
}

TEST(List, can_put_begin_for_empty_list)
{
	TList<int> A;
	ASSERT_NO_THROW(A.PutBegin(3));
}

TEST(List, can_put_end_for_empty_list) 
{
	TList<int> A;
	ASSERT_NO_THROW(A.PutEnd(3));
}

TEST(List, can_get_first_for_list_with_one_elem)
{
	TList<int> A;
	A.PutBegin(3);
	ASSERT_NO_THROW(A.GetBegin(), 3);
}

TEST(List, can_get_end_for_list_with_one_elem)
{
	TList<int> A;
	A.PutEnd(3);
	ASSERT_NO_THROW(A.GetEnd(), 3);
}


TEST(List, can_put_end)
{
	TList<int> A;
	A.PutEnd(1);
	A.PutEnd(2);
	A.PutEnd(3);
	A.PutEnd(4);
	ASSERT_EQ(A.GetEnd(), 4);
}

TEST(List, can_put_and_get_first_for_list_with_many_elem)
{
	TList<int> A;
	A.PutBegin(1);
	A.PutBegin(2);
	A.PutBegin(3);
	A.PutBegin(4);
	ASSERT_EQ(A.GetBegin(), 4);
}

TEST(List, can_put_and_get_end_for_list_with_many_elem)
{
	TList<int> A;
	A.PutEnd(1);
	A.PutEnd(2);
	A.PutEnd(3);
	A.PutEnd(4);
	ASSERT_EQ(A.GetEnd(), 4);
	ASSERT_EQ(A.GetEnd(), 3);
	//ASSERT_EQ(A.GetEnd(), 2);
	//ASSERT_EQ(A.GetEnd(), 1);
}


