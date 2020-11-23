/*
3. Lottery Winners Modification
Modify the program you wrote for Programming Challenge 2 (Lottery Winners) so it
performs a binary search insted of a linear search.
*/

#include <iostream>

bool BinarySearch(const int arr[], size_t size, int key);

int main()
{
	using namespace std;

	const size_t SIZE = 10;
	int luckyNumbers[SIZE] =
	{
		13579, 26791, 26792, 33445, 55555,
		62483, 77777, 79422, 85647, 93121
	};

	cout << "Enter your 5-digit number: ";
	int userNumber;
	cin >> userNumber;

	if (BinarySearch(luckyNumbers, SIZE, userNumber))
		cout << "You win the lottery!\n";
	else
		cout << "You lose :(\n";

	return 0;
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