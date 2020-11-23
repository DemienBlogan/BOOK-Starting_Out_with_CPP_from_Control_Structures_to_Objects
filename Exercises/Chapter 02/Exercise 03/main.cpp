/*
3. Sales Tax
Write a program that will compute the total sales tax on a $95 purchase. Assume the
state sales tax in 4 percent, and the county sales tas is 2 percent.
*/

#include <iostream>
#include <iomanip>

int main()
{
	using namespace std;

	double purchase = 95.00; // $
	const double STATE_SALES_TAX_PERCENT = 0.04, COUNTY_SALES_TAX_PERSENT = 0.02;
	double stateSalesTax = purchase * STATE_SALES_TAX_PERCENT;
	double countySalesTax = purchase * COUNTY_SALES_TAX_PERSENT;
	double totalSalesTax = stateSalesTax + countySalesTax;

	cout << fixed << setprecision(2);
	cout << "Purchase = $" << purchase << endl;
	cout << "State sales tax  = $" << stateSalesTax << endl;
	cout << "County sales tax = $" << countySalesTax << endl;
	cout << "Total sales tax = $" << totalSalesTax << endl;

	return 0;
}