/*
8. How Many Widgets?
The Yukon Widger Company manufactures widgets that weigh 12.5 pounds each.
Write a program that calculates how many widgets are stacked on a pallet, based on
the total weight of the pallet. The program should ask the user how much the pallet
weighs by itself and with the widgets stacked on it. It should then calculate and display
the number of widgers stacked on the pallet.
*/

#include <iostream>

int main()
{
	using namespace std;

	const double WIDGET_WEIGHT = 12.5; // Pounds

	cout << "How much the pallet weights by itself (in pounds)?: ";
	double palletWeight;
	cin >> palletWeight;

	cout << "How much the pallet weights with the widgets stacked on it (in pounds)?: ";
	double palletWeightWithWidgets;
	cin >> palletWeightWithWidgets;

	double widgetsWeight = palletWeightWithWidgets - palletWeight;
	int amountWidgets = widgetsWeight / WIDGET_WEIGHT;

	cout << "There are " << amountWidgets << " widget(s) stacked on the pallet\n";

	return 0;
}