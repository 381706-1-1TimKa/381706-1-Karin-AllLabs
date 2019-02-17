#include "RPN.h"
#include "../Exception/Exception.h"
#include <cstdlib>

int GetPrior(const char c)
{
	switch (c)
	{
	case '(':
		return 1;
	case ')':
		return 1;
	case '+':
		return 2;
	case '-':
		return 2;
	case '*':
		return 3;
	case '/':
		return 3;
	default:
		throw TException("Unknown operator", "RPN.cpp", "GetPrior", 1);
	}
}

bool IsOperation(char c)
{
	return ((c == '+') || (c == '-') || (c == '*') || (c == '/') || (c == '(') || (c == ')'));
}

TQueue<char> StrToRPN(TString str)
{
	int openCounter = 0, closeCounter = 0;
	TQueue<char> queue(str.GetLength() * 3); //выделение памяти "с запасом, т.к. вводим дополнительные символы, для разграничения чисел"
	TStack<char> stack(str.GetLength() * 3);
	for (int i = 0; i < str.GetLength(); i++)
	{
		if (i == 0)
		{
			if (str[0] == '-') //обработка унарного минуса
			{
				queue.Put('[');
				queue.Put('0');
				queue.Put(']');
			}
			else
				if (IsOperation(str[0]))
					if ((GetPrior(str[0]) != 1)) //первой операцией может быть только скобка
						throw TException("Incorrect first symbol", "RPN.cpp", "StrToRPN", 1);
		}
		if (isdigit(str[i]))//если наткнулись на число
		{
			queue.Put('['); //ограничитель для числа
			while ((i < str.GetLength()) && isdigit(str[i + 1]))
			{
				queue.Put(str[i]); //запихиваем цифры числа в очередь
				i++;
			}
			queue.Put(str[i]); //последняя цифра числа
			queue.Put(']'); //ограничитель для числа
		}
		else //если попался символ операции
			if (stack.IsEmpty() && IsOperation(str[i]))//если стек пустой
			{
				stack.Put(str[i]);
				if (str[i] == '(')
					openCounter++;
				if (str[i] == ')')
					throw TException("Incorrect use of '(' and ')'", "RPN.cpp", "StrToRPN", 2);
			}
			else //если стек не пустой
				if (IsOperation(str[i]))
				{
					if (str[i] == '(')
					{
						stack.Put(str[i]);
						openCounter++;
					}
					else
						if (str[i] == ')')
						{
							closeCounter++;
							while (stack.Top() != '(')
								queue.Put(stack.Get()); //операции из стека переносим в очередь
							stack.Get(); //вытаскиваем открывающую скобку из стека
						}
						else //если текущая операция не '(' или ')', то
						{
							int p = GetPrior(str[i]);
							if (p > GetPrior(stack.Top()))
								stack.Put(str[i]);
							else
								if (p <= GetPrior(stack.Top()))
								{
									while (!stack.IsEmpty() && p <= GetPrior(stack.Top()))
										queue.Put(stack.Get()); //если приоритет очередной операции не больше, чем у последней в стеке операций, то переносим их в очередь
									stack.Put(str[i]); //очередную операцию в стек операций
								}
						}
				}
				else //если не число и не операция, то проверка на конец строки, иначе "мусор"
					if (str[i] != '\0')
						throw TException("The line incorrect.");
	} //конец цикла for, обработана вся входная строка
	while (!stack.IsEmpty())
		queue.Put(stack.Get()); //операции, оставшиеся в стеке, переносим в очередь
	if (openCounter != closeCounter)
		throw TException("The number of open and closed brackets does not match.");
	return queue;
}

double Calculate(TQueue<char> queue)
{
	double result = 0;
	TStack<double> stack(queue.GetSize());
	if (IsOperation(queue.Top()))
		throw TException("Incorrect string", "RPN.cpp", "Calculate", 3);
	while (!queue.IsEmpty())
	{
		char element = queue.Get();
		if (element == '[')
		{
			element = queue.Get();
			double tmp = std::atof(&element);
			while (queue.Top() != ']' && !queue.IsEmpty())
			{
				element = queue.Get();
				tmp = tmp * 10 + std::atof(&element); //собираем число
			}
			queue.Get(); //вытаскиваем закрывающую скобку
			stack.Put(tmp); //полученное число в стек
		}
		else
			if (IsOperation(element))
			{
				double rightOperand = stack.Get(); //достаем сначала правый операнд, т.к. в стек он попал позже левого
				double leftOperand = stack.Get(); //затем левый
				double res = 0;
				if (element == '+')
					res = leftOperand + rightOperand;
				if (element == '-')
					res = leftOperand - rightOperand;
				if (element == '*')
					res = leftOperand * rightOperand;
				if (element == '/')
					res = leftOperand / rightOperand;
				stack.Put(res);
			}
			else
				throw TException("Incorrect string", "RPN.cpp", "Calculate", 3);
	}
	result = stack.Get();
	if (!stack.IsEmpty())
		throw TException("Incorrect string", "RPN.cpp", "Calculate", 3);
	return result;
}

double Result(TString& A)
{
	TQueue<char> q(3 * A.GetLength());
	q = StrToRPN(A);
	double res;
	res = Calculate(q);
	return res;
}
