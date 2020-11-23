/*
4. Larger than n
In a program, write a function that accepts three arguments: an array, the size of the
array, and a number n. Assume the array contains itegers. The function should display
all of the numbers in the array that are greater than the number n.
*/

#include <iostream>
#include <cstdlib>
#include <ctime>

void Initialize(int arr[], size_t size);
void Show(const int arr[], size_t size);
void ShowAllLarger(const int arr[], size_t size, int number);
int EnterNumber();

int main()
{
	const size_t SIZE = 10;
	int arr[SIZE];

	Initialize(arr, SIZE);
	Show(arr, SIZE);

	int number = EnterNumber();

	ShowAllLarger(arr, SIZE, number);

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
		arr[i] = rand() % 100;
}

void Show(const int arr[], size_t size)
{
	using namespace std;

	if (arr == nullptr)
	{
		cout << "nullptr in function 'Show'\n";
		exit(0);
	}

	cout << "Array: ";
	for (size_t i = 0; i < size; i++)
		cout << arr[i] << " ";
	cout << endl;
}

void ShowAllLarger(const int arr[], size_t size, int number)
{
	using namespace std;

	if (arr == nullptr)
	{
		cout << "nullptr in function 'ShowAllLarger'\n";
		exit(0);
	}

	cout << "Numbers larger than " << number << ": ";
	for (size_t i = 0; i < size; i++)
		if (arr[i] > number)
			cout << arr[i] << " ";
	cout << endl;
}

int EnterNumber()
{
	using namespace std;

	cout << "Enter a number: ";
	int number;
	cin >> number;

	return number;
}