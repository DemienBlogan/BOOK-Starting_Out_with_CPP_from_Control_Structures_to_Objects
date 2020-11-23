/*
16. Savings Account Balance
Write a program that calculates the balance of a savings account at the end of a peroid
of time. It should ask the user for the annual iterest rate, the starting balance, and the
number number of months that have passed since the account was established. A loop should
then iterate once for every month, performing the following:

A) Ask the user for the amount deposited into the account during the month. (Do not
   accept negative numbers.) THis amount should be added to the balance.
B) Ask the user for the amount withdrawn from the account during the month. (Do
   not accept negative numbers). This amount should be subtracted from the balance.
C) Calculate the monthly interest. The monthly interest rate is the annual interest rate
   divided by 12. Multiply the monthly interest rate by the balance, and add the result
   to the balance.

After the last iteration, the program should display the ending balance, the total
amount of deposits, the total amount of withdrawals, and the total interest earned.

NOTE: If a negative balance is calculated at any point, a message should be displayed
      indicationg the account has been closed and the loop should terminate.
*/

#include <iostream>
#include <iomanip>

int main()
{
	using namespace std;

	const int MONTHS_IN_YEAR = 12;

	cout << "Enter the annual interest rate: $";
	double annualInterestRate;
	cin >> annualInterestRate;

	double monthlyInterestRate = annualInterestRate / MONTHS_IN_YEAR;

	cout << "Enter the starting balance: $";
	double balance;
	cin >> balance;

	cout << "Enter the number of months that have passed since the acocunt was established: ";
	int months;
	cin >> months;

	double totalDeposits = 0.0, totalWithdrawals = 0.0, totalInterest = 0.0;

	for (int month = 1; month <= months; month++)
	{
		if (balance < 0)
		{
			cout << "The account has been closed.\n";
			break;
		}

		cout << "Month #" << month << endl;
		cout << "\tEnter the amount deposited into the account during the month: $";
		double deposite;
		cin >> deposite;

		if (deposite < 0)
		{
			cout << "Incorrect deposite.\n";
			return 0;
		}

		balance += deposite;
		totalDeposits += deposite;

		cout << "\tEnter the amount withdrawn from the account during the month: $";
		double withdraw;
		cin >> withdraw;

		if (withdraw < 0)
		{
			cout << "Incorrect withdraw.\n";
			return 0;
		}

		balance -= withdraw;
		totalWithdrawals += withdraw;

		double monthlyInterest = monthlyInterestRate * balance;
		balance += monthlyInterest;
		totalInterest += monthlyInterest;
	}

	cout << fixed << setprecision(2);
	cout << "The ending balance: $" << balance << endl;
	cout << "The total amount of deposits: $" << totalDeposits << endl;
	cout << "The total amount of withdrawals: $" << totalWithdrawals << endl;
	cout << "The total interest earned: $" << totalInterest << endl;

	return 0;
}