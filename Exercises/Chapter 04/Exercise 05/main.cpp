/*
5. Body Mass Index
Write a program that calculates and displays a person's body mass index (BMI). The
BMI is often used to determine whether a person is overweight of underweight for his
or her height. A person's BMI is calculated with the following formula:

BMI = weight * 703 / height ^ 2

where weight is measued in pounds and height is measured in inches. The program should
display a message indicating whether the person has optimal weight, is underweight, or is
overweight. A person's weight is considered to be optimal if his or her BMI is between
18.5 and 25. If the BMI is less than 18.5, the person is considered to be underweight. If
the BMI value is greater than 25, the person is considered to be overweight.
*/

#include <iostream>
#include <cmath>

int main()
{
	using namespace std;

	cout << "Enter your weight (pounds): ";
	double weight;
	cin >> weight;

	cout << "Enter your height (inches): ";
	double height;
	cin >> height;

	double BMI = weight * 703 / pow(height, 2);

	if (BMI < 18.5)
		cout << "You are considered to be unreweight.\n";
	else if (BMI > 25)
		cout << "You are considered to be overweight.\n";
	else
		cout << "Your weight is normal.\n";

	return 0;
}