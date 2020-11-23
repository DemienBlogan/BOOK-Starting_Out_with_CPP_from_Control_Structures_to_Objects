/*
2. Stadium Seating
There are three seating categories at a stadium. For a softball game, Class A sears cost
$15, Class B seats cost $12, and Class C seats cost $9. Write a program that asks how
many tickers for each class of seats were sold, then displays the amount of income generated
from ticket sales. Format your dollar amount in fixed-point notarion, with two
decimal places of precision, and be sure the decimal point is always displayed.
*/

#include <iostream>
#include <iomanip>

int main()
{
	using namespace std;

	double classACost = 15.00, classBCost = 12.00, classCCost = 9.00;

	cout << "Enter tickets that were sold for A class: ";
	int classATickets;
	cin >> classATickets;

	cout << "Enter tickets that were sold for B class: ";
	int classBTickets;
	cin >> classBTickets;

	cout << "Enter tickets that were sold for C class: ";
	int classCTickets;
	cin >> classCTickets;

	double classAIncome = classACost * classATickets;
	double classBIncome = classBCost * classBTickets;
	double classCIncome = classCCost * classCTickets;
	double totalIncome = classAIncome + classBIncome + classCIncome;

	cout << "\n --- Classes Tickes sold --- \n";
	cout << "Class A: " << classATickets << endl;
	cout << "Class B: " << classBTickets << endl;
	cout << "Class C: " << classCTickets << "\n\n";

	cout << fixed << setprecision(2);
	cout << " --- Classes Costs --- \n";
	cout << "Class A: $" << classACost << endl;
	cout << "Class B: $" << classBCost << endl;
	cout << "Class C: $" << classCCost << "\n\n";

	cout << " --- Classes Income --- \n";
	cout << "Class A: $" << classAIncome << endl;
	cout << "Class B: $" << classBIncome << endl;
	cout << "Class C: $" << classCIncome << "\n\n";

	cout << "Total income = $" << totalIncome << endl;

	return 0;
}