/*
10. Reverse Array
Write aa function that accepts an int array and the array's size as arguments. The function
should create a copy of the array except that the element values should be reversed
in the copy. The function should return a pointer to the new array. Demonstrate the
function in a complete program.
*/

#include <iostream>

int* CreateIntArray(size_t size);
void FillArray(int* arr, size_t size);
void EnterSize(int& size);
void Delete(const int* arr);
void Show(const int* arr, size_t size);

int* CreateReverseCopy(const int* arr, size_t size);

int main()
{
	int size;
	EnterSize(size);

	int* arr = CreateIntArray(size);
	FillArray(arr, size);

	int* reverseArr = CreateReverseCopy(arr, size);

	Show(arr, size);
	Show(reverseArr, size);

	Delete(arr);
	Delete(reverseArr);

	return 0;
}

int* CreateIntArray(size_t size)
{
	return size != 0 ? new int[size] : nullptr;
}

void FillArray(int* arr, size_t size)
{
	for (size_t i = 0; i < size; i++)
		arr[i] = i;
}

void EnterSize(int& size)
{
	using namespace std;

	do
	{
		cout << "Enter size: ";
		cin >> size;

		if (size <= 0)
			cout << "Incorrect value. Try again.\n";

	} while (size <= 0);
}

void Delete(const int* arr)
{
	delete[] arr;
}

void Show(const int* arr, size_t size)
{
	using namespace std;

	for (size_t i = 0; i < size; i++)
		cout << *(arr + i) << " ";
	cout << endl;
}

int* CreateReverseCopy(const int* arr, size_t size)
{
	int* reverseArr = new int[size];

	for (size_t i = 0; i < size; i++)
		reverseArr[i] = arr[size - i - 1];

	return reverseArr;
}