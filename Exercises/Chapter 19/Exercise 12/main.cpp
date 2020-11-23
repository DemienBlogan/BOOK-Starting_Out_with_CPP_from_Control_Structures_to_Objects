/*
12. Inventory Bin Stack
Design an inventory class that stores the following members:

serialNum:     An integer that holds a part's serial number.
manufactDate:  A member that holds the date the part was manufactured.
lotNum:        An integer that holds the part's lot number.

The class should have appropriate member functions for storing data into, and retrieving
data from, these members.

Next, design a stack class that can hold objects of the class described above. If you
wish, you may use the template you designed in Programming Challenge 1 or 2.

Last, design a program that uses the stack class described above. The program should
have a loop that asks the user if he or she wishes to add a part to inventory, or take a
part from inventory. The loop should repeat until the user is finished.

If the user wishes to add a part to inventory, the program should ask for the serial
number, date of manufacture, and lot number. The data should be stored in an inventory
object, and pushed onto the stack.

If the user wishes to take a part from inventory, the program should pop the top-most
part from the stack and display the contents of its member variables.

When the user finishes the program, it should display the contents of the member values
of all the objects that remain on the stack.
*/

#include <iostream>
#include "Inventory.h"
#include "Stack.h"
#include "Interface.h"

int main()
{
	Stack<Inventory> inventoryBin;
	Inventory inventory;
	char menuItem;

	do
	{
		ShowMenu();
		menuItem = SelectMenuItem();

		switch (menuItem)
		{
		case '0':
			continue;
		case '1':
			inventory = EnterInventory();
			inventoryBin.Push(inventory);
			std::cout << "New part was added.\n";
			break;

		case '2':
			if (!inventoryBin.IsEmpty())
			{
				std::cout << "New part was removed.\n";
				inventoryBin.Pop(inventory);
			}
			else
				std::cout << "Inventory bin is empty.\n";
			break;

		default:
			std::cout << "Incorrect input. Try again.\n";
			break;
		}

	} while (menuItem != '0');

	system("cls");

	if (inventoryBin.IsEmpty())
		std::cout << "Inventory bin is empty.\n";
	else
	{
		std::cout << "All parts of inventory:\n";

		for (size_t i = 0; !inventoryBin.IsEmpty(); i++)
		{
			inventoryBin.Pop(inventory);

			std::cout << "Part #" << i + 1 << ":\n";
			std::cout << "\tSerial Num:    " << inventory.GetSerialNum() << std::endl;
			std::cout << "\tLot Num:       " << inventory.GetLotNum() << std::endl;
			std::cout << "\tManufact Date: " << inventory.GetManufactDate() << std::endl;
		}
	}

	return 0;
}