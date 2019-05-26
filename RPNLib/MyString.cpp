#include "../RPNLib/MyString.h"


TString::TString()
{
	str = 0;
	len = 0;
}

TString::TString(TString& _str)
{
	len = _str.len;
	if (_str.len == 0)
		str = 0;
	else
	{
		str = new char[len];
		for (int i = 0; i < len; i++)
			str[i] = _str.str[i];
	}
}

TString::TString(const char* ch)
{
	if (ch == 0)
		throw 1;
	if (ch[0] == '\0')
		return;
	int size=0;
	char k=1;
	while (k != '\0')
	{
		size++;
		k = ch[size];
	}
	len = size+1;
	str = new char[len];
	for (int i = 0; i < len; i++)
		str[i] = ch[i];
}

TString::~TString()
{
	if (len != 0)
		delete str;
	str = 0;
	len = 0;
}

int TString::GetLength()
{
	return len;
}

TString& TString::operator=(const TString& _str)
{
	if (this == &_str)
		return *this;
	if (len != _str.len)
	{
		delete[] str;
		len = _str.len;
		if (len != 0)
			str = new char[len];
		else
			return *this;
	}
	for (int i = 0; i < len; i++)
	{
		str[i] = _str.str[i];
	}
	return *this;
}

TString TString::operator+(TString& _str)
{
	TString Res;
	Res.len = len + _str.len - 1;
	Res.str = new char[Res.len];
	for (int i = 0; i < len - 1; i++)
		Res.str[i] = str[i];
	for (int i = 0; i < _str.len; i++)
		Res.str[i + len - 1] = _str[i];
	return Res;
}

char& TString::operator[] (int i)
{
	if ((i < 0) || (i >= len))
		throw 1;
	return str[i];
}

bool TString::operator==(TString& _str)
{
	if (len != _str.len)
		return false;
	for (int i = 0; i < len; i++)
		if (str[i] != _str.str[i])
			return false;
	return true;
}

bool TString::operator>(TString& _str)
{
	int minlen;
	if (len < _str.len)
		minlen = len;
	else
		minlen = _str.len;
	for (int i = 0; i < minlen-1; i++)
	{
		if (str[i] < _str.str[i])
			return false;
		if (str[i] > _str.str[i])
			return true;
	}
	if (len == _str.len)
		return false;
	if (minlen == len)
		return true;
	else
		return false;
}

bool TString::operator<(TString& _str)
{
	if (*this == _str)
		return false;
	return !(*this > _str);
}


std::istream& operator>>(std::istream &is, TString &string)
{
	char s[256];
	is >> s;

	char x = 1;
	int size = 0;
	while (x != '\0')
	{
		size++;
		x = s[size];
	}
	string.len = size + 1;
	string.str = new char[string.len];
	for (int i = 0; i < string.len - 1; i++)
		string.str[i] = s[i];
	string.str[string.len - 1] = 0;
	return is;
}

	std::ostream& operator<<(std::ostream &os, const TString &string)
	{
		os << string.str;
		return os;
	}