/*
14. Order Status
The Middletown Copper Wire Company sells spools of copper wiring for
$100 each. Write a program that displays the status of an order. The program should
have a function that asks for the following data:

- The number of spools ordered
- The number of spools in stock
- Whether there are special shopping and handling charges

(Shipping and handling is normally $10 per spool). If there are special charges, the
program should ask for the special charges per spool.

The gathered data should be passed as arguments to another function that displays:
- The number of spools ready to shop from current stock
- The number of spools on backorder (if the numbe rordered is greater than what is
  in stock)
- Subtotal of the portion ready to ship (the numbe rof spools ready to ship times
  $100)
- Total shipping and handling charges on the portion ready to ship

The shipping and handling parameter in the second function should have the default
argument 10.00.

Input Validation: Do not accept numbers less than 1 for spools ordered. Do not accept
a number less than 0 fro spools in stock or shopping and handling charges.
*/
#include <iostream>
#include <iomanip>

void MakeOrder();
void ShowOrder(int numberOfSpoolsOrdered, int numberOfSpoolsInStock, double specialCharges = 10.0);

int main()
{
	MakeOrder();
	return 0;
}

void MakeOrder()
{
	using namespace std;

	cout << "Enter the number of spools ordered: ";
	int numberOfSpoolsOrdered;
	cin >> numberOfSpoolsOrdered;

	if (numberOfSpoolsOrdered < 1)
	{
		cout << "Incorrect number of spools ordered.\n";
		exit(0);
	}

	cout << "Enter the number of spools in stock: ";
	int numberOfSpoolsInStock;
	cin >> numberOfSpoolsInStock;

	if (numberOfSpoolsInStock < 0)
	{
		cout << "Incorrect number of spools in stock.\n";
		exit(0);
	}

	cout << "Enter 'Y' if there are speacial shipping and handling charges (or 'N' if no): ";
	char answer;
	cin >> answer;

	double specialCharges = 10.0;

	if (answer == 'Y' || answer == 'y')
	{
		cout << "Enter the special charges per spool: ";
		cin >> specialCharges;

		if (specialCharges < 0)
		{
			cout << "Incorrect number of special charges per spool.\n";
			exit(0);
		}
	}

	ShowOrder(numberOfSpoolsOrdered, numberOfSpoolsInStock, specialCharges);
}

void ShowOrder(int spoolsOrdered, int spoolsStock, double specialCharges)
{
	using namespace std;

	const double SPOOL_COST = 100.00; 

	int spoolsReadyShip = spoolsStock >= spoolsOrdered ? spoolsOrdered : spoolsStock;
	int spoolsBackorder = spoolsOrdered > spoolsStock ? spoolsOrdered - spoolsStock : 0;
	double subtotalReadyShip = spoolsReadyShip * SPOOL_COST;
	double totalShippinghandling = specialCharges * spoolsReadyShip;
	double totalOrder = subtotalReadyShip + totalShippinghandling;

	cout << fixed << setprecision(2);
	cout << "The number of spools ready to ship from current stock = " << spoolsReadyShip << endl;
	cout << "The number of spools on backorder = " << spoolsBackorder << endl;
	cout << "Subtotal of the portion ready to ship = $" << subtotalReadyShip << endl;
	cout << "Total shipping and handling charges on the portion ready to ship: $" << totalShippinghandling << endl;
	cout << "Total of the order ready to ship = $" << totalOrder << endl;
}