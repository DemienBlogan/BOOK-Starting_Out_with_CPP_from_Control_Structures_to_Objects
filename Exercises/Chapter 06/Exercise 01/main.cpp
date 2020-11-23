/*
1. Markup
Write a program that asks the user to enter an item's wholesale cost ant its markup
percentage. It should then display the item's retail price. For example:

- If an item's wholesale cost is 5.00 and its markup percentage is 100 percent, then the
  item's retail price is 10.00.
- If an item's wholesale cost is 5.00 and its markup percentage is 50 percent, the the
  item's retail price is 7.50.

The program should have a function named calculateRetail that receives the
wholesale cost and the markup percentage as armuments and returns the retail price
of the item.

Input Validation: Do not accept negative values for either the wholesale cost of the item
or the markup percentage.
*/

#include <iostream>
#include <iomanip>

double calculateRetail(double wholesale, double markupPercentege);

int main()
{
	using namespace std;

	cout << "Enter wholesale: $";
	double wholesale;
	cin >> wholesale;

	if (wholesale < 0)
	{
		cout << "Incorrect wholesale.\n";
		return 0;
	}

	cout << "Enter markup percentege: ";
	double markupPercentege;
	cin >> markupPercentege;

	if (markupPercentege < 0)
	{
		cout << "Incorrect markup percentege.\n";
		return 0;
	}

	double retail = calculateRetail(wholesale, markupPercentege);

	cout << fixed << setprecision(2);
	cout << "Retail price: $" << retail << endl;

	return 0;
}

double calculateRetail(double wholesale, double markupPercentege)
{
	double retail = wholesale + wholesale * (markupPercentege / 100.0);
	return retail;
}