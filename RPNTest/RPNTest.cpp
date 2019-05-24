#include <gtest.h>
#include "RPN.h"

TEST(String, can_create)
{
	char str[] = "this is string";
	ASSERT_NO_THROW(TString S(str));
}

TEST(String, can_get_length)
{
	char str[] = "this is string too";
	TString S(str);
	ASSERT_TRUE(S.GetLength() == 19);
}

TEST(String, can_copy)
{
	char str[] = "this is string";
	TString S(str);
	TString Scopy(S);
	ASSERT_TRUE(S[0] == 't');
	ASSERT_TRUE(S[2] == 'i');
	ASSERT_TRUE(S[4] == ' ');
	ASSERT_TRUE(S[6] == 's');
	ASSERT_TRUE(S[8] == 's');
	ASSERT_TRUE(S[10] == 'r');
}

TEST(String, can_assign)
{
	char str[] = "this is string";
	TString S(str);
	TString S1;
	S1 = S;
	ASSERT_TRUE(S[0] == 't');
	ASSERT_TRUE(S[2] == 'i');
	ASSERT_TRUE(S[4] == ' ');
	ASSERT_TRUE(S[6] == 's');
	ASSERT_TRUE(S[8] == 's');
	ASSERT_TRUE(S[10] == 'r');
}

TEST(String, can_add)
{
	char str1[] = "This is string";
	char str2[] = "And it's too";
	TString S1(str1);
	TString S2(str2);
	TString S3;
	S3 = S1 + S2;
	ASSERT_TRUE(S3[0] == 'T');
	ASSERT_TRUE(S3[5] == 'i');
	ASSERT_TRUE(S3[10] == 'r');
	ASSERT_TRUE(S3[14] == 'A');
	ASSERT_TRUE(S3[20] == '\'');
	ASSERT_TRUE(S3[26] == '\0');
}

TEST(RPN, can_spot_operator)
{
	ASSERT_TRUE(IsOperation('+'));
	ASSERT_TRUE(IsOperation('-'));
	ASSERT_TRUE(IsOperation('/'));
	ASSERT_TRUE(IsOperation('*'));
	ASSERT_TRUE(IsOperation(')'));
	ASSERT_TRUE(IsOperation('('));
	ASSERT_FALSE(IsOperation('A'));
	ASSERT_FALSE(IsOperation('a'));
	ASSERT_FALSE(IsOperation('1'));
	ASSERT_FALSE(IsOperation(']'));
	ASSERT_FALSE(IsOperation('%'));
}

TEST(RPN, can_add)
{
	char str[] = "25+54+87";
	TString S(str);
	ASSERT_TRUE(Result(S) == 166);
}

TEST(RPN, can_subtrack)
{
	char str[] = "25-54-87";
	TString S (str);
	ASSERT_TRUE(Result(S) == -116);
}

TEST(RPN, can_multiplicate)
{
	char str[] = "25*54*87";
	TString S(str);
	ASSERT_TRUE(Result(S) == 117450);
}



TEST(RPN, can_translate_to_RPN_without_parentheses_and_muli_digit_numbers)
{
	char str[] = "3*2*6-5*8-6+8*7";
	TString S1(str);
	TQueue<char> Q(3*S1.GetLength());
	Q = StrToRPN(S1);
	ASSERT_TRUE(Q.Get() == '[');
	ASSERT_TRUE(Q.Get() == '3');
	ASSERT_TRUE(Q.Get() == ']');
	ASSERT_TRUE(Q.Get() == '[');
	ASSERT_TRUE(Q.Get() == '2');
	ASSERT_TRUE(Q.Get() == ']');
	ASSERT_TRUE(Q.Get() == '*');
	ASSERT_TRUE(Q.Get() == '[');
	ASSERT_TRUE(Q.Get() == '6');
	ASSERT_TRUE(Q.Get() == ']');
	ASSERT_TRUE(Q.Get() == '*');
	ASSERT_TRUE(Q.Get() == '[');
	ASSERT_TRUE(Q.Get() == '5');
	ASSERT_TRUE(Q.Get() == ']');
	ASSERT_TRUE(Q.Get() == '[');
	ASSERT_TRUE(Q.Get() == '8');
	ASSERT_TRUE(Q.Get() == ']');
	ASSERT_TRUE(Q.Get() == '*');
	ASSERT_TRUE(Q.Get() == '-');
	ASSERT_TRUE(Q.Get() == '[');
	ASSERT_TRUE(Q.Get() == '6');
	ASSERT_TRUE(Q.Get() == ']');
	ASSERT_TRUE(Q.Get() == '-');
	ASSERT_TRUE(Q.Get() == '[');
	ASSERT_TRUE(Q.Get() == '8');
	ASSERT_TRUE(Q.Get() == ']');
	ASSERT_TRUE(Q.Get() == '[');
	ASSERT_TRUE(Q.Get() == '7');
	ASSERT_TRUE(Q.Get() == ']');
	ASSERT_TRUE(Q.Get() == '*');
	ASSERT_TRUE(Q.Get() == '+');
	ASSERT_TRUE(Q.IsEmpty());
}

