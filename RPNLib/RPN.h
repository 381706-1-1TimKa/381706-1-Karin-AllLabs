#pragma once
#include "../RPNLib/MyString.h"
#include "Queue.h"

int GetPrior(const char c);
bool IsOperation(char c);
TQueue<char> StrToRPN(TString str);
double Calculate(TQueue<char> queue);
double Result(TString& A);


