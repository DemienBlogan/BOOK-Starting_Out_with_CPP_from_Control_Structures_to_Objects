/*
4. Charge Account Validation Modification
Modify the program you wrote for Problem 1 (Charge Account Validation) so it performs
a binary search to locate valid account numbers. Use the selection sort algorithm
to sort the array before the binary search is performed.
*/

#include <iostream>

void SelectionSort(int arr[], size_t size);
bool BinarySearch(const int arr[], size_t size, int key);

int main()
{
	using namespace std;

	const size_t SIZE = 18;
	int validNumbers[SIZE] =
	{
		5658845, 4520125, 7895122, 8777541, 8451277, 1302850,
		8080152, 4562555, 5552012, 5050552, 7825877, 1250255,
		1005231, 6545231, 3852085, 7576651, 7881200, 4581002
	};

	SelectionSort(validNumbers, SIZE);

	cout << "Enter a charge account number: ";
	int userNumber;
	cin >> userNumber;

	if (BinarySearch(validNumbers, SIZE, userNumber))
		cout << "Your number is valid.\n";
	else
		cout << "Your number is not valid.\n";

	return 0;
}

void SelectionSort(int arr[], size_t size)
{
	for (size_t i = 0; i < size - 1; i++)
		for (size_t j = i + 1; j < size; j++)
			if (arr[i] > arr[j])
				std::swap(arr[i], arr[j]);
}

bool BinarySearch(const int arr[], size_t size, int key)
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