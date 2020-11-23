/*
3. QuickSort Template
Create a template version of the QuickSort algorithm that will work with any data
type. Demonstrate the template with a driver function.
*/

#include <iostream>

template <typename T>
void QuickSort(T arr[], int first, int last)
{
	T middle = arr[(first + last) / 2];
	int i = first;
	int j = last;

	do
	{
		while (arr[i] < middle)
			i++;
		while (arr[j] > middle)
			j--;

		if (i <= j)
		{
			std::swap(arr[i], arr[j]);
			i++;
			j--;
		}

	} while (i <= j);

	if (i < last)
		QuickSort(arr, i, last);
	if (j > first)
		QuickSort(arr, first, j);
}

int main()
{
	const size_t SIZE = 5;
	int arr[SIZE] = { 10, 1, 9, 2, 8 };

	for (size_t i = 0; i < SIZE; i++)
		std::cout << arr[i] << " ";
	std::cout << std::endl;

	QuickSort(arr, 0, SIZE - 1);

	for (size_t i = 0; i < SIZE; i++)
		std::cout << arr[i] << " ";
	std::cout << std::endl;

	return 0;
}