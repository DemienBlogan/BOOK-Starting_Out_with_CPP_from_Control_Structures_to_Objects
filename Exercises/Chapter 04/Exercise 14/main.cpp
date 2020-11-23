/*
14. Bank Charges
A bank charges $10 per month plus the following check fees for a commercial checking
account:
$0.10 each for fewer than 20 checks
$0.08 each for 20-39 checks
$0.06 each for 40-59 checks
$0.04 each for 60 or more checks
The bank also charges an extra $15 if the balance of the account falls below $400
(before any check fees are applied). Write a program that asks for the beginnin balance
and the number of checks written. Compute and display the bank's service fees
for the month.
Input Validation: Do not accept a negative value for the number of checks written. If a
negative value is given for the beginning balance, display an urgent message idicating
the account is overdrawn.
*/

#include <iostream>
#include <iomanip>

int main()
{
	using namespace std;

	cout << "Enter the beginning balance: $";
	double balance;
	cin >> balance;

	if (balance < 0)
	{
		cout << "The account is overdrawn.\n";
		return 0;
	}

	cout << "Enter the number of checks written: ";
	int checks;
	cin >> checks;

	if (checks < 0)
	{
		cout << "Incorrect value of checks. Try again.\n";
		return 0;
	}

	double serviceFees = 10;

	if (balance < 400)
		serviceFees += 15;

	double checkFees;

	if (checks < 20)
		checkFees = balance * 0.1;
	else if (checks >= 20 && checks <= 39)
		checkFees = balance * 0.08;
	else if (checks >= 40 && checks <= 59)
		checkFees = balance * 0.06;
	else
		checkFees = balance * 0.04;
	
	serviceFees += checkFees;

	cout << fixed << setprecision(2);
	cout << "Service fees: $" << serviceFees << endl;

	return 0;
}