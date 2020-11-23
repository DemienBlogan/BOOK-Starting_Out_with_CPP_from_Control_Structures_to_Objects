/*
NOTE: This assignment assumes you have already completed Programming Challenges 4 and 5

Write a program that uses an instance of the TimeOff class you designed in
Programming Challenge 5. The program should ask the user to enter the numbe rof
months an employee has worked for the company. It should then use the TimeOff
object to calculate and display the employee's maximum number of sick leave and
vacation days. Employees earn 12 hours of vacation leave and 8 hours of sick leave
per month.
*/

#include <iostream>
#include "TimeOff.h"

using std::cout;
using std::cin;
using std::endl;

int main()
{
	cout << "Enter the number of months an employees has worked: ";
	int months;
	cin >> months;

	int earnedHoursVacationLeavePerMonth = 12;
	int earnedHoursSickLeavePerMonth = 8;

	TimeOff time1
	{
		"Demien Blogan",
		1,
		NumDays{ 5 * months },
		NumDays{ earnedHoursSickLeavePerMonth * months },
		NumDays{ 34 * months },
		NumDays{ earnedHoursVacationLeavePerMonth * months },
		NumDays{ 36 * months },
		NumDays{ 61 * months }
	};

	cout << "Employee's name: " << time1.GetEmployeeName() << endl;
	cout << "Employee's ID: " << time1.GetEmployeeID() << endl;
	cout << "Max Sick Days: " << time1.GetMaxSickDays() << endl;
	cout << "Sick Taken: " << time1.GetSickTaken() << endl;
	cout << "Max Vacation: " << time1.GetMaxVacation() << endl;
	cout << "Vac Taken: " << time1.GetVacTaken() << endl;
	cout << "Max Unpaid: " << time1.GetMaxUnpaid() << endl;
	cout << "Unpaid Taken: " << time1.GetUnpaidTaken() << endl;

	return 0;
}