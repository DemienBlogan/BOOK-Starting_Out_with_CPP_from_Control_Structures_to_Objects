/*
17. Cash Register
Design a CashRegister class that can be used with the InventoryItem class discussed
in this chapter. The CashRegister class should perform the following:
1. Ask the user for the item and quntity being purchased.
2. Get the item's cost from the InventoryItem object.
3. Add a 30 percent profit to the cost to get the item's unit price.
4. Multiply the unit price times the quantity being purchased to get the purchase subtotal.
5. Compute a 6 percent sales tax on the subtotal to get the purchase total.
6. Display the purchase subtotal, tax, and total on the screen.
7. Substract the quantity being purchased from the onHand vairable of the InventoryItem
   class object.

Implement both classes in a complete program. Feel free to modify the InventoryItem
class in any way necessary.

Input Validation: Do not accept a negative value for the quantity of items being
purchased.
*/

#include <iostream>

#include "CashRegister.h"

using std::cout;

int main()
{
	CashRegister cashRegister{ "Coca-Cola", 5.99, 20 };

	cashRegister.Show();
	cout << "------------------\n";

	cashRegister.AddProfit();

	cashRegister.Show();
	cout << "------------------\n";

	cashRegister.EnterQuantity();

	cashRegister.Show();
	cout << "------------------\n";

	return 0;
}