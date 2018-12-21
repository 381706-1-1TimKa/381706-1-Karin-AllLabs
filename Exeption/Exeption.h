#pragma once
#include <iostream>
#include <string>
using namespace std;

class TExeption {
	string name;
	string file;
	string func;
	int number;
public:
	TExeption(string _name, string _file, string _func, int _number);
	TExeption(string _name, string _file, string _func);
	TExeption(string _name);
	void Print();
};

void TExeption::Print() {
	cout << "Exeption" << endl;
	if (number != 0)
		cout << "exeption number " << number << endl;
	cout << "massege: " << name << endl;
	cout << "In file: " << file << endl;
	cout << "Function: " << func << endl;
}

TExeption::TExeption(string _exname, string _exfile, string _exfunc, int _exnumber) {
	name = _exname;
	file = _exfile;
	func = _exfunc;
	number = _exnumber;
}

TExeption::TExeption(string _exname, string _exfile, string _exfunc) {
	name = _exname;
	file = _exfile;
	func = _exfunc;
	number = 0;
}

TExeption::TExeption(string _exname) {
	name = _exname;
	file = "unknown";
	func = "unknown";
	number = 0;
}