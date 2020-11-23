/*
13. Movie Statistics
Write a program that can be used to gather statistical data about the number of movies
college students see in a month. The program should perform the following steps:

A) Ask the user how many students were surveyed. An array of integers with his many
   elements should then be dynamically allocated.
B) Allow the user to enter the number of movies each student saw into the array.
C) Calculate and display the average, median, and mode of the values entered. (Use the
   functions you wrote in Programming Challenges 8 and 9 to calculate the median and
   mode).

Input Validation: Do not accept negative numbers for input.
*/

#include <iostream>

double FindAverage(const int arr[], size_t size);
double FindMedian(const int arr[], size_t size);
int FindMode(const int* arr, size_t size);
void Sort(int* arr, size_t size);

int main()
{
	using namespace std;

	cout << "How many student were surveyed?: ";
	int students;
	cin >> students;

	int* movieStatistics = new int[students];

	for (size_t i = 0; i < students; i++)
	{
		cout << "Enter the number of movies for student #" << i + 1 << ": ";
		cin >> movieStatistics[i];
	}

	Sort(movieStatistics, students);

	double average = FindAverage(movieStatistics, students);
	double median = FindMedian(movieStatistics, students);
	int mode = FindMode(movieStatistics, students);

	cout << "Average = " << average << endl;
	cout << "Median = " << median << endl;
	cout << "Mode = " << mode << endl;

	delete[] movieStatistics;

	return 0;
}

double FindAverage(const int arr[], size_t size)
{
	double sum = 0;
	for (size_t i = 0; i < size; i++)
		sum += arr[i];

	double average = sum / size;
	return average;
}

double FindMedian(const int arr[], size_t size)
{
	if (size % 2 != 0)
		return arr[size / 2];

	double middle1 = arr[size / 2 - 1], middle2 = arr[size / 2];
	double median = (middle1 + middle2) / 2.0;
	return median;
}

int FindMode(const int* arr, size_t size)
{
	int maxAmount = 1;
	int numberAmount;
	int modeValue = -1;

	for (size_t i = 0; i < size; i++)
	{
		numberAmount = 0;
		for (size_t j = 0; j < size; j++)
			if (arr[i] == arr[j])
				numberAmount++;

		if (numberAmount > maxAmount)
		{
			maxAmount = numberAmount;
			modeValue = arr[i];
		}
	}

	return modeValue;
}

void Sort(int* arr, size_t size)
{
	for (size_t i = 0; i < size - 1; i++)
		for (size_t j = i + 1; j < size; j++)
			if (*(arr + i) > * (arr + j))
				std::swap(*(arr + i), *(arr + j));
}