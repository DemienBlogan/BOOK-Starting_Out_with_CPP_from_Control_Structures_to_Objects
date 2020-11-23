/*
6. String Selection Sort
Modify the selectionSort function presented in this chapter so it sorts an array
of strings instead of an array of ints. The the function with a driver program. Use
Program 8-8 as a skeleton to complete.
*/

#include <iostream>
#include <string>

using namespace std;

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

	cout << "--- BEFORE sorting: ---\n";
	for (size_t i = 0; i < NUM_NAMES; i++)
		cout << names[i] << endl;

	for (size_t i = 0; i < NUM_NAMES - 1; i++)
		for (size_t j = i + 1; j < NUM_NAMES; j++)
			if (names[i] > names[j])
				std::swap(names[i], names[j]);

	cout << "--- AFTER sorting: ---\n";
	for (size_t i = 0; i < NUM_NAMES; i++)
		cout << names[i] << endl;

	return 0;
}