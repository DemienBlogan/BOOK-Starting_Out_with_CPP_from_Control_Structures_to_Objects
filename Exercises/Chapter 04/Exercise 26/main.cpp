/*
26. Mobile Service Provider, Part 2
Modify the Program in Programming Challenge 25 so it also displays how much money
Package A customers would save if they purchased packages B or C, and how much
money Package B customers would save if they purchased Package C. If there would
be no savings, no message should be printed.
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

	usedGigabytes -= 4;
	double amountDueA = usedGigabytes > 0 ? usedGigabytes * 10.00 + 39.99 : 39.99;
	double amountDueB = usedGigabytes > 0 ? usedGigabytes * 5.00 + 59.99 : 59.99;
	double amountDueC = 69.99;

	cout << fixed << setprecision(2);

	switch (package)
	{
	case 'A':
	case 'a':
		cout << "Amount due = $" << amountDueA << endl;
		if (amountDueA - amountDueB > 0)
			cout << "With Package B you could save $" << amountDueA - amountDueB << endl;
		if (amountDueA - amountDueC > 0)
			cout << "With Package C you could save $" << amountDueA - amountDueC << endl;
		break;

	case 'B':
	case 'b':
		cout << "Amount due = $" << amountDueB << endl;
		if (amountDueB - amountDueC > 0)
			cout << "With Package C you could save $" << amountDueB - amountDueC << endl;
		break;

	case 'C':
	case 'c':
		cout << "Amount due = $" << amountDueC << endl;
		break;
	}

	return 0;
}