/*
10. Write a program that uses two identical arrays of just eight integers. It should display
the contents of the first array, then call a function to sort the array using an ascending
order bubble sort modified to print out the array contents after each pass of the sort.
Next, the program should display the contents of the second array, then call a function
to sort the array using an ascending order selection sort modified to print out the array
contents after each pass of the sort.
*/

#include <iostream>
#include <ctime>
#include <cstdlib>

void Initialize(int arr[], size_t size);
void Show(const int arr[], size_t size);
void SelectionSort(int arr[], size_t size);
void BubbleSort(int arr[], size_t size);

int main()
{
	using namespace std;

	srand(static_cast<unsigned>(time(nullptr)));

	const size_t SIZE = 8;
	int arr1[SIZE], arr2[SIZE];

	Initialize(arr1, SIZE);

	for (size_t i = 0; i < SIZE; i++)
		arr2[i] = arr1[i];

	cout << "----- Selection Sort -----\n";
	SelectionSort(arr1, SIZE);

	cout << "\n----- Bubble Sort -----\n";
	BubbleSort(arr2, SIZE);

	return 0;
}

void Initialize(int arr[], size_t size)
{
	for (size_t i = 0; i < size; i++)
		arr[i] = rand() % 100;
}

void Show(const int arr[], size_t size)
{
	using namespace std;

	for (size_t i = 0; i < size; i++)
		cout << arr[i] << " ";
	cout << endl;
}

void SelectionSort(int arr[], size_t size)
{
	using namespace std;


	for (size_t i = 0; i < size - 1; i++)
	{
		for (size_t j = i + 1; j < size; j++)
		{
			if (arr[i] > arr[j])
			{
				swap(arr[i], arr[j]);
				Show(arr, size);
			}
		}
	}
}

void BubbleSort(int arr[], size_t size)
{
	using namespace std;


	for (int i = 0; i < size - 1; i++)
	{
		for (int j = 0; j < size - i - 1; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				swap(arr[j], arr[j + 1]);
				Show(arr, size);
			}
		}
	}
}