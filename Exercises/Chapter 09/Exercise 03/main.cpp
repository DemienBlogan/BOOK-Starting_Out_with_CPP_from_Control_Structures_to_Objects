/*
3. Drop Lowest Score
Modify Problem 2 above so the lowest test score is dropped. This score should not be
included in the calculation of the average.
*/

#include <iostream>

int* CreateIntArray(size_t size);
void FillArray(int* arr, size_t size);
void EnterSize(int& size);
void Sort(int* arr, size_t size);
void Delete(const int* arr);
void Show(const int* arr, size_t size);
double Average(const int* arr, size_t size);
double Min(const int* arr, size_t size);

int main()
{
	using namespace std;

	int* arr;
	int size;

	EnterSize(size);
	arr = CreateIntArray(size);
	FillArray(arr, size);
	Sort(arr, size);
	Show(arr, size);
	double average = Average(arr, size);
	cout << "Average = " << average << endl;
	Delete(arr);

	return 0;
}

int* CreateIntArray(size_t size)
{
	return size != 0 ? new int[size] : nullptr;
}

void FillArray(int* arr, size_t size)
{
	using namespace std;

	for (size_t i = 0; i < size; i++)
	{
		cout << "Enter arr[" << i << "]: ";
		cin >> *(arr + i);

		if (*(arr + i) < 0)
		{
			cout << "Incorrect value. Try again.\n";
			i--;
		}
	}
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

void Sort(int* arr, size_t size)
{
	for (size_t i = 0; i < size - 1; i++)
		for (size_t j = i + 1; j < size; j++)
			if (*(arr + i) > * (arr + j))
				std::swap(*(arr + i), *(arr + j));
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

double Average(const int* arr, size_t size)
{
	double sum = 0;
	int min = Min(arr, size);

	for (size_t i = 0; i < size; i++)
		if (*(arr + i) != min)
			sum += *(arr + i);

	double average = sum / (size - 1);

	return average;
}

double Min(const int* arr, size_t size)
{
	int min = arr[0];

	for (size_t i = 0; i < size; i++)
		if (min > * (arr + i))
			min = *(arr + i);

	return min;
}