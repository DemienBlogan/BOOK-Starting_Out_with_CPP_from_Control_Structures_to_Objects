#pragma once

struct Date
{
	int day;
	int month;
	int year;
};

class GasPrice
{
private:
	Date date;
	double price;

public:
	GasPrice(const Date& date = Date{ 0, 0, 0 }, double price = 0.00);
	
	void SetDateDay(int day);
	void SetDateMonth(int month);
	void SetDateYear(int year);
	void SetDate(const Date& date);
	void SetPrice(double price);

	int GetDateDay() const { return date.day; }
	int GetDateMonth() const { return date.month; }
	int GetDateYear() const { return date.year; }
	Date GetDate() const { return date; }
	double GetPrice() const { return price; }
};