/*
6. Annual Pay
Suppose an employee gets paid every two weeks and earns $2,200 each pay period. In
a year, the employee gets paid 26 times. Write a program that defines che following
variables:

payAmount - This variable will hold the amount of pay the employee earns each
			pay period. Initialize the variable with 2200.0.

payPeriod - This variable will hold the number of pay periods in a year. Initialize
			the variable with 26.

annualPay - This variable will hold the employee's total annual pay, which will
			be calculated.

The program should calculate the employee's total annual pay by multiplying the
employee's pay amount by the number of pay periods in a year and store the result in
the annualPay variable. Display the total annual pay on the screen.
*/

#include <iostream>
#include <iomanip>

int main()
{
	using namespace std;

	double payAmount = 2200.0;
	int payPeriods = 26;
	double annualPay = payAmount * payPeriods;

	cout << fixed << setprecision(2);
	cout << "Pay amount  = $" << payAmount << endl;
	cout << "Pay periods = " << payPeriods << endl;
	cout << "Annual Pay  = $" << annualPay << endl;

	return 0;
}