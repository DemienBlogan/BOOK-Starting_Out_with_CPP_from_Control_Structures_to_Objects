/*
1. Minimum/Maximum
Write a program that asks the user to enter two numbers. THe prgoram should use the
conditional operator to determine which number is the smaller and which is the larger.
*/

#include <iostream>

int main()
{
	using namespace std;

	cout << "Enter two numbers: ";
	int number1, number2;
	cin >> number1 >> number2;

	int min = number1 < number2 ? number1 : number2;
	int max = number1 > number2 ? number1 : number2;

	cout << "Minimum number = " << min << endl;
	cout << "Maximum number = " << max << endl;

	return 0;
}