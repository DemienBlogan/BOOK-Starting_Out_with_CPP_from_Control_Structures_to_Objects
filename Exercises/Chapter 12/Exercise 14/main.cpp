/*
14. Inventory Screen Report
Write a program that reads the data in the file created by the program in Programming
Challenge 13. The program should calculate and display the following data:
- The total wholesale value of the inventory
- The total retail value of the inventory
- The total quantity of all items in the inventory
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

void Show(const Inventory inventory[], size_t size);
void ReadFromFile(ifstream& file, Inventory** inventory, size_t& size);

int main()
{
	ifstream file("Inventory.txt");

	if (!file.is_open())
	{
		cerr << "File could not been opened.\n";
		return 1;
	}

	Inventory* inventory = nullptr;
	size_t size = 0;

	ReadFromFile(file, &inventory, size);
	file.close();

	double totalWholesale = 0;
	int totalItemsAmount = 0;
	double totalRetailCost = 0;

	for (size_t i = 0; i < size; i++)
	{
		totalWholesale += inventory[i].wholesaleCost;
		totalItemsAmount += inventory[i].quantityOnHand;
		totalRetailCost += inventory[i].retailCost;
	}

	cout << "Total wholesale = " << totalWholesale << endl;
	cout << "Total amount of itmes = " << totalItemsAmount << endl;
	cout << "Total retail cost = " << totalRetailCost << endl;

	if (inventory != nullptr)
		delete[] inventory;

	return 0;
}

void Show(const Inventory inventory[], size_t size)
{
	if (size == 0)
		cout << "Inventory is empty.\n";
	else
	{
		for (size_t i = 0; i < size; i++)
		{
			cout << "Item #" << i + 1 << ":\n";
			cout << "\t Item Description: " << inventory[i].itemDescription << endl;
			cout << "\t Quantity on Hand: " << inventory[i].quantityOnHand << endl;
			cout << "\t Wholesale Cost:   " << inventory[i].wholesaleCost << endl;
			cout << "\t Retail Cost:      " << inventory[i].retailCost << endl;
			cout << "\t Date Added:       " << inventory[i].dateAdded << endl;
		}
	}
}

void ReadFromFile(ifstream& file, Inventory** inventory, size_t& size)
{
	file >> size;
	file.ignore();

	*inventory = new Inventory[size];

	for (size_t i = 0; i < size; i++)
	{
		getline(file, (*inventory)[i].itemDescription);
		file >> (*inventory)[i].quantityOnHand;
		file >> (*inventory)[i].wholesaleCost;
		file >> (*inventory)[i].retailCost;
		file.ignore();
		getline(file, (*inventory)[i].dateAdded);
	}
}