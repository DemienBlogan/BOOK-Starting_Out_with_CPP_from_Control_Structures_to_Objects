/*
2. Rainfall Statistics
Write a program that lets the user enter the total rainfall for each of 12 months into an
array of doubles. The program should calculate and display the total rainfall for the
year, the average monthly rainfall, and the months with the highest and lowest amounts.

Input Validation: Do not accept negative numbers for monthly rainfall figures.
*/

#include <iostream>

void Initialize(double arr[], size_t size);
void Show(const double arr[], size_t size);
int Min(const double arr[], size_t size);
int Max(const double arr[], size_t size);
double Sum(const double arr[], size_t size);
double Average(const double arr[], size_t size);

int main()
{
	const size_t MONTHS = 12;
	double rainfalls[MONTHS];

	using namespace std;

	cout << "Initializing...\n";
	Initialize(rainfalls, MONTHS);

	cout << "\nArray elements:\n";
	Show(rainfalls, MONTHS);

	int minMonth = Min(rainfalls, MONTHS);
	int maxMonth = Max(rainfalls, MONTHS);

	cout << endl;
	cout << "Month with min rainfall = " << minMonth + 1 << endl;
	cout << "Month with max rainfall = " << maxMonth + 1 << endl;

	double sum = Sum(rainfalls, MONTHS);
	double average = Average(rainfalls, MONTHS);

	cout << endl;
	cout << "Sum rainfall = " << sum << endl;
	cout << "Average rainfall = " << average << endl;

	return 0;
}

void Initialize(double arr[], size_t size)
{
	using namespace std;

	if (arr == nullptr)
	{
		cout << "nullptr in function 'Initialize'\n";
		exit(0);
	}

	for (size_t i = 0; i < size; i++)
	{
		cout << "Enter rainfall for " << i + 1 << " month: ";
		cin >> arr[i];

		if (arr[i] < 0)
		{
			cout << "Incorrect value. Try again.\n";
			i--;
		}
	}
}
void Show(const double arr[], size_t size)
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

int Min(const double arr[], size_t size)
{
	using namespace std;

	if (arr == nullptr)
	{
		cout << "nullptr in function 'Min'\n";
		exit(0);
	}

	double min = arr[0];
	int minIndex = 0;

	for (size_t i = 1; i < size; i++)
	{
		if (min > arr[i])
		{
			min = arr[i];
			minIndex = i;
		}
	}

	return min;
}

int Max(const double arr[], size_t size)
{
	using namespace std;

	if (arr == nullptr)
	{
		cout << "nullptr in function 'Max'\n";
		exit(0);
	}

	double max = arr[0];
	int maxIndex = 0;

	for (size_t i = 1; i < size; i++)
	{
		if (max < arr[i])
		{
			max = arr[i];
			maxIndex = i;
		}
	}

	return max;
}

double Sum(const double arr[], size_t size)
{
	using namespace std;

	if (arr == nullptr)
	{
		cout << "nullptr in function 'Sum'\n";
		exit(0);
	}

	double sum = 0.0;

	for (size_t i = 0; i < size; i++)
		sum += arr[i];

	return sum;
}

double Average(const double arr[], size_t size)
{
	using namespace std;

	if (arr == nullptr)
	{
		cout << "nullptr in function 'Average'\n";
		exit(0);
	}

	if (size <= 0)
	{
		cout << "Incorrect size in function 'Average'\n";
		exit(0);
	}

	double sum = Sum(arr, size);
	double average = sum / size;
	return average;
}