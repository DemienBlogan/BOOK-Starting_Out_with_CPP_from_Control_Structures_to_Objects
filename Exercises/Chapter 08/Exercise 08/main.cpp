/*
8. Search Benchmarks
Write a program that has an array of at least 20 integers. It should call a function that
uses the linear search algorithm to locate one of the values. The function should keep
a count of the numbe rof comparisons it makes until it finds the value. The program
then should call a function that uses the binary search algorithm to locate the same
value. It should also keep count of the number of comparisons it makes. Display these 
values on the screen.
*/

#include <iostream>
#include <ctime>
#include <cstdlib>

void Initialize(int arr[], size_t size);
void Show(const int arr[], size_t size);
void SelectionSort(int arr[], size_t size);
bool BinarySearch(const int arr[], size_t size, int key);
bool LinearSearch(const int arr[], size_t size, int key);

int main()
{
	using namespace std;

	srand(static_cast<unsigned>(time(nullptr)));

	const size_t SIZE = 20;
	int arr[SIZE];

	Initialize(arr, SIZE);
	SelectionSort(arr, SIZE);
	Show(arr, SIZE);

	LinearSearch(arr, SIZE, rand() % 100);
	BinarySearch(arr, SIZE, rand() % 100);

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
	for (size_t i = 0; i < size - 1; i++)
		for (size_t j = i + 1; j < size; j++)
			if (arr[i] > arr[j])
				std::swap(arr[i], arr[j]);
}

bool BinarySearch(const int arr[], size_t size, int key)
{
	using namespace std;

	int leftBound = 0, rightBound = size - 1;
	int middleIndex;

	int comparisons = 0;

	while (leftBound <= rightBound)
	{
		middleIndex = (leftBound + rightBound) / 2;

		comparisons++;
		if (key > arr[middleIndex])
			leftBound = middleIndex + 1;
		else if (key < arr[middleIndex])
			rightBound = middleIndex - 1;
		else
		{
			cout << "Binary comparisons = " << comparisons << endl;
			return true;
		}
	}

	cout << "Binary comparisons = " << comparisons << endl;
	return false;
}

bool LinearSearch(const int arr[], size_t size, int key)
{
	using namespace std;

	int comparisons = 0;

	for (size_t i = 0; i < size; i++)
	{
		comparisons++;
		if (arr[i] == key)
		{
			cout << "Linear comparisons = " << comparisons << endl;
			return true;
		}
	}

	cout << "Linear comparisons = " << comparisons << endl;
	return false;
}