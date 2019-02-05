#include "Vector.h"
#include <gtest.h>

TEST(Vector, can_create_vector_with_negative_length)
{
	ASSERT_ANY_THROW(TVector <double> V(-1));
}

TEST(Vector, can_create_vector_with_positive_length)
{
	ASSERT_NO_THROW(TVector <double> V(5));
}

TEST(Vector, can_get_Elem)
{
	TVector<double> V(3);
	V[2] = 45.23;
	ASSERT_EQ(V[2], 45.23);
}

TEST(Vector, can_compare) {
	TVector<double> V1(3), V2(3);
	for (int i = 0; i < 3; i++) {
		V1[i] = i;
		V2[i] = i;
	}
	ASSERT_TRUE(V1 == V2);
}

TEST(Vector, can_plus) {
	TVector<int> V1(3), V2(3), V3(3);
	for (int i = 0; i < 3; i++) {
		V1[i] = i;
		V2[i] = i;
		V3[i] = 2*i;
	}
	ASSERT_TRUE((V1+V2)==V3);
}

TEST(Vector, can_not_plus_different_length) {
	TVector<int> V1(3), V2(4);
	ASSERT_ANY_THROW(V1+V2);
}

TEST(Vector, can_minus) {
	TVector<int> V1(3), V2(3), V3(3);
	for (int i = 0; i < 3; i++) {
		V1[i] = i;
		V2[i] = i;
	}
	ASSERT_TRUE((V1 - V2) == V3);
}

TEST(Vector, can_not_minus_different_length) {
	TVector<int> V1(3), V2(4);
	ASSERT_ANY_THROW(V1 - V2);
}

TEST(Vector, can_skalar_multiplicate) {
	TVector<int> V1(3), V2(3), V3(3);
	for (int i = 0; i < 3; i++) {
		V1[i] = i;
		V2[i] = i;
	}
	ASSERT_EQ(V1*V2, 5);
}

