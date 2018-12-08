#include "Polynom.h"

TPolynom TPolynom::operator+ (TPolynom &p) {
	TPolynom temp(n);
	TMonom *i1 = start, *i2 = p.start, *i = 0;
	while ((i1 != 0) && (i2 != 0))
	{
		TMonom *t1;
		if ((*i1) == (*i2))
		{
			t1 = new TMonom((*i1) + (*i2));
			i1 = i1->GetNext();
			i2 = i2->GetNext();
		}
		else
			//��� ��������� ����� �������� �������� ���: (x0^2 + x1 + x2^2) + (x0^2 + x0 + x2^2 + x2)
		{
			if ((*i1) < (*i2))
			{
				t1 = new TMonom((*i2));
				i2 = i2->GetNext();
			}
			else
			{
				t1 = new TMonom((*i1));
				i1 = i1->GetNext();
			}
		}
		if (temp.start == 0)
		{
			temp.start = t1; //���� ������� ������, �� ���� ��������� t1
			i = t1; //��������� � t1
		}
		else
		{
			i->SetNext(t1); //��������� t1 � ��������, ���� �� �� ������
			i = t1; //��������� � t1
		}
	}
	if (i1 == 0)
		i1 = i2; //���� ����� �� ����� ������� ��������, �� ������������ �������� �������� �� ������
	while (i1 != 0) //���������� �������
	{
		i->SetNext(new TMonom(*i1));
		i1 = i1->GetNext();
	}
	return temp;
}

TPolynom::TPolynom(TPolynom &p) {
	n = p.n;
	if (p.start == 0)
	{
		start = 0;
		end = 0;
	}
	else
	{
		n = p.n;
		TMonom *i = new TMonom(*p.start);
		//

	}
}

TPolynom& TPolynom::operator+=(TMonom &m)
{
	TMonom *_start, *_end;
	_start = start;
	_end = start->GetNext();
	if (start == 0) // ���� ������� ����
	{
		start = new TMonom(m);
		end = start;
	}
	else
	{
		if (*start < m) // ���� ����� ������, ��� ������ ���� ��������
		{
			TMonom* tmp = new TMonom(m);
			tmp->SetNext(start);
			start = tmp;
		}
		else
		{
			while (_end != 0)// ����������� �� ����� ��������
			{
				if ((*_start < m) && (m < *_end))
				{
					TMonom* tmp = new TMonom(m);
					_start->GetNext();
					tmp->SetNext(_end);
					break;
				}
				_start = _end;
				_end = _end->GetNext();
			}
			if (_end == 0)
			{
				start->SetNext(new TMonom(m));
				end = start->GetNext();
			}
		}
	}
	return *this;
}