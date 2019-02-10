#pragma once
#include "Monom.h"
#include "../Exception/Exception.h"
class TPolynom {
protected:
	TMonom *start;
	int n; //x1x2...xn
public:
	TPolynom(int _n);
	TPolynom(TPolynom &p);
	TPolynom& operator+=(TMonom &m);
	TPolynom& operator=(TPolynom &p);
	TPolynom operator+(TPolynom &p);
	TPolynom operator*(TPolynom &p);
};

