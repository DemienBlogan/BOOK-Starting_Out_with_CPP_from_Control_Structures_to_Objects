#include <iostream>
#include <string>
#include <array>
using namespace std;

int main()
{
	const int SIZE = 3;

	// Store some names in an array object.
	array<string, SIZE> names = { "Sarah", "William", "Alfredo" };

	// Create an iterator for the array object.
	array<string, SIZE>::iterator it;

	// Display the names.
	cout << "Here are the names:\n";
	for (it = names.begin(); it != names.end(); it++)
		cout << *it << endl;

	return 0;
}