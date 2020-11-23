/*
7. Binary String Search
Modify the binarySearch function presented in this chapter so it searches an array
of strings instead of an array of ints. The the function with a driver program.
Use Program 8-8 as a skeleton to complete. (The array must be sorted before the binary
search will work).
*/

#include <iostream>
#include <string>

using namespace std;

bool BinarySearch(const string arr[], size_t size, const string& key);

int main()
{
	const int NUM_NAMES = 20;
	string names[NUM_NAMES] = { "Collins, Bill", "Smith, Bart", "Allen, Jim",
								"Griffin, Jim", "Stamey, Marty", "Rose, Geri",
								"Taylor, Terri", "Johnson, Jill",
								"Allison, Jeff", "Looney, Joe", "Wolfe, Bill",
								"James, Jean", "Weaver, Jim", "Pore, Bob",
								"Rutherford, Greg", "Javens, Renee",
								"Harrison, Rose", "Setzer, Cathy",
								"Pike, Gordon", "Holland, Beth" };

	// Sorting
	for (size_t i = 0; i < NUM_NAMES - 1; i++)
		for (size_t j = i + 1; j < NUM_NAMES; j++)
			if (names[i] > names[j])
				std::swap(names[i], names[j]);

	// Searching
	cout << "Searching Jim Griffin: ";
	if (BinarySearch(names, NUM_NAMES, "Griffin, Jim"))
		cout << "Found\n";
	else
		cout << "Not found\n";

	cout << "Searching Demien Blogan: ";
	if (BinarySearch(names, NUM_NAMES, "Blogan, Demien"))
		cout << "Found\n";
	else
		cout << "Not found\n";

	return 0;
}

bool BinarySearch(const string arr[], size_t size, const string& key)
{
	int leftBound = 0, rightBound = size - 1;
	int middleIndex;

	while (leftBound <= rightBound)
	{
		middleIndex = (leftBound + rightBound) / 2;

		if (key > arr[middleIndex])
			leftBound = middleIndex + 1;
		else if (key < arr[middleIndex])
			rightBound = middleIndex - 1;
		else
			return true;
	}

	return false;
}