/*
1. Largest/Smallest Array Values
Write a program that lets the user enter ten values into an array. The program should
than display the largest and smallest values stored in the array.
*/

#include <iostream>

void Initialize(int arr[], size_t size);
void Show(const int arr[], size_t size);
int Min(const int arr[], size_t size);
int Max(const int arr[], size_t size);

int main()
{
	const size_t SIZE = 10;
	int arr[SIZE];

	using namespace std;

	cout << "Initializing...\n";
	Initialize(arr, SIZE);

	cout << "\nArray elements:\n";
	Show(arr, SIZE);

	int min = Min(arr, SIZE);
	int max = Max(arr, SIZE);

	cout << endl;
	cout << "Min value = " << min << endl;
	cout << "Max value = " << max << endl;

	return 0;
}

void Initialize(int arr[], size_t size)
{
	using namespace std;

	if (arr == nullptr)
	{
		cout << "nullptr in function 'Initialize'\n";
		exit(0);
	}

	for (size_t i = 0; i < size; i++)
	{
		cout << "Enter arr[" << i << "]: ";
		cin >> arr[i];
	}
}
void Show(const int arr[], size_t size)
{
	using namespace std;

	if (arr == nullptr)
	{
		cout << "nullptr in function 'Show'\n";
		exit(0);
	}

	for (size_t i = 0; i < size; i++)
		cout << arr[i] << " ";
	cout << endl;
}

int Min(const int arr[], size_t size)
{
	using namespace std;

	if (arr == nullptr)
	{
		cout << "nullptr in function 'Min'\n";
		exit(0);
	}

	int min = arr[0];

	for (size_t i = 1; i < size; i++)
		if (min > arr[i])
			min = arr[i];

	return min;
}

int Max(const int arr[], size_t size)
{
	using namespace std;

	if (arr == nullptr)
	{
		cout << "nullptr in function 'Max'\n";
		exit(0);
	}

	int max = arr[0];

	for (size_t i = 1; i < size; i++)
		if (max < arr[i])
			max = arr[i];

	return max;
}