/*
13. Inventory Program
Write a program that uses a structure to store the following inventory data in a file:
- Item Description
- Quantity on Hand
- Wholesale Cost
- Retail Cost
- Date Added to Inventory

The program should have a menu allows the user to perform the following tasks:
- Add new records to the file
- Display any record in the file
- Change any record in the file

Input Validation: The program should not accept quantities, or wholesale or retail
costs, less then 0. The program should not accept dates that the programmer determines
are unreasonable.
*/

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct Inventory
{
	string itemDescription;
	int quantityOnHand;
	double wholesaleCost;
	double retailCost;
	string dateAdded;
};

void Show(ostream& os, const Inventory inventory[], size_t size);
Inventory* AddNewRecord(Inventory inventory[], size_t& size);
void ChangeRecord(Inventory& item);
void ChangeRecordInInventory(Inventory inventory[], size_t size);
double EnterValue();

int main()
{
	ofstream file("Inventory.txt");
	Inventory* inventory = nullptr;
	size_t size = 0;
	char menuItem;

	do
	{
		cout << "1 - Show inventory \n";
		cout << "2 - Add new record \n";
		cout << "3 - Change record  \n";
		cout << "4 - Save in file   \n";
		cout << "0 - Quit           \n";
		cout << "Select menu item: ";

		cin >> menuItem;

		while (cin.get() != '\n')
			continue;

		switch (menuItem)
		{
		case '0': // No code
			break;

		case '1':
			Show(cout, inventory, size);
			break;

		case '2':
			inventory = AddNewRecord(inventory, size);
			break;

		case '3':
			ChangeRecordInInventory(inventory, size);
			break;

		case '4':
			Show(file, inventory, size);
			break;

		default:
			cout << "Incorrect digit. Try again.\n";
			break;
		}

		system("pause");
		system("cls");

	} while (menuItem != '0');

	file.close();

	return 0;
}

void Show(ostream& os, const Inventory inventory[], size_t size)
{
	if (size == 0)
		os << "Inventory is empty.\n";
	else
	{
		for (size_t i = 0; i < size; i++)
		{
			os << "Item #" << i + 1 << ":\n";
			os << "\t Item Description: " << inventory[i].itemDescription << endl;
			os << "\t Quantity on Hand: " << inventory[i].quantityOnHand << endl;
			os << "\t Wholesale Cost:   " << inventory[i].wholesaleCost << endl;
			os << "\t Retail Cost:      " << inventory[i].retailCost << endl;
			os << "\t Date Added:       " << inventory[i].dateAdded << endl;
		}
	}
}

Inventory* AddNewRecord(Inventory inventory[], size_t& size)
{
	if (size == 0)
	{
		inventory = new Inventory[1];
		ChangeRecord(inventory[0]);
		size++;
	}
	else
	{
		Inventory* newInventory = new Inventory[size + 1];

		for (size_t i = 0; i < size; i++)
			newInventory[i] = inventory[i];
		ChangeRecord(newInventory[size]);
		size++;

		delete[] inventory;
		inventory = newInventory;
	}

	cout << "New item was added.\n";

	return inventory;
}

void ChangeRecord(Inventory& item)
{
	cout << "Enter item description: ";
	getline(cin, item.itemDescription);

	cout << "Enter quantity on Hand: ";
	item.quantityOnHand = EnterValue();

	cout << "Enter wholesale cost: $";
	item.wholesaleCost = EnterValue();

	cout << "Enter retail cost: $";
	item.retailCost = EnterValue();

	cout << "Enter date added to Inventory:\n";
	cout << "\t Day: ";
	int day = EnterValue();
	cout << "\t Month: ";
	int month = EnterValue();
	cout << "\t Year: ";
	int year = EnterValue();

	item.dateAdded = to_string(day);
	item.dateAdded += '.';
	item.dateAdded += to_string(month);
	item.dateAdded += '.';
	item.dateAdded += to_string(year);
}

void ChangeRecordInInventory(Inventory inventory[], size_t size)
{
	if (size == 0)
	{
		cout << "Inventory is empty.\n";
		return;
	}

	cout << "Enter index of record (1 ... " << size << "): ";
	size_t index;
	cin >> index;
	cin.ignore();

	index--;

	ChangeRecord(inventory[index]);
	cout << "Item was changed.\n";
}

double EnterValue()
{
	double value;

	do
	{
		cin >> value;
		cin.ignore();

		if (value < 0)
			cout << "Incorrect value. Try again.\n";

	} while (value < 0);

	return value;
}