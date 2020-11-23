/*
2. Sales Prediction
The East Coast sales division of a company generates 58 percent of total sales. Based
on that percentage, write a program that will predict how much the East Coast division
will generate if the company has $8,6 million in sales this year.
*/

#include <iostream>
#include <iomanip>

int main()
{
	using namespace std;

	double sales = 8.6;
	const double PERCENT_OF_EAST_COAST = 0.58;
	
	cout << "Sales this year = $" << sales << endl;
	cout << "The East Coast sales percent = " << PERCENT_OF_EAST_COAST * 100 << endl;

	double eastCoastSales = sales * PERCENT_OF_EAST_COAST;
	cout << fixed << setprecision(2);
	cout << "The East Coast sales = $" << eastCoastSales << " milion \n";

	return 0;
}