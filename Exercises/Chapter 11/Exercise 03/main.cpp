/*
3. Corporate Sales Data
Write a program that uses a stucture to store the following data on a company division:
	Division Name (such as East, West, North, or South)
	First-Quarter Sales
	Second-Quarter Sales
	Third-Quarter Sales
	Fourth-Quarter Sales
	Total Annual Sales
	Average Quartery Sales

The program should use four variables of this structure. Each variable should represent
one of the following corporate divisions: East, West, North, and South. The user
should be asked for the four quarters' sales figures for each division. Each division's
total and average sales should be calculated and stored in the appropriate member of
each structure variable. These figures should then be displayed on the screen.

Input Validation: Don not accept negative members for any sales figures.
*/

#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

struct CorporateSales
{
	string divisionName;
	double firstQuarterSales;
	double secondQuarterSales;
	double thirdQuarterSales;
	double fourthQuarterSales;
	double totalAnnualSales;
	double averageQuarterlySales;
};

void EnterSales(CorporateSales& division);
void CalculateSales(CorporateSales& division);
void ShowSales(const CorporateSales& division);
double EnterSale();

int main()
{
	CorporateSales division1 = { "East" };
	CorporateSales division2 = { "West" };
	CorporateSales division3 = { "North" };
	CorporateSales division4 = { "South" };

	EnterSales(division1);
	EnterSales(division2);
	EnterSales(division3);
	EnterSales(division4);

	CalculateSales(division1);
	CalculateSales(division2);
	CalculateSales(division3);
	CalculateSales(division4);

	cout << fixed << setprecision(2);
	
	ShowSales(division1);
	ShowSales(division2);
	ShowSales(division3);
	ShowSales(division4);

	return 0;
}

void EnterSales(CorporateSales& division)
{
	cout << "-------- " << division.divisionName << " division: -------\n";
	cout << "Enter 1/4 quater sales: ";
	division.firstQuarterSales = EnterSale();
	cout << "Enter 2/4 quater sales: ";
	division.secondQuarterSales = EnterSale();
	cout << "Enter 3/4 quater sales: ";
	division.thirdQuarterSales = EnterSale();
	cout << "Enter 4/4 quater sales: ";
	division.fourthQuarterSales = EnterSale();
}

void CalculateSales(CorporateSales& division)
{
	division.totalAnnualSales = division.firstQuarterSales +
		division.secondQuarterSales +
		division.thirdQuarterSales +
		division.fourthQuarterSales;

	division.averageQuarterlySales = division.totalAnnualSales / 4.0;
}

void ShowSales(const CorporateSales& division)
{
	cout << "------- " << division.divisionName << " division: -------\n";
	cout << "1/4 quater sales:        $" << division.firstQuarterSales << endl;
	cout << "2/4 quater sales:        $" << division.secondQuarterSales << endl;
	cout << "3/4 quater sales:        $" << division.thirdQuarterSales << endl;
	cout << "4/4 quater sales:        $" << division.fourthQuarterSales << endl;
	cout << "Total annual sales:      $" << division.totalAnnualSales << endl;
	cout << "Average Quarterly Sales: $" << division.averageQuarterlySales << endl;
}

double EnterSale()
{
	double sale;

	do
	{
		cin >> sale;

		if (sale < 0)
			cout << "Incorrect value. try again.\n";

	} while (sale < 0);

	return sale;
}