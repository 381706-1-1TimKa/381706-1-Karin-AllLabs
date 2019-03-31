#pragma once
#include <iostream>

class TMyString
{
protected:
	char* str;
	int len;
public:
	TMyString();
	TMyString(TMyString& _str);
	TMyString(char* ch);
	~TMyString();

	int GetLength();
	TMyString& operator=(const TMyString& _str);
	TMyString operator+(TMyString& _str);
	char& operator[] (int i);

	friend std::istream& operator>>(std::istream &is, TMyString& str);
	friend std::ostream& operator<<(std::ostream &os, const TMyString& str);
};
