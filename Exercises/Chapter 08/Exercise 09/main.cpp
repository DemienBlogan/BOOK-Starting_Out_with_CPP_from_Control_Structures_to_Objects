/*
9. Sorting Benchmarks
Write a program that uses two identical arrays of at least 20 integers. It should call
a function that uses the bubble sort algorithm to sort one of the arrays in ascending
order. The function should keep a count of the number of exchanges it makes. The
program then should call a function that uses the selection sort algorithm to sort the
other array. It should also keep count of the number of exchanges it makes. Display
these values on the screen.
*/

#include <iostream>
#include <ctime>
#include <cstdlib>

void Initialize(int arr[], size_t size);
void SelectionSort(int arr[], size_t size);
void BubbleSort(int arr[], size_t size);

int main()
{
	using namespace std;

	srand(static_cast<unsigned>(time(nullptr)));

	const size_t SIZE = 20;
	int arr1[SIZE], arr2[SIZE];

	Initialize(arr1, SIZE);
	
	for (size_t i = 0; i < SIZE; i++)
		arr2[i] = arr1[i];

	SelectionSort(arr1, SIZE);
	BubbleSort(arr2, SIZE);

	return 0;
}

void Initialize(int arr[], size_t size)
{
	for (size_t i = 0; i < size; i++)
		arr[i] = rand() % 100;
}

void SelectionSort(int arr[], size_t size)
{
	using namespace std;

	int swaps = 0;

	for (size_t i = 0; i < size - 1; i++)
	{
		for (size_t j = i + 1; j < size; j++)
		{
			if (arr[i] > arr[j])
			{
				swap(arr[i], arr[j]);
				swaps++;
			}
		}
	}

	cout << "Linear Sort, swaps = " << swaps << endl;
}

void BubbleSort(int arr[], size_t size)
{
	using namespace std;

	int swaps = 0;

	for (int i = 0; i < size - 1; i++)
	{
		for (int j = 0; j < size - i - 1; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				swap(arr[j], arr[j + 1]);
				swaps++;
			}
		}
	}

	cout << "Bubble Sort, swaps = " << swaps << endl;
}