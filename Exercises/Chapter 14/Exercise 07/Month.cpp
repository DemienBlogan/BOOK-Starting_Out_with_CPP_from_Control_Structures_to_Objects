#include <algorithm>
#include "Month.h"

using std::find;

const string Month::MONTHS_NAMES[Month::MONTHS] =
{
	"January", "February", "March",
	"April", "May", "June",
	"July", "August", "September",
	"October", "November", "December"
};

int Month::MonthNameIntoNumber(const string& name)
{
	const auto& findIter = find(MONTHS_NAMES, MONTHS_NAMES + MONTHS, name);

	int monthNumber = findIter - MONTHS_NAMES + 1;

	return monthNumber;
}

string Month::MonthNumberIntoName(int monthNumber)
{
	return MONTHS_NAMES[monthNumber - 1];
}

Month::Month()
	: name("January"), monthNumber(1)
{ }

Month::Month(const string& name)
	: Month()
{
	SetName(name);
}

Month::Month(int monthNumber)
	: Month()
{
	SetMonthNumber(monthNumber);
}

void Month::SetName(const string& name)
{
	if (find(MONTHS_NAMES, MONTHS_NAMES + MONTHS, name) == MONTHS_NAMES + MONTHS)
		return;

	this->monthNumber = MonthNameIntoNumber(name);
	this->name = name;
}

void Month::SetMonthNumber(int monthNumber)
{
	if (monthNumber <= 0 || monthNumber > 12)
		return;

	this->monthNumber = monthNumber;
	this->name = MonthNumberIntoName(monthNumber);
}

string Month::GetName() const
{
	return name;
}

int Month::GetMonthNumber() const
{
	return monthNumber;
}

Month& Month::operator--()
{
	if (monthNumber - 1 <= 0)
	{
		name = MONTHS_NAMES[MONTHS - 1];
		monthNumber = 12;
	}
	else
	{
		monthNumber--;
		name = MONTHS_NAMES[monthNumber - 1];
	}

	return *this;
}

Month Month::operator--(int)
{
	Month copy{ *this };

	if (monthNumber - 1 <= 0)
	{
		name = MONTHS_NAMES[MONTHS - 1];
		monthNumber = 12;
	}
	else
	{
		monthNumber--;
		name = MONTHS_NAMES[monthNumber - 1];
	}

	return copy;
}

Month& Month::operator++()
{
	if (monthNumber + 1 > MONTHS)
	{
		name = MONTHS_NAMES[0];
		monthNumber = 1;
	}
	else
	{
		monthNumber++;
		name = MONTHS_NAMES[monthNumber - 1];
	}

	return *this;
}

Month Month::operator++(int)
{
	Month copy{ *this };

	if (monthNumber + 1 > MONTHS)
	{
		name = MONTHS_NAMES[0];
		monthNumber = 1;
	}
	else
	{
		monthNumber++;
		name = MONTHS_NAMES[monthNumber - 1];
	}

	return copy;
}

ostream& operator<<(ostream& out, const Month& month)
{
	out << month.name << " (" << month.monthNumber << " month)";

	return out;
}

istream& operator>>(istream& in, Month& month)
{
	in >> month.monthNumber;

	return in;
}