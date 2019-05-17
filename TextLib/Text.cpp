#include "Text.h"
using namespace std;


TText::TText()
{
	root = 0;
}

char * TText::Copy(int start, int n)
{
	char* res = new char[n];
	bool f = false;
	int pos = 0;
	TNodeIter t(root);
	while (pos != start)
	{
		if (t.IsEnd())
			throw TException("incorrect values", "Text", "Copy", 5);
		if (t()->GetLevel() == 3)
			pos++;
		t++;
	}
	pos = 0;
	while (pos < n)
	{
		if (t.IsEnd())
			throw TException("incorrect values", "Text", "Copy", 5);
		if (t()->GetLevel() == 3)
		{
			res[pos] = t()->GetData();
			pos++;
		}
		t++;
	}
	return res;
}

void TText::Del(int start, int n)
{
	return;
}

void TText::Ins(TNode* start, TNode* d)
{ 
	if (start->GetLevel() != d->GetLevel())
		throw TException("different level", "Text", "Ins", 5);
	d->SetSosed(start->GetSosed());
	start->SetSosed(d);
}

TNode* TText::Find(char* a)
{
	TNodeIter i(root);
	for (; i.IsEnd(); i++)
	{
		if (i()->GetData() == a[0])
		{
			bool f = true;
			TNodeIter j = i;
			int t = 1;
			while ((!(j.IsEnd())) && (a[t]!='\0'))
			{
				if (j()->GetData() != a[t])
				{
					f = false;
					break;
				}
				t++;
			}
			if (f = true)
				return i();
		}
	}
	return NULL;
}

int TText::FindIndex(char * a)
{

	return 0;
}

