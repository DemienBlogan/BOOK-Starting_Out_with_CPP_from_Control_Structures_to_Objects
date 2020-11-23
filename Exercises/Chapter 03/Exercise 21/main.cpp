/*
21. How Many Pizzas?
Modify the program you wrote in Programming Challenge 20 (Pizza Pi) so it reports
the number of pizzas you need to buy for a party if each person attending is expected
to eat an average of four slices. The program should ask the user for the number of
people who will be at the party, and for the diameter of the pizzas to be ordered. It
should then calculate and display the number of pizzas to purchase.
*/

#include <iostream>
#include <iomanip>

int main()
{
	using namespace std;

	cout << "Enter the number of people who will be at the party: ";
	int people;
	cin >> people;

	cout << "Enter the diameter of the pizza in inches: ";
	double diameterPizza;
	cin >> diameterPizza;

	const double AREA_OF_1_SLICE = 14.125; // inches
	const int PIECES_FOR_1_PERSON = 4;

	
	double radiusPizza = diameterPizza / 2;
	const double PI = 3.14159;
	double areaPizza = PI * radiusPizza * radiusPizza;
	double areaPieces = AREA_OF_1_SLICE * PIECES_FOR_1_PERSON * people;
	double pizzasNeeded = areaPieces / areaPizza;

	cout << fixed << setprecision(1);
	cout << "With this diameter and this numbe of people you\n";
	cout << "need to buy " << pizzasNeeded << " pizzas.\n";

	return 0;
}