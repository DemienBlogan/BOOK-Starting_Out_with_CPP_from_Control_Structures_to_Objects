#include <iostream>

#include "DayOfYear.h"

using std::cout;
using std::endl;

pair<string, int> DayOfYear::months[MONTHS_AMOUNT] =
{
	{ "January", 31 }, { "February", 28 }, { "March", 31 },
	{ "April", 30 }, { "May", 31 }, { "June", 30 },
	{ "July", 31 }, { "August", 31 }, { "September", 30 },
	{ "October", 31 }, { "November", 30 }, { "December", 31 }
};

DayOfYear::DayOfYear(int dayNumber)
	: dayNumber(0)
{
	if (dayNumber > 0 && dayNumber <= 365)
		this->dayNumber = dayNumber;
}

void DayOfYear::print() const
{
	string monthName;
	int daysInMonth;
	int copyDayNumber = dayNumber;

	for (size_t i = 0; i < MONTHS_AMOUNT; i++)
	{
		monthName = months[i].first;
		daysInMonth = months[i].second;

		if (copyDayNumber - daysInMonth <= 0)
			break;
		else
			copyDayNumber -= daysInMonth;
	}

	cout << monthName << " " << copyDayNumber << endl;
}