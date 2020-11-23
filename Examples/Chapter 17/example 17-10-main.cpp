#include <iostream>
#include <vector>
#include "example 17-10-Product.h"
using namespace std;

int main()
{
	// Create a vector to hold the Products.
	vector<Product> products =
	{
		Product("T-Shirt", 20),
		Product("Coffe Mug", 30),
	};

	// Get an iterator to the 2nd element.
	auto it = products.begin() + 1;

	// Insert another Product into the vector.
	products.emplace(it, "Calendar", 25);

	// Display the vector elements.
	for (auto element : products)
	{
		cout << "Product: " << element.getName() << endl
			<< "Units: " << element.getUnits() << endl;
	}

	return 0;
}