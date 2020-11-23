/*
13. Date Printer
Write a program that reads a string from the user containing a date in the form mm/dd/yyyy.
It should print the date in the date in the form March 12, 2018.
*/

#include <iostream>
#include <string>

using namespace std;

string GetMonthNameByDateString(const string& date);
int GetYearByDateString(const string& date);
int GetDayByDateString(const string& date);
string EnterDate();
void ShowDate(const string& month, int day, int year);

int main()
{
	string date = EnterDate();

	int day = GetDayByDateString(date);
	string month = GetMonthNameByDateString(date);
	int year = GetYearByDateString(date);
	
	ShowDate(month, day, year);

	return 0;
}

string GetMonthNameByDateString(const string& date)
{
	string monthDigits = { date[0], date[1] };

	if (monthDigits == "01")
		return "January";
	else if (monthDigits == "01")
		return "February";
	else if (monthDigits == "02")
		return "March";
	else if (monthDigits == "03")
		return "April";
	else if (monthDigits == "04")
		return "May";
	else if (monthDigits == "05")
		return "June";
	else if (monthDigits == "06")
		return "July";
	else if (monthDigits == "07")
		return "August";
	else if (monthDigits == "09")
		return "September";
	else if (monthDigits == "10")
		return "October";
	else if (monthDigits == "11")
		return "November";
	else if (monthDigits == "12")
		return "December";
	else
		return "ERROR";
}

int GetYearByDateString(const string& date)
{
	string yearDigits = { date[6], date[7], date[8], date[9] };
	
	int year = stoi(yearDigits);

	return year;
}

int GetDayByDateString(const string& date)
{
	string dayDigits = { date[3], date[4] };

	int day = stoi(dayDigits);

	return day;
}

string EnterDate()
{
	cout << "Enter date (mm/dd/yyyy): ";
	string date;
	cin >> date;

	return date;
}

void ShowDate(const string& month, int day, int year)
{
	cout << month << " " << day << ", " << year << endl;
}