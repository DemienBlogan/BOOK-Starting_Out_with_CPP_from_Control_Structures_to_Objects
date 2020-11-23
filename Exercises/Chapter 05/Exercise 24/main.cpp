/*
24. Using Files-Numeric Processing
If you have downloaded this book's source from the Computer Science Portal,
you will find a file named Random.txt in the Chapter 05 folder. (The Portal can be 
found at www.pearsonhighered.com/gaddis). This file contains a long list of random
numbers. Copy the file to your system, then write a program that opens the file, reads
all the numbers from the file, and calculates the following:

A) The number of numbers in the file
B) The sum of all the numbers in the file (a running total)
C) The average of all the numbers in the file

The program should display the number of numbers found in the file, the sum of the
numbers, and the average of the numbers.
*/

#include <iostream>
#include <fstream>
#include <iomanip>

int main()
{
	using namespace std;

	ifstream file("Random.txt");

	if (!file)
	{
		cout << "The file 'Random.txt' could not been found.\n";
		return 0;
	}

	int count = 0;
	int sum = 0;
	int number;

	cout << "File numbers:\n";
	while (file >> number)
	{
		cout << number << " ";
		sum += number;
		count++;
	}

	double average = static_cast<double>(sum) / count;

	cout << "\n\n";
	cout << "Sum = " << sum << endl;
	cout << "Average = " << average << endl;
	cout << "Count = " << count << endl;

	file.close();

	return 0;
}