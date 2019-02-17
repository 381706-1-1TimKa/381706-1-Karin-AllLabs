#pragma once
#include <iostream>

class TString
{
	char* str;
	int len;
public:
	TString();
	TString(TString& _str);
	TString(char* ch);
	~TString();

	int GetLength();
	TString& operator=(TString& _str);
	TString operator+(TString& _str);
	char& operator[] (int i);

	friend std::istream& operator>>(std::istream &is, TString& str);
	friend std::ostream& operator<<(std::ostream &os, const TString& str);
};
