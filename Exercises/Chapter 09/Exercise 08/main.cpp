/*
8. Mode Function
In statistics, the mode of a set of values is the value that occurs most often or with the
greatest frequency. Write a function that accepts as arguments the following:

A) An array of integers
B) An integer that indicates the number of elements in the array

The function should determine the mode of the array. That is, it should determine
which value in the array occurs most often. The mode is the value the function
should return. If the array has no mode (none of the values occur more than once),
the function should return -1. (Assume the array will always contain nonegative
values).

Demonstrate your pointer prowess by using pointer notation instead of array notation
in this function.
*/

#include <iostream>

int Mode(const int* arr, size_t size);

int main()
{
	using namespace std;

	const size_t SIZE = 3;
	int arr[SIZE] = { 1, 2, 3 };

	cout << "Mode = " << Mode(arr, SIZE) << endl;

	return 0;
}

int Mode(const int* arr, size_t size)
{
	int maxAmount = 1;
	int numberAmount;
	int modeValue = -1;

	for (size_t i = 0; i < size; i++)
	{
		numberAmount = 0;
		for (size_t j = 0; j < size; j++)
			if (arr[i] == arr[j])
				numberAmount++;

		if (numberAmount > maxAmount)
		{
			maxAmount = numberAmount;
			modeValue = arr[i];
		}
	}

	return modeValue;
}