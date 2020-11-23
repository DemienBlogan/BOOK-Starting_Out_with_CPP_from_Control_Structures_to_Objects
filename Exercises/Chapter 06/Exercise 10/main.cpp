/*
10. Future Value
Suppose you have a certain amount of money in a savings account that earns compound
monthly interest, and you want to calculate the amount that you will have
after a specific number of months. The formula, which is known as the future value
formula, is

F = P * (1 + i)^t

- F is the future value of the account after the specified time period.
- P is the present value of the account.
- i is the monthly interest rate.
- t is the numbe rof months.

Write a program that prompts the user to enter the account's present value, monthly
iterest rate, and the numbe rof months that the money will be left in the account. The
program should pass these values to a function named futureValue that returns the
future value of the account, after the specified number of month. The program should
display the account's future value.
*/

#include <iostream>
#include <iomanip>
#include <cmath>

double futureValue(double P, double i, int t);

int main()
{
	using namespace std;

	cout << "Enter present value: $";
	double P;
	cin >> P;

	cout << "Enter the monthly interest rate: $";
	double i;
	cin >> i;

	cout << "Enter the number of months: ";
	int t;
	cin >> t;

	double F = futureValue(P, i, t);

	cout << fixed << setprecision(2);
	cout << "The future value =	$" << F << endl;

	return 0;
}

double futureValue(double P, double i, int t)
{
	double F = P * pow(1 + i, t);
	return F;
}