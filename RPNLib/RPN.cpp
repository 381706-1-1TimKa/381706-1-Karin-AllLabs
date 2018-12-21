#include "Queue.h"
#include "Stack.h"
TQueue<char> One(TString S)
{
	TQueue<char> Res;
	TStack<char> st;
	for (int i = 0; i < s.Size(); i++)
	{
		if (isnumber(s[i]))
			res.push(s[i]);
		else
		{
			if (s[i] == ')')
			{
				while (st.top()!= '(')
					res.push(st.get());
				st.get();
			}
			else if (st.isempty())
				st.push(s[i]);
			else if (getprior(s[i]) > getprior(st.top()))
				st.push(s[i]);
			else
			{
				while ((getprior(s[i]) <= getprior(st.top())))
					res.push(st.get());
			}
		}
	}
	while (!st.isempty())
		res.push(st.get());
	return res;
}

double f(TQueue<char> q)
{
	double res;
	TStack<double> st2;
	while (!q.IsEmpty())
	{
		char A = q.get();
		if (isnumber(A))
			st2.push(atof(A))
		else
		{
			double y = st2.get();
			double x = st2.get();
			double z = 0;
			if (A == '+') z = x + y;
			if (A == '-') z = x - y;
			if (A == '*') z = x * y;
			if (A == '/') z = x / y;
			st2.push(z);
		}
	}
	res = st2.get();
	return res;
}