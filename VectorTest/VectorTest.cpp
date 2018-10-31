#include "Vector.h"
#include <gtest.h.>

TEST(Vector, can_create_vector_with_negative_length)
{
	ASSERT_ANY_THROW(TVector <double> V(-1));
}
