/*
5. Total Template
Write a template for a function called total. The function should keep a running
total of values entered by the user, then return the total. The argument sent into the
function should be the number of values the function is to read. Test the template in
a simple driver program that sends values of various types as arguments and displays
the results.
*/

#include <iostream>

using std::cout;
using std::cin;
using std::endl;

template <typename T>
T total(size_t amountOfValues);

int main()
{
	cout << "Type: int. Amount of Values = 3\n";
	int sum1 = total<int>(3);
	cout << "Sum = " << sum1 << endl;

	cout << "Type: double. Amount of Values = 2\n";
	double sum2 = total<double>(2);
	cout << "Sum = " << sum2 << endl;

	return 0;
}

template <typename T>
T total(size_t amountOfValues)
{
	T sum = 0;
	T value;

	do
	{
		cout << "Enter value: ";
		cin >> value;
		sum += value;

	} while (--amountOfValues > 0);

	return sum;
}