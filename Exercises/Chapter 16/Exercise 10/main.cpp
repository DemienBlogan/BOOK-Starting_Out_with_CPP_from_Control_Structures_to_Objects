/*
10. SortableVector Class Template
Write a class template named SortableVector. The class should be derived from the
SimpleVector class presented in this chapter. It should have a member function that
sorts the array elements in ascending order. (Use the sorting algorithm of your choice).
Test the template in a driver program.
*/

#include <iostream>
#include "SortableVector.h"

using std::cout;
using std::endl;

int main()
{
	SortableVector<int> vector;

	for (int i = 10; i >= 0; i--)
		vector.push_back(i + 1);

	cout << "Vector before sorting: ";
	for (size_t i = 0; i < vector.GetSize(); i++)
		cout << vector[i] << " ";
	cout << endl;

	vector.Sort();

	cout << "Vector after sorting: ";
	for (size_t i = 0; i < vector.GetSize(); i++)
		cout << vector[i] << " ";
	cout << endl;

	return 0;
}