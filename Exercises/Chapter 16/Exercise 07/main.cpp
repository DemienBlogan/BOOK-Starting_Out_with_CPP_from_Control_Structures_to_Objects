/*
7. TestScores Class
Write a class named TestScores. The class constructor should accept an array of test
scores as its argument. The class should have a member fnction that returns the average
of the test scores. If any test score in the array is negative of greater that 100, the
class should throw an exception. Demonstrate the class in a program.
*/

#include <iostream>
#include "TestScores.h"

using std::cout;
using std::endl;

int main()
{
	const size_t SIZE = 5;
	double arr1[SIZE] = { 20, 30, -5, 3, 10 };
	double arr2[SIZE] = { 20, 30, 5, 3, 10 };

	try
	{
		TestScores scores1{ arr1, SIZE };
		cout << "Average = " << scores1.GetAverage() << endl;
	}
	catch (const std::exception& exc)
	{
		cout << exc.what() << endl;
	}

	try
	{
		TestScores scores2{ arr2, SIZE };
		cout << "Average = " << scores2.GetAverage() << endl;
	}
	catch (const std::exception& exc)
	{
		cout << exc.what() << endl;
	}
	return 0;
}