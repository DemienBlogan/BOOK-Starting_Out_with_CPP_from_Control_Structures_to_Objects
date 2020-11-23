/*
7. TestScores Class
Design a TestScores class that has member variables to hold three test scores. The
class should have a constructor have, accessor, and mutator functions for the test score fields
and a member function that returns the average of the test scores. Demonstrate the
class by writing a separate program that scores, which are stored in the TestScores
object. Then the program should display the average of the scores, as reported by the
TestScores object.
*/

#include <iostream>

#include "TestScores.h"

using std::cout;
using std::cin;
using std::endl;

int main()
{
	double score1, score2, score3;

	cout << "Enter three scores: ";
	cin >> score1 >> score2 >> score3;

	TestScores scores{ score1, score2, score3 };

	cout << "Average score: " << scores.GetAverage() << endl;

	return 0;
}