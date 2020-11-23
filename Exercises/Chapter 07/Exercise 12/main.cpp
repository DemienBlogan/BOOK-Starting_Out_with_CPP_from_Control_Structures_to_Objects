/*
12. Grade Book
A teacher has five students who have taken four tests. The teacher uses the following
grading scale to assign a letter grade to a student, based on the average of his or her
four test scores:
----------------------------------
Test Score            Letter Grade
----------------------------------
90 - 100              A
80 - 89               B
70 - 79               C
60 - 69               D
0  - 59               F
----------------------------------

Write a program that uses an array of string object to hold the five student names,
an array of five characters to hold the five students' letter grades, and five arrays of
four doubles to hold each student's set of test scores.

The program should allow the user to enter each student's name and his or her four
test scores. It should then calculate and display each student's average test score, and a
letter grade based on the average.

Input Validation: Do not accept test scores less than 0 or greater than 100.
*/
#include <iostream>
#include <string>

int main()
{
	using namespace std;

	const size_t STUDENTS_AMOUNT = 5, TESTS_AMOUNT = 4;
	string studentsNames[STUDENTS_AMOUNT];
	char studentsLetterGrages[STUDENTS_AMOUNT];
	int studentsScores[TESTS_AMOUNT];

	double sum, average;

	for (size_t i = 0; i < STUDENTS_AMOUNT; i++)
	{
		cout << "Student #" << i + 1 << ", enter your name: ";
		cin >> studentsNames[i];

		sum = 0;

		for (size_t j = 0; j < TESTS_AMOUNT; j++)
		{
			cout << "Test #" << j + 1 << ", enter the score (0...100): ";
			cin >> studentsScores[j];

			if (studentsScores[j] < 0 || studentsScores[j] > 100)
			{
				cout << "Incorrect value. Try again.\n";
				j--;
				continue;
			}

			sum += studentsScores[j];
		}

		average = sum / TESTS_AMOUNT;

		if (average >= 0 && average <= 59)
			studentsLetterGrages[i] = 'F';
		else if (average >= 60 && average <= 69)
			studentsLetterGrages[i] = 'D';
		else if (average >= 70 && average <= 79)
			studentsLetterGrages[i] = 'C';
		else if (average >= 80 && average <= 89)
			studentsLetterGrages[i] = 'B';
		else
			studentsLetterGrages[i] = 'A';
	}

	for (size_t i = 0; i < STUDENTS_AMOUNT; i++)
		cout << studentsNames[i] << ", your grade " << studentsLetterGrages[i] << endl;

	return 0;
}