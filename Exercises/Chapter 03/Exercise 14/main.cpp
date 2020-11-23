/*
14. Monthly Sales Tax
A retail company must file a monthly sales tax report listing the sales for the month and
the amount of sales tax collected. Write a program that asks for the month, the year,
and the total amount collected at the cash register (i.e. sales plus sales tax). Assume the
state sales tax is 4 percent, and the county sales tax is 2 percent.
If the total amount collected is known and the total sales tax is 6 percent, the amount
of product sales may be calculated as:
S = T / 1.06
S is the product sales and T is the total income (product sales plus sales tax).
The program should display a report similar to:
Month : October
---------------------
Total Collected: $ 26572.89
Sales:           $ 25068.76
Count Sales Tax: $ 501.38
State Sales Tax: $ 1002.75
Total Sales Tax: $ 1504.13
*/

#include <iostream>
#include <iomanip>

int main()
{
	using namespace std;

	cout << "Enter a month: ";
	string monthName;
	cin >> monthName;

	cout << "Enter a year: ";
	int year;
	cin >> year;

	cout << "Enter the total amount collected: $";
	double totalCollected;
	cin >> totalCollected;

	const double COUNTY_SALES_TAX_PERCENT = 0.02; // 2%
	const double STATE_SALES_TAX_PERCENT = 0.04;  // 4%

	double sales = totalCollected / 1.06;
	double countySalesTax = totalCollected * COUNTY_SALES_TAX_PERCENT;
	double stateSalesTax = totalCollected * STATE_SALES_TAX_PERCENT;
	double totalSalesTax = countySalesTax + stateSalesTax;
	
	cout << "\nMonth: " << monthName << " (" << year << " year) \n";
	cout << "--------------------------- \n";
	cout << fixed << setprecision(2);
	cout << "Total Collected:  $" << totalCollected << endl;
	cout << "Sales:            $" << sales << endl;
	cout << "County Sales Tax: $" << countySalesTax << endl;
	cout << "State Sales Tax:  $" << stateSalesTax << endl;
	cout << "Total Sales Tax:  $" << totalSalesTax << endl;

	return 0;
}