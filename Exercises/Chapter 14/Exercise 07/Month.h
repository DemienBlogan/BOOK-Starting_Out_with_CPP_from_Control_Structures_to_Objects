#pragma once

#include <iostream>
#include <string>

using std::string;
using std::ostream;
using std::istream;

class Month
{
private:
	static const size_t MONTHS = 12;
	static const string MONTHS_NAMES[MONTHS];

	string name;
	int monthNumber;

	int MonthNameIntoNumber(const string& name);
	string MonthNumberIntoName(int monthNumber);

public:
	Month();
	Month(const string& name);
	Month(int monthNumber);
	
	void SetName(const string& name);
	void SetMonthNumber(int monthNumber);
	string GetName() const;
	int GetMonthNumber() const;

	Month& operator--();
	Month operator--(int);
	Month& operator++();
	Month operator++(int);

	friend ostream& operator<<(ostream& out, const Month& month);
	friend istream& operator>>(istream& in, Month& month);
};