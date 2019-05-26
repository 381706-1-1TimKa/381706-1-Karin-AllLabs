#pragma once
#include <iostream>

class TString
{
	char* str;
	int len;
public:
	TString();
	TString(TString& _str);
	TString(const char* ch);
	~TString();

	int GetLength();
	TString& operator=(const TString& _str);
	TString operator+(TString& _str);
	char& operator[] (int i);

	bool operator==(TString& _str);
	bool operator>(TString& _str);
	bool operator<(TString& _str);

	friend std::istream& operator>>(std::istream &is, TString& str);
	friend std::ostream& operator<<(std::ostream &os, const TString& str);
};
