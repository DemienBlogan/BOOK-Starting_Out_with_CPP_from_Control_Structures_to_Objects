/*
21. 2D Array Operations
Write a program that creates a two-dimensional array initialized with test data. Use
any data type you wish. The program should have the following functions:

- getTotal - This function should accept a two-dimensional array as its argument
  and return the total of all the values in the array.
- getAverage - This function should accept a two-dimensional array as its argument
  and return the average of all the values in the array.
- getRowTotal - This function should accept a two-dimensional array as its first
  argument and an integer as its second argument. The second argument should be
  the subscript of a row in the array. The function should return the total of the values
  in the specified row.
- getColumnTotal - This function should accept a two-dimensional array as its first
  argument and an integer as its second argument. The second argument should be the
  subscript of a column in the array. The function should return the total of the values
  in the specified column.
- getHighestInRow - This function should accept a two-dimensional array as its first
  argument and an integer as its second argument. The second argument should be the 
  subscript of a row in the array. The function should return the highest value in the
  specified row of the array.
- getLowestInRow - This function should accept a two-dimensional array as its first
  argument and an integer as its second argument. The second argument should be
  the subscript of a row in the array. The function should return the lowest value in
  the specified row of the array.

Demonstrate each of the functions in this program.
*/

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int** Create2DArray(size_t rows, size_t cols);
void Initialize(int** arr, size_t rows, size_t cols);
void Show(const int* const* arr, size_t rows, size_t cols);
void Delete(const int* const* arr, size_t rows);

int getTotal(const int* const* arr, size_t rows, size_t cols);
double getAverage(const int* const* arr, size_t rows, size_t cols);
int getRowTotal(const int* const* arr, size_t rows, size_t cols, int rowIndex);
int getColumnTotal(const int* const* arr, size_t rows, size_t cols, int colIndex);
int getHighestInRow(const int* const* arr, size_t rows, size_t cols, int rowIndex);
int getLowestInRow(const int* const* arr, size_t rows, size_t cols, int rowIndex);

int main()
{
	srand(static_cast<unsigned>(time(nullptr)));

	int rows = 5, cols = 5;
	int** arr = Create2DArray(rows, cols);

	Initialize(arr, rows, cols);
	Show(arr, rows, cols);

	int sum = getTotal(arr, rows, cols);
	double average = getAverage(arr, rows, cols);
	int row2Sum = getRowTotal(arr, rows, cols, 2);
	int column3Sum = getColumnTotal(arr, rows, cols, 3);
	int row4Max = getHighestInRow(arr, rows, cols, 4);
	int row1Min = getLowestInRow(arr, rows, cols, 1);

	cout << "Sum = " << sum << endl;
	cout << "Average = " << average << endl;
	cout << "Row #2 Sum = " << row2Sum << endl;
	cout << "Column #3 Sum = " << column3Sum << endl;
	cout << "Row #4 Max = " << row4Max << endl;
	cout << "Row #1 Min = " << row1Min << endl;

	Delete(arr, rows);

	return 0;
}

int** Create2DArray(size_t rows, size_t cols)
{
	if (rows == 0 || cols == 0)
		return nullptr;

	int** arr;

	arr = new int* [rows];
	for (size_t i = 0; i < rows; i++)
		arr[i] = new int[cols];

	return arr;
}

void Initialize(int** arr, size_t rows, size_t cols)
{
	if (arr == nullptr)
		return;

	for (size_t i = 0; i < rows; i++)
		for (size_t j = 0; j < cols; j++)
			arr[i][j] = rand() % 100;
}

void Show(const int* const* arr, size_t rows, size_t cols)
{
	if (arr == nullptr)
		return;

	for (size_t i = 0; i < rows; i++)
	{
		for (size_t j = 0; j < cols; j++)
			cout << arr[i][j] << "\t";
		cout << endl;
	}
}

void Delete(const int* const* arr, size_t rows)
{
	if (arr == nullptr)
		return;

	for (size_t i = 0; i < rows; i++)
		delete[] arr[i];
	delete[] arr;
}

int getTotal(const int* const* arr, size_t rows, size_t cols)
{
	if (arr == nullptr)
		return 0;

	int sum = 0;

	for (size_t i = 0; i < rows; i++)
		for (size_t j = 0; j < cols; j++)
			sum += arr[i][j];

	return sum;
}

double getAverage(const int* const* arr, size_t rows, size_t cols)
{
	if (arr == nullptr || rows == 0 || cols == 0)
		return 0;

	double sum = getTotal(arr, rows, cols);
	double average = sum / (rows * cols);

	return average;
}

int getRowTotal(const int* const* arr, size_t rows, size_t cols, int rowIndex)
{
	if (arr == nullptr || rowIndex < 0 || rowIndex >= rows)
		return 0;

	int sum = 0;

	for (size_t i = 0; i < cols; i++)
		sum += arr[rowIndex][i];

	return sum;
}

int getColumnTotal(const int* const* arr, size_t rows, size_t cols, int colIndex)
{
	if (arr == nullptr || colIndex < 0 || colIndex >= rows)
		return 0;

	int sum = 0;

	for (size_t i = 0; i < rows; i++)
		sum += arr[i][colIndex];

	return sum;
}

int getHighestInRow(const int* const* arr, size_t rows, size_t cols, int rowIndex)
{
	if (arr == nullptr || rowIndex < 0 || rowIndex >= rows)
		return -1;

	int max = arr[rowIndex][0];

	for (size_t i = 0; i < cols; i++)
		if (max < arr[rowIndex][i])
			max = arr[rowIndex][i];

	return max;
}

int getLowestInRow(const int* const* arr, size_t rows, size_t cols, int rowIndex)
{
	if (arr == nullptr || rowIndex < 0 || rowIndex >= rows)
		return -1;

	int min = arr[rowIndex][0];

	for (size_t i = 0; i < cols; i++)
		if (min > arr[rowIndex][i])
			min = arr[rowIndex][i];

	return min;
}