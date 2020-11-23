/*
15. Payroll Report
Write a program that displays a weekly payroll report. A loop in the program should
ask the user for the employee number, gross pay, state tax, federal tax, and FICA withholdings.
The loop will terminate when 0 is entered for the employee number. After the
data is entered, the program should display totals for gross pay, state tax, federal tax,
FICA withholdings, and net pay.

Input Validation: Do not accept negative numbers for any of the items entered. Do
not accept values for state, federal, or FICA withholdings that are greater than the
gross pay. If the sum of state tax + federal tax + FICA withholdings for any employee
is greater thatn gross pay, print an error message and ask the user to reenter the data
for that employee.
*/

#include <iostream>
#include <iomanip>

int main()
{
	using namespace std;

	double totalGrossPay = 0.0, totalStateTax = 0.0, totalFederalTax = 0.0, totalFica = 0.0;
	double netPay = 0.0;
	int employeeNumber;

	do
	{
		cout << "Enter the employee number: ";
		cin >> employeeNumber;

		if (employeeNumber == 0)
			continue;

		if (employeeNumber < 0)
		{
			cout << "Incorrect employee number.\n";
			return 0;
		}

		cout << "Enter gross pay: ";
		double grossPay;
		cin >> grossPay;

		totalGrossPay += grossPay;

		if (grossPay < 0)
		{
			cout << "Incorrect gross pay.\n";
			return 0;
		}

		cout << "Enter state tax: ";
		double stateTax;
		cin >> stateTax;

		totalStateTax += stateTax;

		if (stateTax < 0 || stateTax > grossPay)
		{
			cout << "Incorrect state tax.\n";
			return 0;
		}

		cout << "Enter federal tax: ";
		double federalTax;
		cin >> federalTax;

		totalFederalTax += federalTax;

		if (federalTax < 0 || federalTax > grossPay)
		{
			cout << "Incorrect federal tax.\n";
			return 0;
		}

		cout << "Enter FICA withholdings: ";
		double fica;
		cin >> fica;

		totalFica += fica;

		netPay = grossPay - totalGrossPay - totalStateTax - totalFederalTax;

		if (fica < 0 || fica > grossPay)
		{
			cout << "Incorrect FICA withholdings.\n";
			return 0;
		}

	} while (employeeNumber != 0);

	cout << fixed << setprecision(2);
	cout << "Total Gross Pay:   $" << totalGrossPay << endl;
	cout << "Total State Tax:   $" << totalStateTax << endl;
	cout << "Total Federal Tax: $" << totalFederalTax << endl;
	cout << "Total Total Fica:  $" << totalFica << endl;
	cout << "Total Net Pay:     $" << totalFica << endl;

	return 0;
}