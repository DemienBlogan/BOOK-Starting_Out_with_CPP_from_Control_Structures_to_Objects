/*
13. Grade Book Modification
Modify the grade book application in Programming Challenge 12 so it drops each
student's lowest score when determining the test score averages and letter grades.
*/

#include <iostream>
#include <string>

int main()
{
	using namespace std;

	const size_t STUDENTS_AMOUNT = 1, TESTS_AMOUNT = 4;
	string studentsNames[STUDENTS_AMOUNT];
	char studentsLetterGrages[STUDENTS_AMOUNT];
	int studentsScores[TESTS_AMOUNT];

	double sum, average;

	for (size_t i = 0; i < STUDENTS_AMOUNT; i++)
	{
		cout << "Student #" << i + 1 << ", enter your name: ";
		cin >> studentsNames[i];

		// Entering scores
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
		}

		// Finding minimum score
		int minScore = studentsScores[0];
		for (size_t j = 1; j < TESTS_AMOUNT; j++)
			if (minScore > studentsScores[j])
				minScore = studentsScores[j];

		// Calculating sum
		sum = 0;
		for (size_t j = 1; j < TESTS_AMOUNT; j++)
			if (studentsScores[j] != minScore)
				sum += minScore;

		// Calculating average
		average = sum / TESTS_AMOUNT - 1;

		// Determining grade letter
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