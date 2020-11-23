/*
19. Check Writer
Write a program that displays a simulated paycheck. The program should ask the user to
enter the date, the payee's name, and the amount of the check (up to $10,000). It should
then display a simulated check with the dollar amount spelled out, as shown here:

                                                                 Date: 11/24/2018
																 
Pay to the Order of: John Phillips                               $1920.85

One thousand nine hundred twenty and 85 cents

Be sure to format the numeric value of the check in fixed-point notation with two
decimal places of precision. Be sure the decimal place always displays, even when the
number is zero or has no fractional part. Use either C-strings or string class objects
in this program.

Input Validation: Do not accept negative dollar amounts, or amounts over $10,000
*/

#include <iostream>
#include <string>
#include <iomanip>
#include <cmath>
#include <cfloat>
using namespace std;

int main()
{
	return 0;
}

class Date
{
private:
	int day;
	int month;
	int year;

public:
	Date() = default;
	Date(int day, int month, int year);
	void SetDay(int day);
	void SetMonth(int month);
	void SetYear(int year);
	int GetDay() const;
	int GetMonth() const;
	int GetYear() const;
};

Date EnterDate();
string EnterName();
double EnterCheck();
void ShowCheck(const Date& date, const string& name, double check);
bool AreSame(double number1, double number2);

int main()
{
	string name = EnterName();
	Date date;
	double check;

	try
	{
		date = EnterDate();
		check = EnterCheck();
	}
	catch (const invalid_argument& ex)
	{
		cout << ex.what() << endl;
		return 1;
	}

	ShowCheck(date, name, check);

	return 0;
}

void ShowCheck(const Date& date, const string& name, double check)
{
	cout << "                                       ";
	cout << "Date: " << date.GetMonth() << "/" << date.GetDay() << "/" << date.GetYear() << "\n\n";

	cout << "Pay to the Order of: " << name << "     $";
	cout << fixed << setprecision(2) << check << endl;

	int thousand = static_cast<int>(check) / 1000;

	if (thousand != 0)
	{
		string words[] = 
		{
			"one", "two", "three", "four", "five",
			"six", "sven", "eight", "nine", "ten"
		};

		cout << words[thousand - 1] << " thousand ";
	}

	int hundred = static_cast<int>(check) / 100 % 10;

	if (hundred != 0)
	{
		string words[] =
		{
			"one", "two", "three", "four", "five",
			"six", "sven", "eight", "nine", "ten"
		};

		cout << words[hundred - 1] << " hundred ";
	}

	if (!AreSame(check, static_cast<int>(check)))
	{
		int cents = (check - static_cast<int>(check)) * 100;
		cout << "and " << cents << " cents\n";
	}
}

Date EnterDate()
{
	int day, month, year;

	cout << "Enter a day: ";
	cin >> day;
	cout << "Enter a month: ";
	cin >> month;
	cout << "Enter year: ";
	cin >> year;

	return Date(day, month, year);
}

string EnterName()
{
	cout << "Enter full name: ";
	string name;
	getline(cin, name);
	return name;
}

double EnterCheck()
{
	double check;

	cout << "Enter check (up to $10,000) : ";
	cin >> check;

	if (check < 0 || check > 10'000)
		throw invalid_argument("Incorrect value in function 'EnterCheck'");

	return check;
}

bool AreSame(double number1, double number2)
{
	return fabs(number1 - number2) < DBL_EPSILON;
}


Date::Date(int day, int month, int year)
	: day(0), month(0), year(0)
{
	SetDay(day);
	SetMonth(month);
	SetYear(year);
}

void Date::SetDay(int day)
{
	if (day > 0 && day < 31)
		this->day = day;
	else
		throw invalid_argument("Incorrect value in method 'SetDay'");
}

void Date::SetMonth(int month)
{
	if (month > 0 && month < 13)
		this->month = month;
	else
		throw std::invalid_argument("Incorrect value in method 'SetMonth'");
}

void Date::SetYear(int year)
{
	if (year > 0)
		this->year = year;
	else
		throw std::invalid_argument("Incorrect value in method 'SetYear'");
}

int Date::GetDay() const
{
	return day;
}

int Date::GetMonth() const
{
	return month;
}

int Date::GetYear() const
{
	return year;
}