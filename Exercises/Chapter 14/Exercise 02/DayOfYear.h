#pragma once

#include <string>

using std::string;
using std::pair;

class DayOfYear
{
private:
	enum { MONTHS_AMOUNT = 12 };
	static pair<string, int> months[MONTHS_AMOUNT];
	int dayNumber;

public:
	DayOfYear(int dayNumber);
	void print() const;
};