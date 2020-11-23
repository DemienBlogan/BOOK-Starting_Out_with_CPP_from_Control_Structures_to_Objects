/*
3. Winning Division
Write a program that determines which of a company's four divisions (Northeast,
Southeast, Northwest, and Sourthwest) had the greatest sales for a quarter. It should
include the following two functions, which are called by main:

- double getSales() is passed the name of a division. It asks the user for a division's
  quarterly sales figure, validates the input, then returns it. It should be called once for
  each division.
- void findHighest() is passed the four sales totals. It determines which is the largest
  and prints the name of the high-grossing division, along with its sales figure.

Input Validation: Do not accept dollar amounts less than $0.00.
*/

#include <iostream>
#include <iomanip>
#include <string>

double getSales(const std::string& divisionName);
void findHighest(double sale1, double sale2, double sale3, double sale4);

int main()
{
	double sale1, sale2, sale3, sale4;

	sale1 = getSales("Northeast");
	sale2 = getSales("Southeast");
	sale3 = getSales("Northwest");
	sale4 = getSales("Southwest");

	findHighest(sale1, sale2, sale3, sale4);

	return 0;
}

double getSales(const std::string& divisionName)
{
	using namespace std;

	cout << "Enter the sales figure for " << divisionName << ": ";
	double sale;
	cin >> sale;

	if (sale < 0)
	{
		cout << "Incorrect sale.\n";
		exit(0);
	}

	return sale;
}

void findHighest(double sale1, double sale2, double sale3, double sale4)
{
	using namespace std;

	double sale1sale2Max = sale1 > sale2 ? sale1 : sale2;
	double sale3sale4Max = sale3 > sale4 ? sale3 : sale4;
	double salesMax = sale1sale2Max > sale3sale4Max ? sale1sale2Max : sale3sale4Max;

	cout << fixed << setprecision(2);

	if (salesMax == sale1)
		cout << "The high-grossing division: Northeast (with sale $" << salesMax << ").\n";
	else if (salesMax == sale2)
		cout << "The high-grossing division: Southeast (with sale $" << salesMax << ").\n";
	else if (salesMax == sale3)
		cout << "The high-grossing division: Northwest (with sale $" << salesMax << ").\n";
	else
		cout << "The high-grossing division: Southwest (with sale $" << salesMax << ").\n";
}