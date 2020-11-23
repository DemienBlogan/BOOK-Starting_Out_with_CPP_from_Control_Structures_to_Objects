/*
11. Payroll Class
Design a PayRoll class that has data members for an employee's hourly par rate,
number of hours worked, and total pay for the week. Write a program with an array of
seven PayRoll object. The program should ask the user for the number of hours each
employee has worked, and will then display the amount of gross pay each has earned.

Input Validation: Do not accept values greater than 60 for the number of hours worked.
*/

#include <iostream>
#include <iomanip>

#include "PayRoll.h"

using std::cout;
using std::cin;
using std::endl;
using std::fixed;
using std::setprecision;

int main()
{
	const size_t SIZE = 7;
	PayRoll workers[SIZE];


	for (size_t i = 0; i < SIZE; i++)
	{
		cout << "Enter number of hours worked for worker #" << i + 1 << ": ";
		int hours;
		cin >> hours;

		workers[i].SetHours(hours);

		cout << "Enter hourly pay rate for worker #" << i + 1 << ": ";
		double payRate;
		cin >> payRate;

		workers[i].SetPayRate(payRate);
	}

	cout << fixed << setprecision(2);

	for (size_t i = 0; i < SIZE; i++)
	{
		cout << "Worker #" << i + 1 << ": \n";
		cout << "\t Number of hours worked: " << workers[i].GetHours() << endl;
		cout << "\t Number of hourly pay rate: $" << workers[i].GetPayRate() << endl;
		cout << "\t Amount of gross pay: $" << workers[i].GetTotalPay() << endl;
	}

	return 0;
}