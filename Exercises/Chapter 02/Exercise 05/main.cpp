/*
5. Average of Values
To see the average of a series of values, you add the values up then divide the sum by
the number of values. Write a program that stores the following values in five different
variables: 28, 32, 37, 24, and 33. The program should first calculate the sum of
these five variables and store the result in a separate variable named sum. Then, the
program should divide the sum variable by 5 to get tbe average. Display the average
on the screen.
*/

#include <iostream>

int main()
{
	using namespace std;

	double num1 = 28, num2 = 32, num3 = 37, num4 = 24, num5 = 33;
	double sum = num1 + num2 + num3 + num4 + num5;
	double average = sum / 5;

	cout << "Number #1 = " << num1 << endl;
	cout << "Number #2 = " << num2 << endl;
	cout << "Number #3 = " << num3 << endl;
	cout << "Number #4 = " << num4 << endl;
	cout << "Number #5 = " << num5 << endl;

	cout << "Sum = " << sum << endl;
	cout << "Average = " << average << endl;

	return 0;
}