/*
17. Sales Bar Chart
Write a program that asks the user to enter today's sales for five stores. The program
should then display a bar graph comparing each store's sales. Create each bar in the bar
graph by displayin a row of asterisks. Each asterisk should represent $100 of sales.
*/

#include <iostream>

int main()
{
	using namespace std;

	const int SIZE = 5;
	int sales[SIZE];

	for (int i = 0; i < SIZE; i++)
	{
		cout << "Enter today's sales for store 1: ";
		cin >> sales[i];
	}

	cout << "SALES BAR CHART\n";
	cout << "(Each * =  $100)\n";
	for (int i = 0; i < SIZE; i++)
	{
		cout << "Store " << i + 1 << ": ";
		
		double asterisks = sales[i] / 100;
		for (int j = 0; j < asterisks; j++)
			cout << '*';
		cout << endl;
	}

	return 0;
}