#include <iostream>

#include "Date.h"

using std::cout;
using std::cin;
using std::endl;

string Date::GetMonthName() const
{
	switch (month)
	{
	case 1:
		return "January";
	case 2:
		return "February";
	case 3:
		return "March";
	case 4:
		return "April";
	case 5:
		return "May";
	case 6:
		return "June";
	case 7:
		return "July";
	case 8:
		return "August";
	case 9:
		return "September";
	case 10:
		return "October";
	case 11:
		return "November";
	case 12:
		return "December";
	default:
		return "ERROR MONTH";
	}
}

Date::Date(int month, int day, int year)
	: month(1), day(1)
{
	this->month = (month >= 1 && month <= 12) ? month : 1;
	this->day = (day >= 1 && day <= 31) ? day : 1;
	this->year = year;
}

void Date::Show(Representing representing) const
{
	switch (representing)
	{
	case Date::Representing::BY_SLASH:
		cout << month << "/" << day << "/" << year << endl;
		break;

	case Date::Representing::MONTH_DAY_COMA_YEAR:
		cout << GetMonthName() << " " << day << ", " << year << endl;
		break;

	case Date::Representing::DAY_MONTH_YEAR:
		cout << day << " " << GetMonthName() << " " << year << endl;
		break;

	default:
		cout << "Incorrect representing.\n";
		break;
	}
}

Date& Date::operator--()
{
	if (day - 1 <= 0)
	{
		if (month - 1 <= 0)
		{
			month = 12;
			year--;
		}
		else
			month--;

		day = 31;
	}
	else
		day--;

	return *this;
}

Date Date::operator--(int)
{
	Date copy{ *this };

	if (day - 1 <= 0)
	{
		if (month - 1 <= 0)
		{
			month = 12;
			year--;
		}
		else
			month--;

		day = 31;
	}
	else
		day--;

	return copy;
}

Date& Date::operator++()
{
	if (day + 1 > 31)
	{
		if (month + 1 > 12)
		{
			month = 1;
			year++;
		}
		else
			month++;

		day = 1;
	}
	else
		day++;

	return *this;
}

Date Date::operator++(int)
{
	Date copy{ *this };

	if (day + 1 > 31)
	{
		if (month + 1 > 12)
		{
			month = 1;
			year++;
		}
		else
			month++;

		day = 1;
	}
	else
		day++;

	return copy;
}

int Date::operator-(const Date& other) const
{
	const int MONTHS_IN_YEAR = 12;
	const int DAYS_IN_MONTH = 31;

	int date1Days = (this->year - 1) * MONTHS_IN_YEAR * DAYS_IN_MONTH +
		(this->month - 1) * DAYS_IN_MONTH + this->day;

	int date2Days = (other.year - 1) * MONTHS_IN_YEAR * DAYS_IN_MONTH +
		(other.month - 1) * DAYS_IN_MONTH + other.day;

	return date1Days - date2Days;
}

ostream& operator<<(ostream& out, const Date& date)
{
	switch (date.month)
	{
	case 1:
		out << "January";
		break;
	case 2:
		out << "February";
		break;
	case 3:
		out << "March";
		break;
	case 4:
		out << "April";
		break;
	case 5:
		out << "May";
		break;
	case 6:
		out << "June";
		break;
	case 7:
		out << "July";
		break;
	case 8:
		out << "August";
		break;
	case 9:
		out << "September";
		break;
	case 10:
		out << "October";
		break;
	case 11:
		out << "November";
		break;
	case 12:
		out << "December";
		break;
	default:
		out << "ERROR";
		break;
	}
	out << " " << date.day << ", " << date.year;

	return out;
}

istream& operator>>(istream& in, Date& date)
{
	int month;
	int day;
	int year;

	in >> month >> day >> year;

	if (month >= 1 && month <= 12)
		date.month = month;
	if (day >= 1 && day <= 31)
		date.day = day;
	if (year >= 1)
		date.year = year;

	return in;
}