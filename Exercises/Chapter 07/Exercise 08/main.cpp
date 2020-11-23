/*
8. Lo Shu Magic Square
The Lo Shu Magic Square is a grid with 3 rows and 3 columns shown in Figure 7-19.
The Lo Shu Magic Square has the following properties:

- The grid contains the numbers 1 through 9 exactly.
- The sum of each row, each column, and each diagonal all add up to the same number.
  This is shown in Figure 7-20.

In a program, you can simulate a magic square using a two-dimensional array. Write a
function that accepts a two-dimensional array as an argument, and determines whether
the array is a Lo Shu Magic Square. Test the function in a program.
*/

#include <iostream>

void Initialize(int square[][3], int rows);
void Show(const int square[][3], int rows);
bool IsLoShuSquare(int square[][3], int rows);

int main()
{
	using namespace std;

	const size_t ROWS = 3, COLS = 3;
	int square[ROWS][COLS];

	Initialize(square, ROWS);
	Show(square, ROWS);

	if (IsLoShuSquare(square, ROWS))
		cout << "It is Lo Shu square.\n";
	else
		cout << "It is not Lo Shu square.\n";

	return 0;
}

void Initialize(int square[][3], int rows)
{
	using namespace std;

	for (size_t i = 0; i < rows; i++)
	{
		for (size_t j = 0; j < 3; j++)
		{
			cout << "Enter square[" << i << "][" << j << "]: ";
			cin >> square[i][j];
		}
	}
}

void Show(const int square[][3], int rows)
{
	using namespace std;

	cout << "Square:\n";
	for (size_t i = 0; i < rows; i++)
	{
		for (size_t j = 0; j < 3; j++)
			cout << square[i][j] << " ";
		cout << endl;
	}
	cout << endl;
}

bool IsLoShuSquare(int square[][3], int rows)
{
	int sum = 0;

	// Horizontal sum:
	for (size_t i = 0; i < rows; i++)
	{
		sum = 0;
		for (size_t j = 0; j < 3; j++)
			sum += square[i][j];

		if (sum != 15)
			return false;
	}

	// Vertical sum:
	for (size_t j = 0; j < 3; j++)
	{
		sum = 0;
		for (size_t i = 0; i < rows; i++)
			sum += square[i][j];

		if (sum != 15)
			return false;
	}

	// Diagonal #1 sum:		
	sum = 0;
	for (size_t i = 0; i < rows; i++)
		for (size_t j = 0; j < 3; j++)
			if (i == j)
				sum += square[i][j];

	if (sum != 15)
		return false;

	// Diagonal #1 sum:
	sum = 0;
	for (size_t i = 0; i < rows; i++)
		for (size_t j = 0; j < 3; j++)
			if (i + j == rows - 1)
				sum += square[i][j];

	if (sum != 15)
		return false;

	return true;
}