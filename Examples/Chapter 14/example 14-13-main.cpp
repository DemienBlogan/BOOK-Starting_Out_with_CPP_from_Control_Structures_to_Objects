// This program demonstrates the IntArray class's bound-checking ability.
#include <iostream>
#include "example 14-13-IntArray.h"
using namespace std;

int main()
{
	const int SIZE = 10; // Arrya size

	// Define an IntArray with 10 elements.
	IntArray table(SIZE);

	// Store values in the array.
	for (int x = 0; x < SIZE; x++)
		table[x] = x;

	// Display the values in the array.
	for (int x = 0; x < SIZE; x++)
		cout << table[x] << " ";
	cout << endl;

	// Attempt to use an invalid subscript.
	cout << "Now attemptin to use an invalid subscript.\n";
	table[SIZE + 1] = 0;
	return 0;
}