TEST(RPN, can_count_RPN_without_parentheses_and_muli_digit_numbers)
{
	char str[] = "3*2*6-5*8-6+8*7";
	TString S1(str);
	TQueue<char> Q(3 * S1.GetLength());
	Q = StrToRPN(S1);
	double res = Calculate(Q);
	ASSERT_EQ(res, 46);
}

TEST(RPN, can_translate_to_RPN_with_parentheses_and_muli_digit_numbers)
{
	char str[] = "(32*6-5)*((82-64)+85)*7";
	TString S1(str);
	TQueue<char> Q(3 * S1.GetLength());
	Q = StrToRPN(S1);
	ASSERT_TRUE(Q.Get() == '[');
	ASSERT_TRUE(Q.Get() == '3');
	ASSERT_TRUE(Q.Get() == '2');
	ASSERT_TRUE(Q.Get() == ']');
	ASSERT_TRUE(Q.Get() == '[');
	ASSERT_TRUE(Q.Get() == '6');
	ASSERT_TRUE(Q.Get() == ']');
	ASSERT_TRUE(Q.Get() == '*');
	ASSERT_TRUE(Q.Get() == '[');
	ASSERT_TRUE(Q.Get() == '5');
	ASSERT_TRUE(Q.Get() == ']');
	ASSERT_TRUE(Q.Get() == '-');
	ASSERT_TRUE(Q.Get() == '[');
	ASSERT_TRUE(Q.Get() == '8');
	ASSERT_TRUE(Q.Get() == '2');
	ASSERT_TRUE(Q.Get() == ']');
	ASSERT_TRUE(Q.Get() == '[');
	ASSERT_TRUE(Q.Get() == '6');
	ASSERT_TRUE(Q.Get() == '4');
	ASSERT_TRUE(Q.Get() == ']');
	ASSERT_TRUE(Q.Get() == '-');
	ASSERT_TRUE(Q.Get() == '[');
	ASSERT_TRUE(Q.Get() == '8');
	ASSERT_TRUE(Q.Get() == '5');
	ASSERT_TRUE(Q.Get() == ']');
	ASSERT_TRUE(Q.Get() == '+');
	ASSERT_TRUE(Q.Get() == '*');
	ASSERT_TRUE(Q.Get() == '[');
	ASSERT_TRUE(Q.Get() == '7');
	ASSERT_TRUE(Q.Get() == ']');
	ASSERT_TRUE(Q.Get() == '*');
	ASSERT_TRUE(Q.IsEmpty());
}

TEST(RPN, can_count_RPN_with_parentheses_and_muli_digit_numbers)
{
	char str[] = "(32*6-5)*((82-64)+85)*7";
	TString S1(str);
	TQueue<char> Q(3 * S1.GetLength());
	Q = StrToRPN(S1);
	double res = Calculate(Q);
	ASSERT_TRUE(res == 134827);
}

TEST(RPN, can_spot_incorrect_parentheses)
{
	char str[] = "(32*6-5*((82-64)+85)*7";
	TString S1(str);
	ASSERT_ANY_THROW(Result(S1));
}

TEST(RPN, can_spot_incorrect_operators)
{
	char str[] = "(32*6-+5)*((82-64)+85)*7";
	TString S1(str);
	ASSERT_ANY_THROW(Result(S1));
}

TEST(RPN, can_result_if_first_symbol_is_minus)
{
	char str[] = "-(32*6-5)*((82-64)+85)*7";
	TString S1(str);
	ASSERT_TRUE(Result(S1) == -134827);
}


