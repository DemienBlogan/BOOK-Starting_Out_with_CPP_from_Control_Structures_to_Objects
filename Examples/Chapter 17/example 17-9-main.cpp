#include <iostream>
#include <vector>
#include "example 17-9-Product.h"
using namespace std;

int main()
{	
	// Create a vector to hold the Products.
	vector<Product> products;

	// Add Products to the vector.
	products.emplace_back("T-Shirt", 20);
	products.emplace_back("Calendar", 25);
	products.emplace_back("Coffe Mug", 30);

	// Use an iterator to display the vector contents.
	for (auto it = products.begin(); it != products.end(); it++)
	{
		cout << "Product: " << it->getName() << endl
			<< "Units: " << it->getUnits() << endl;
	}

	return 0;
}