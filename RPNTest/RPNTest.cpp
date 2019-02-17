#include <gtest.h>
#include "RPN.h"

TEST(String, can_create)
{
	char str[15] = "this is string";
	ASSERT_NO_THROW(TString S(str));
}
