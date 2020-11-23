/*
11. Lowest Score Drop
Write a program that calculates the average of a group of test scores, where the lowest
score in the group is dropped. It should use the following functions:

- void getScore() should ask the user for a test score, store it in a reference parameter
  variable, and validate it. This function should be called by main once for each
  of the five scores to be entered.
- void calcAverage() should calculate and display the average of the four highest
  scores. This function should be called just once by main and should be passed the
  five scores.
- int findLowest() should find and return the lowest of the five scores passed to it.
  It should be called by calcAverage, which uses the function to determine which of
  the five scores to drop.

Input Validation: Do not accept test scores lower than 0 or higher than 100.
*/

#include <iostream>

void getScore(int& score);
void calcAverage(int score1, int score2, int score3, int score4, int score5);
int findLowest(int score1, int score2, int score3, int score4, int score5);

int main()
{
	using namespace std;

	int score1, score2, score3, score4, score5;

	cout << "Enter 5 scores: ";
	getScore(score1);
	getScore(score2);
	getScore(score3);
	getScore(score4);
	getScore(score5);

	calcAverage(score1, score2, score3, score4, score5);

	return 0;
}

void getScore(int& score)
{
	using namespace std;

	cin >> score;

	if (score < 0 || score > 100)
	{
		cout << "Incorrect score.\n";
		exit(0);
	}
}

void calcAverage(int score1, int score2, int score3, int score4, int score5)
{
	using namespace std;

	int sum = score1 + score2 + score3 + score4 + score5;
	int lowestScore = findLowest(score1, score2, score3, score4, score5);
	sum -= lowestScore;

	double average = sum / 4.0;

	cout << "Average score = " << average << endl;
}

int findLowest(int score1, int score2, int score3, int score4, int score5)
{
	int lowestScore = score1 < score2 ? score1 : score2;
	lowestScore = lowestScore < score3 ? lowestScore : score3;
	lowestScore = lowestScore < score4 ? lowestScore : score4;
	lowestScore = lowestScore < score5 ? lowestScore : score5;

	return lowestScore;
}
