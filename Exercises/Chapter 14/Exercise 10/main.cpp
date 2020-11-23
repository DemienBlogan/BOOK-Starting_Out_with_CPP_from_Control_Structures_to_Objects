/*
10. Corporate Sales
A corporation has six divisions, each responsible for sales to different geographic locations.
Design a DivSales class that keeps sales data for a division, with the following
members:

- An array with four elements for holding four quarters of sales figures for the division.
- A private static variable for holding the total corporate sales for all divisions for the
  entire year.
- A member function that takes four arguments, each assumed to be the sales for a
  quarter. The value of the arguments should be copied into the array that holds the
  sales data. The total of the four arguments should be added to the static variable
  that holds the total yearly corporate sales.
- A function that takes an integer argument within the range of 0-3. The argument is
  to be used as a subscript into the division quarterly sales array. The function should
  return the value of the array element with that subscript.

Write a program that creates an array of six DivSales objects. The program should
ask the user to enter the sales for four quarters for each division. After the data are
entered, the program should display a table showing the division sales for each quarter.
The program should then display the total corporate sales for the year.

Input Validation: Only accept positive values for quarterly sales figures.
*/

#include <iostream>
#include <iomanip>
#include "DivSales.h"

using std::cout;
using std::cin;
using std::endl;
using std::fixed;
using std::setprecision;

int main()
{
	const size_t AMOUNT = 6;
	DivSales divisions[AMOUNT];
	double sale1, sale2, sale3, sale4;

	for (size_t i = 0; i < AMOUNT; i++)
	{
		cout << "Division #" << i + 1 << ":\n";
		cout << "\tEnter sale #1: $";
		cin >> sale1;
		cout << "\tEnter sale #2: $";
		cin >> sale2;
		cout << "\tEnter sale #3: $";
		cin >> sale3;
		cout << "\tEnter sale #4: $";
		cin >> sale4;

		divisions[i].SetSales(sale1, sale2, sale3, sale4);
	}

	system("cls");

	cout << fixed << setprecision(2);

	for (size_t i = 0; i < AMOUNT; i++)
	{
		cout << "Division #" << i + 1 << ":\n";

		for (size_t j = 0; j < 4; j++)
			cout << "\tQuarter #" << j + 1 << " = $" << divisions[i].GetQuarter(j) << endl;
	}

	cout << "Total sales = $" << DivSales::GetTotalSales() << endl;

	return 0;
}