/*
7. Number Analysis Program
Write a program that asks the user for a file name. Assume the file contains a series of
numbers, each written on a separate line. The program should read the contents of the
file into an array then display the following data:

- The lowest number in the array
- The highest number in the array
- The total of the numbers in the array
- The average of the numbers in the array

If you have downloaded this book's source code, you will find a file named numbers.txt
in the Chapter 07 folder. You can use the file to test the program.
*/

#include <iostream>
#include <fstream>

int main()
{
	using namespace std;

	ifstream fin("Numbers.txt");

	if (!fin)
	{
		cout << "File 'Numbers.txt' could not been opened.\n";
		return 0;
	}

	int size = 0;
	int number;
	while (fin >> number)
		size++;

	fin.clear();
	fin.seekg(ios::beg);

	if (size == 0)
	{
		cout << "There is no numbers.\n";
		return 0;
	}

	int* arr = new int[size];
	for (size_t i = 0; i < size; i++)
		fin >> arr[i];

	cout << "All numbers: ";
	for (size_t i = 0; i < size; i++)
		cout << arr[i] << " ";
	cout << endl;

	int max = arr[0], min = arr[0];
	double total = 0;

	for (size_t i = 0; i < size; i++)
	{
		total += arr[i];

		if (max < arr[i])
			max = arr[i];

		if (min > arr[i])
			min = arr[i];
	}
	
	double average = total / size;

	cout << "Max number = " << max << endl;
	cout << "Min number = " << min << endl;
	cout << "Total      = " << total << endl;
	cout << "Average    = " << average << endl;

	delete[] arr;
	arr = nullptr;

	return 0;
}