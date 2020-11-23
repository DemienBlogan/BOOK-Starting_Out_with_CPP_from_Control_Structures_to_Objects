#include "GasPrice.h"

GasPrice::GasPrice(const Date& date, double price)
	: date{ 0, 0, 0 }, price(0.00)
{
	SetDate(date);
	SetPrice(price);
}

void GasPrice::SetDateDay(int day)
{
	if (day > 0 && day <= 31)
		this->date.day = day;
}

void GasPrice::SetDateMonth(int month)
{
	if (month > 0 && month <= 12)
		this->date.month = month;
}

void GasPrice::SetDateYear(int year)
{
	if (year > 0)
		this->date.year = year;
}

void GasPrice::SetDate(const Date& date)
{
	SetDateDay(date.day);
	SetDateMonth(date.month);
	SetDateYear(date.year);
}

void GasPrice::SetPrice(double price)
{
	if (price >= 0.00)
		this->price = price;
}