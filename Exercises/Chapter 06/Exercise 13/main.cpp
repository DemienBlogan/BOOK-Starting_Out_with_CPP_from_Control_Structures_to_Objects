/*
13. Days Out
Write a program that calculates the average number of days a company's employees are
absent. The program should have the following functions:

- A function called by main that asks the user for the number of employees in the
  company. This value should be returned as an int. (The function accepts no arguments).
- A function called by main that accepts one argument: the number of employees in
  the company. The function should ask the user to enter the number of days each
  employee missed during the past year. The total of these days should be returned as
  an int.
- A function called by main that takes two arguments: the number of employees in
  the company and the total number of days absent for all employees during the year.
  The function should return, as a double, the average number of days absent. (This
  function does not perform screen output and does not ask the user for input).

Input Validation: Do not accept a number less than 1 for the number of employees. Do
not accept a negative number for the days any employee missed.
*/

#include <iostream>

int EnterNumberEmployees();
int EnterTotalDaysOut(int numberEmpoyees);
double CalculateAverageDaysOut(int numberEmpoyees, int totalOutDays);

int main()
{
	using namespace std;

	int numberEmployees = EnterNumberEmployees();
	int totalDaysOut = EnterTotalDaysOut(numberEmployees);
	double averageDaysOut = CalculateAverageDaysOut(numberEmployees, totalDaysOut);

	cout << "Average days out = " << averageDaysOut << endl;

	return 0;
}

int EnterNumberEmployees()
{
	using namespace std;

	cout << "Enter the number of employees in the company: ";
	int numberEmpoyees;
	cin >> numberEmpoyees;

	if (numberEmpoyees < 1)
	{
		cout << "Incorrect number of employees.\n";
		exit(0);
	}

	return numberEmpoyees;
}

int EnterTotalDaysOut(int numberEmpoyees)
{
	using namespace std;

	int totalOutDays = 0;

	for (int i = 0; i < numberEmpoyees; i++)
	{
		cout << "Enter out days for employee #" << i + 1 << ": ";
		int outDays;
		cin >> outDays;

		if (outDays < 0)
		{
			cout << "Incorrect number of out days.\n";
			exit(0);
		}

		totalOutDays += outDays;
	}

	return totalOutDays;
}

double CalculateAverageDaysOut(int numberEmpoyees, int totalOutDays)
{
	double average = static_cast<double>(totalOutDays) / numberEmpoyees;
	return average;
}