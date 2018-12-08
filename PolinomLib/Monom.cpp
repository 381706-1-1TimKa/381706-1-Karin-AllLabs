#include "Monom.h"

TMonom::~TMonom()
{
	delete[] power;
	c = 0;
	next = 0;
}

TMonom::TMonom(int _n, unsigned* _power, double _c) :n(_n)
{
	if (_n <= 0)
		throw - 1;
	power = new unsigned[_n];
	if (_power != 0) {
		for (int i = 0; i < _n; i++)
			power[i] = _power[i];
	}
	else {
		for (int i = 0; i < _n; i++)
			power[i] = 0;
	}
	c = _c;
	next = 0;
}

TMonom::TMonom(TMonom& monom) : n(monom.n)
{
	c = monom.c;
	next = monom.next;
	power = new unsigned[n];
	for (int i = 0; i < n; i++) {
		power[i] = monom.power[i];
	}
}

TMonom* TMonom::GetNext()
{
	return next;
}

unsigned* TMonom::GetPower()
{
	return power;
}

double TMonom::GetC()
{
	return c;
}
const int TMonom::GetN()
{
	return n;
}

void TMonom::SetNext(TMonom* _next)
{
	next = _next;
}

void TMonom::SetPower(unsigned* _power)
{
	try {
		for (int i = 0; i < n; i++)
			if (_power[i] >= 0)
			{
				power[i] = _power[i];
			}
			else
				throw 1;
	}
	catch (...)
	{
		throw 2;
	}
}

void TMonom::SetC(double _c)
{
	c = _c;
}


TMonom& TMonom::operator =(TMonom& monom)
{
	if (this != &monom)
	{
		c = monom.c;
		if (n != monom.n)
			throw 1;
		for (int i = 0; i < n; i++)
			power[i] = monom.power[i];
		next = monom.next;
	}
	return *(this);
}

TMonom& TMonom::operator +(TMonom& monom)
{
	if (n != monom.n || !(*this == monom))
		throw 1;
	TMonom temp(monom);
	temp.c = c + monom.c;
	return temp;
}

TMonom& TMonom::operator -(TMonom& monom)
{
	if ((n != monom.n) || !(*this == monom))
		throw 1;
	TMonom temp(monom);
	temp.c = c - monom.c;
	return temp;
}

TMonom& TMonom::operator*(TMonom& monom){
	if (n != monom.n || !(*this == monom))
		throw 1;
	int max;
	unsigned int *_power;
	int _c = c * monom.c;
	if (n <= monom.n) {
		max = n;
		_power = new unsigned int[monom.n];
		for (int i = 0; i < monom.n; i++){
			_power[i] = monom.power[i];
			if (i < n)
				_power[i] += power[i];
		}
	}
	else {
		max = n;
		_power = new unsigned int[n];
		for (int i = 0; i < n; i++) {
			_power[i] = power[i];
			if (i < monom.n)
				_power[i] += monom.power[i];
		}
	}
		TMonom temp(max, _power, _c);
		return temp;
}



bool TMonom::operator ==(TMonom& monom)
{
	if (n != monom.n)
		throw 1;
	for (int i = 0; i < n; i++) {
		if (power[i] != monom.power[i])
			return false;
	}
	return true;
}
bool TMonom::operator >(TMonom& monom)
{
	if (n != monom.n)
		throw 1;

	for (int i = 0; i < n; i++) {
		if (power[i] < monom.power[i])
			return false;
	}
	return true;

}
bool TMonom::operator <(TMonom& monom)
{
	if (n != monom.n)
		throw 1;
	for (int i = 0; i < n; i++) {
		if (power[i] > monom.power[i])
			return false;
	}
	return true;

}

std::istream& operator >> (std::istream& _s, TMonom& Tm)
{
	std::cout << "input c\n" << std::endl;
	_s >> Tm.c;
	std::cout << "input power \n" << std::endl;
	for (int i = 0; i < Tm.n; i++)
		_s >> Tm.power[i];

	return _s;
}

std::ostream& operator << (std::ostream& _s, TMonom& Tm)
{
	_s << Tm.c;
	if (Tm.c != 0)
	{
		for (int i = 0; i < Tm.n; i++)
			if (Tm.power[i] != 0)
			{
				_s << "x" << i;
				if (Tm.power[i] != 1)
					_s << "^" << Tm.power[i] << " ";
			}
	}
	return _s;
}