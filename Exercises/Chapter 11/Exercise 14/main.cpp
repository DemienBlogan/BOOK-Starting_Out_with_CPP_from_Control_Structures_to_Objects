/*
14. Inventory Bins
Write a program that simulates inventory bins in a warehouse. Each bin holds a number
of the same type of parts. The program should use a structure that keeps the following data:
	Description of the part kept in the bin.
	Number of parts in the bin.
The program should have an array of 10 bins, initialized with the following data:
-----------------------------------------------------
Part Description           Number of Parts in the Bin
-----------------------------------------------------
Valve                      10
Bearing                    5
Bushing                    15
Coupling                   21
Flange                     7
Gear                       5
Gear Housing               5
Vacuum Gripper             25
Cable                      18
Rod                        12
-----------------------------------------------------

The program should have the following functions:
AddParts - increases a specific bin's part count by a specified number.
RemoveParts - decreases a specific bin's part count by a specified number.

When the program runs, it should repeat a loop that performs the following steps:
The user should see a list of what each bin holds and how many parts are in each bin. The
user can choose to either quit the program or select a bin. When a bin is selected, the user
can either add parts to it or remove parts from it. The loop then repeats, showing the
updated bin data on the screen.

Input Validation: No bin can hold more than 30 parts, so don't let the user add more
than a bin can hold. Also, don't accept negative values for the number of parts being
added or removed.
*/

#include <iostream>
#include <string>

using namespace std;

enum class MenuItem
{
	ADD_PARTS,
	REMOVE_PARTS,
	QUIT
};

struct Bin
{
	string description;
	int amount;
};

void AddParts(Bin bins[], size_t size, size_t binIndex, int parts);
void RemoveParts(Bin bins[], size_t size, size_t binIndex, int parts);
void ShowBins(const Bin bins[], size_t size);
void ShowMenu();
MenuItem SelectMenuItem();
size_t EnterBinIndex(size_t size);
int EnterParts();
void AnylizeMenuItem(Bin bins[], size_t size, MenuItem item);
void ClearBuffer();

int main()
{
	MenuItem item;
	const size_t SIZE = 10;
	Bin bins[SIZE] =
	{
		{ "Valve",  10 },
		{ "Bearing",  5 },
		{ "Bushing",  15 },
		{ "Coupling",  21 },
		{ "Flange",  7 },
		{ "Gear",  5 },
		{ "Gear Housing",  5 },
		{ "Vaccum Gripper",  25 },
		{ "Cable",  18 },
		{ "Rod",  12 },
	};

	do
	{
		ShowBins(bins, SIZE);
		ShowMenu();
		item = SelectMenuItem();
		AnylizeMenuItem(bins, SIZE, item);

	} while (item != MenuItem::QUIT);

	return 0;
}

void AddParts(Bin bins[], size_t size, size_t binIndex, int parts)
{
	if (bins == nullptr)
	{
		cerr << "ERROR #1: bins = nullptr in 'AddParts' function.\n";
		exit(1);
	}

	if (binIndex >= size)
	{
		cerr << "ERROR #2: Incorrect bin index in 'AddParts' function.\n";
		exit(2);
	}

	if (parts < 0)
	{
		cerr << "ERROR #3: Incorrect number of parts in 'AddParts' function.\n";
		exit(3);
	}

	if (size == 0)
	{
		cout << "Bins are empty.\n";
		return;
	}

	if (bins[binIndex].amount + parts > 30)
		cout << "Too many parts. Operation cannot been done.\n";
	else
		bins[binIndex].amount += parts;
}

void RemoveParts(Bin bins[], size_t size, size_t binIndex, int parts)
{
	if (bins == nullptr)
	{
		cerr << "ERROR #1: bins = nullptr in 'RemoveParts' function.\n";
		exit(1);
	}

	if (binIndex >= size)
	{
		cerr << "ERROR #2: Incorrect bin index in 'RemoveParts' function.\n";
		exit(2);
	}

	if (parts < 0)
	{
		cerr << "ERROR #3: Incorrect number of parts in 'RemoveParts' function.\n";
		exit(3);
	}

	if (size == 0)
	{
		cout << "Bins are empty.\n";
		return;
	}

	if (bins[binIndex].amount - parts < 0)
		cout << "Too many parts. Operation cannot been done.\n";
	else
		bins[binIndex].amount -= parts;
}

void ShowBins(const Bin bins[], size_t size)
{
	if (bins == nullptr)
	{
		cerr << "ERROR #1: bins = nullptr in 'ShowBins' function.\n";
		exit(1);
	}

	if (size == 0)
	{
		cout << "Bins are empty.\n";
		return;
	}

	cout << "--------------- Warehouse ------------------ \n";
	for (size_t i = 0; i < size; i++)
		cout << "Bin #" << i << ". Description: " << bins[i].description << ". Amount = " << bins[i].amount << endl;
	cout << "-------------------------------------------- \n\n";
}

void ShowMenu()
{
	cout << "----------------- Menu --------------------- \n";
	cout << "|          0 - Add new parts               | \n";
	cout << "|          1 - Remove parts                | \n";
	cout << "|          2 - Quit                        | \n";
	cout << "-------------------------------------------- \n\n";
}

MenuItem SelectMenuItem()
{
	char charItem;

	do
	{
		cout << "Select menu item: ";
		cin >> charItem;

		ClearBuffer();

		if (charItem < '0' || charItem > '2')
			cout << "Incorrect input. Try again.\n";

	} while (charItem < '0' || charItem > '2');

	system("cls");

	int intItem = charItem - '0';
	MenuItem menuItem = static_cast<MenuItem>(intItem);

	return menuItem;
}

size_t EnterBinIndex(size_t size)
{
	size_t binIndex;

	do
	{
		cout << "Enter bin index (0..." << size << "): ";
		cin >> binIndex;

		if (!cin)
		{
			cin.clear();
			ClearBuffer();
			binIndex = size;
			cout << "Incorrect input. Try again.\n";
		}
		else if (binIndex >= size)
			cout << "Incorrect index. Try again.\n";

	} while (binIndex >= size);

	return binIndex;
}

int EnterParts()
{
	int parts;

	do
	{
		cout << "Enter amount of parts: ";
		cin >> parts;

		if (!cin)
		{
			cin.clear();
			ClearBuffer();
			parts = -1;
			cout << "Incorrect input. Try again.\n";
		}
		else if (parts < 0)
			cout << "Incorrect amount. Try again.\n";

	} while (parts < 0);

	ClearBuffer();

	return parts;
}

void AnylizeMenuItem(Bin bins[], size_t size, MenuItem item)
{
	if (bins == nullptr)
	{
		cerr << "ERROR #1: bins = nullptr in 'AnylizeMenuItem' function.\n";
		exit(1);
	}

	if (size == 0)
	{
		cout << "Bins are empty.\n";
		return;
	}

	int parts;
	size_t binIndex;

	switch (item)
	{
	case MenuItem::ADD_PARTS:
		parts = EnterParts();
		binIndex = EnterBinIndex(size);
		AddParts(bins, size, binIndex, parts);
		break;

	case MenuItem::REMOVE_PARTS:
		parts = EnterParts();
		binIndex = EnterBinIndex(size);
		RemoveParts(bins, size, binIndex, parts);
		break;

	case MenuItem::QUIT:
		cout << "Goodbye!\n";
		break;

	default:
		cerr << "ERROR #4: menu item is incorrect in 'AnylizeMenuItem'.\n";
		exit(4);
	}
}

void ClearBuffer()
{
	while (cin.get() != '\n')
		continue;
}