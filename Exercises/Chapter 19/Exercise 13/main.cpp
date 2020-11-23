/*
13. Inventory Bin Queue
Modify the program you wrote for Programming Challenge 12 (Inventory Bin Stack) so
it uses a queue instead of a stack. Compare the order in which the parts are removed
from the bin for each program.
*/

#include <iostream>
#include "Inventory.h"
#include "Queue.h"
#include "Interface.h"

int main()
{
	Queue<Inventory> inventoryBin;
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
			inventoryBin.Enqueue(inventory);
			std::cout << "New part was added.\n";
			break;

		case '2':
			if (!inventoryBin.IsEmpty())
			{
				std::cout << "New part was removed.\n";
				inventoryBin.Dequeue(inventory);
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
			inventoryBin.Dequeue(inventory);

			std::cout << "Part #" << i + 1 << ":\n";
			std::cout << "\tSerial Num:    " << inventory.GetSerialNum() << std::endl;
			std::cout << "\tLot Num:       " << inventory.GetLotNum() << std::endl;
			std::cout << "\tManufact Date: " << inventory.GetManufactDate() << std::endl;
		}
	}

	return 0;
}