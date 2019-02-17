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
	TQueue<char> queue(str.GetLength() * 3); //��������� ������ "� �������, �.�. ������ �������������� �������, ��� ������������� �����"
	TStack<char> stack(str.GetLength() * 3);
	for (int i = 0; i < str.GetLength(); i++)
	{
		if (i == 0)
		{
			if (str[0] == '-') //��������� �������� ������
			{
				queue.Put('[');
				queue.Put('0');
				queue.Put(']');
			}
			else
				if (IsOperation(str[0]))
					if ((GetPrior(str[0]) != 1)) //������ ��������� ����� ���� ������ ������
						throw TException("Incorrect first symbol", "RPN.cpp", "StrToRPN", 1);
		}
		if (isdigit(str[i]))//���� ���������� �� �����
		{
			queue.Put('['); //������������ ��� �����
			while ((i < str.GetLength()) && isdigit(str[i + 1]))
			{
				queue.Put(str[i]); //���������� ����� ����� � �������
				i++;
			}
			queue.Put(str[i]); //��������� ����� �����
			queue.Put(']'); //������������ ��� �����
		}
		else //���� ������� ������ ��������
			if (stack.IsEmpty() && IsOperation(str[i]))//���� ���� ������
			{
				stack.Put(str[i]);
				if (str[i] == '(')
					openCounter++;
				if (str[i] == ')')
					throw TException("Incorrect use of '(' and ')'", "RPN.cpp", "StrToRPN", 2);
			}
			else //���� ���� �� ������
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
								queue.Put(stack.Get()); //�������� �� ����� ��������� � �������
							stack.Get(); //����������� ����������� ������ �� �����
						}
						else //���� ������� �������� �� '(' ��� ')', ��
						{
							int p = GetPrior(str[i]);
							if (p > GetPrior(stack.Top()))
								stack.Put(str[i]);
							else
								if (p <= GetPrior(stack.Top()))
								{
									while (!stack.IsEmpty() && p <= GetPrior(stack.Top()))
										queue.Put(stack.Get()); //���� ��������� ��������� �������� �� ������, ��� � ��������� � ����� ��������, �� ��������� �� � �������
									stack.Put(str[i]); //��������� �������� � ���� ��������
								}
						}
				}
				else //���� �� ����� � �� ��������, �� �������� �� ����� ������, ����� "�����"
					if (str[i] != '\0')
						throw TException("The line incorrect.");
	} //����� ����� for, ���������� ��� ������� ������
	while (!stack.IsEmpty())
		queue.Put(stack.Get()); //��������, ���������� � �����, ��������� � �������
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
				tmp = tmp * 10 + std::atof(&element); //�������� �����
			}
			queue.Get(); //����������� ����������� ������
			stack.Put(tmp); //���������� ����� � ����
		}
		else
			if (IsOperation(element))
			{
				double rightOperand = stack.Get(); //������� ������� ������ �������, �.�. � ���� �� ����� ����� ������
				double leftOperand = stack.Get(); //����� �����
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
