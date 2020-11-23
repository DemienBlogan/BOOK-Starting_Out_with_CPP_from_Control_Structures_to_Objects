/*
8. isMember Function
Write a recursive Boolean function named isMember. The function should accept two
arguments: an array and a value. The function should return true if the value is found
in the array, or false if the value is not found in the array. Demonstrate the function
in a driver program.
*/

#include <iostream>

bool IsMember(const int arr[], size_t size, int number)
{
	if (size == 0)
		return false;

	return arr[size - 1] == number ? true : IsMember(arr, size - 1, number);
}

int main()
{
	const size_t SIZE = 5;
	int arr[SIZE] = { 1, 3, 5, 7, 9 };

	int value1 = 3, value2 = 10;

	if (IsMember(arr, SIZE, value1))
		std::cout << "Array contains value 3.\n";

	if (IsMember(arr, SIZE, value2))
		std::cout << "Array contains value 10.\n";

	return 0;
}