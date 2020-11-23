/*
8. Total Purchase
A customer in a store is purchasing five items. The prices of the five items are as follows:

Price of item 1 = $15.95
Price of item 2 = $24.95
Price of item 3 = $6.95
Price of item 4 = $12.95
Price of item 5 = $3.95

Write a program that holds the prices of the five items in five variables . Display each
item's price, the subtotal of the sale, the amount of sales tax, and the total. Assume the
sales tax is 7 percent.
*/

#include <iostream>
#include <iomanip>

int main()
{
	using namespace std;

	// Prices ($):
	double item1 = 15.95, item2 = 24.95, item3 = 6.95, item4 = 12.95, item5 = 3.95;
	
	const double TAX_PERCENT = 0.07; // 7%

	// Taxes ($):
	double tax1 = item1 * TAX_PERCENT;
	double tax2 = item2 * TAX_PERCENT;
	double tax3 = item3 * TAX_PERCENT;
	double tax4 = item4 * TAX_PERCENT;
	double tax5 = item5 * TAX_PERCENT;

	double subtotal = item1 + item2 + item3 + item4 + item5;
	double amountOfTax = tax1 + tax2 + tax3 + tax4 + tax4;
	double total = subtotal - amountOfTax;

	cout << fixed << setprecision(2);
	
	cout << " --- Items prices --- \n";
	cout << "Item #1 = $" << item1 << endl;
	cout << "Item #2 = $" << item2 << endl;
	cout << "Item #3 = $" << item3 << endl;
	cout << "Item #4 = $" << item4 << endl;
	cout << "Item #5 = $" << item5 << endl;

	cout << endl;

	cout << " --- Tax prices --- \n";
	cout << "Tax #1 = $" << tax1 << endl;
	cout << "Tax #2 = $" << tax2 << endl;
	cout << "Tax #3 = $" << tax3 << endl;
	cout << "Tax #4 = $" << tax4 << endl;
	cout << "Tax #5 = $" << tax5 << endl;

	cout << endl;
	
	cout << "Subtotal = $" << subtotal << endl;
	cout << "Amount of tax = $" << amountOfTax << endl;
	cout << "Total = $" << total << endl;

	return 0;
}