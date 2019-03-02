#pragma once
#include "Monom.h"
#include "../Exception/Exception.h"
class TPolynom {
protected:
	TMonom *start;
	int n; //количество переменных
public:
	TPolynom(int _n);
	TPolynom(TPolynom &p);
	virtual ~TPolynom();
	TMonom* GetStart();
	TPolynom& operator+=(TMonom &m);
	TPolynom& operator=(const TPolynom &p);
	TPolynom operator+(TPolynom &p);
	bool operator ==(const TPolynom& p);
	friend ostream& operator << (ostream& ostr, TPolynom& p);
};

