/*
3. Test Average
Write a program that asks for five test scores. The program should calculate the average
test score and display it. The number displayed should be formaned in fixed-point
notation, with one decimal point of precision.
*/

#include <iostream>
#include <iomanip>

int main()
{
	using namespace std;

	const int AMOUNT_OF_NUMBERS = 5;
	double num1, num2, num3, num4, num5;

	cout << "Enter 5 numbers: ";
	cin >> num1 >> num2 >> num3 >> num4 >> num5;

	double sum = num1 + num2 + num3 + num4 + num5;
	double average = sum / AMOUNT_OF_NUMBERS;

	cout << fixed << setprecision(1);
	cout << "Average = " << average << endl;

	return 0;
}