#include <gtest.h>
#include "RPN.h"

TEST(String, can_create)
{
	char str[15] = "this is string";
	ASSERT_NO_THROW(TString S(str));
}

TEST(String, can_get_length)
{
	TString S("this is string too");
	ASSERT_TRUE(S.GetLength() == 19);
}

TEST(String, can_copy)
{
	TString S("this is string");
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
	TString S("this is string");
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
	TString S1("This is string");
	TString S2("And it's too");
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
	TString S = "25+54+87";
	ASSERT_EQ(Result(S), 166);
}

TEST(RPN, can_subtrack)
{
	TString S = "25-54-87";
	ASSERT_EQ(Result(S), -116);
}

TEST(RPN, can_multiplicate)
{
	TString S = "25*54*87";
	ASSERT_EQ(Result(S), 117450);
}

TEST(RPN, can_divide)
{
	TString S = "56/2/7";
	ASSERT_EQ(Result(S), 4);
}

TEST(RPN, can_translate_to_RPN_without_parentheses_and_muli_digit_numbers)
{
	TString S1("3*2*6-5*8-6+8*7");
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
	TString S1("3*2*6-5*8-6+8*7");
	TQueue<char> Q(3 * S1.GetLength());
	Q = StrToRPN(S1);
	double res = Calculate(Q);
	ASSERT_EQ(res, 46);
}

TEST(RPN, can_translate_to_RPN_with_parentheses_and_muli_digit_numbers)
{
	TString S1("(32*6-5)*((82-64)+85)*7");
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
	TString S1("(32*6-5)*((82-64)+85)*7");
	TQueue<char> Q(3 * S1.GetLength());
	Q = StrToRPN(S1);
	double res = Calculate(Q);
	ASSERT_EQ(res, 134827);
}

TEST(RPN, can_spot_incorrect_parentheses)
{
	TString S1("(32*6-5*((82-64)+85)*7");
	ASSERT_ANY_THROW(Result(S1));
}

TEST(RPN, can_spot_incorrect_operators)
{
	TString S1("(32*6-+5)*((82-64)+85)*7");
	ASSERT_ANY_THROW(Result(S1));
}

TEST(RPN, can_result_if_first_symbol_is_minus)
{
	TString S1("-(32*6-5)*((82-64)+85)*7");
	ASSERT_EQ(Result(S1), -134827);
}


