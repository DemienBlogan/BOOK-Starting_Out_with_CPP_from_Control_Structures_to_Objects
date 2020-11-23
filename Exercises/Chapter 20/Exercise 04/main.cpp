/*
4. Recursive Array Sum
Write a function that accepts an array of integers and a number indicating the number
of elements as arguments. The function should recursively calculate the sum of all the
numbers in the array. Demonstrate the function in a driver program.
*/

#include <iostream>

int Sum(const int arr[], size_t size)
{
	return size == 1 ? arr[size - 1] : arr[size - 1] + Sum(arr, size - 1);
}

int main()
{
	const size_t SIZE = 5;
	int arr[SIZE] = { 10, 1, 9, 2, 8 };

	for (size_t i = 0; i < SIZE; i++)
		std::cout << arr[i] << " ";
	std::cout << std::endl;

	int sum = Sum(arr, SIZE);

	std::cout << "Sum = " << sum << std::endl;

	return 0;
}