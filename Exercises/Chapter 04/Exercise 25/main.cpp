/*
25. Mobile Service Provider
A mobile phone service provider has three different data plans for its customers:
Package A: For $39.99 per month, 4 gigabytes are provided. Additional data costs
           $10 per gigabyte.
Package B: For $59.99 per month, 8 gigabytes are provided. Additional data costs
           $5 per gigabyte.
Package C: For $69.99 per month, unlimited data is provided.
Write a program that calculates a customer's monthly bill. It should ask which package
the customer has purchased and how many gigabytes were used. It should then display
the total amount due.
Input Validation: Be sure the user only select package A, B, or C.
*/

#include <iostream>
#include <iomanip>

int main()
{
	using namespace std;

	cout << "Package A: For #39.99 per month, 4 gigabytes are provided. Additional data costs\n";
	cout << "           $10 per gigabyte.\n\n";
	cout << "Package B: For #59.99 per month, 8 gigabytes are provided. Additional data costs\n";
	cout << "           $5 per gigabyte.\n\n";
	cout << "Package C: For #69.99 per month, unlimited data is provided.\n\n";
	cout << "Select package: ";
	char package;
	cin >> package;

	if ((package < 'a' || package > 'c') && (package < 'A' || package > 'C'))
	{
		cout << "Incorrect package.\n";
		return 0;
	}

	cout << "Enter how many gigabytes were used: ";
	int usedGigabytes;
	cin >> usedGigabytes;

	double amountDue; // $

	switch (package)
	{
	case 'A':
	case 'a':
		usedGigabytes -= 4;
		amountDue = usedGigabytes > 0 ? usedGigabytes * 10.00 + 39.99 : 39.99;
		break;
	case 'B':
	case 'b':
		usedGigabytes -= 8;
		amountDue = usedGigabytes > 0 ? usedGigabytes * 5.00 + 59.99 : 59.99;
		break;
	case 'C':
	case 'c':
		amountDue = 69.99;
		break;
	}

	cout << fixed << setprecision(2);
	cout << "Amount due = $" << amountDue << endl;

	return 0;
}