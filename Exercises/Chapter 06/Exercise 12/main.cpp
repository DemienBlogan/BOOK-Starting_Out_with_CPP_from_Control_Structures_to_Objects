/*
12. Star Search
A particular talent competition has five judges, each of whom awards a score between
0 and 10 to each performer. Fractional scores, such as 8.3, are allowed. A performer's
final score is determined by dropping the highest and lowest score received, then averaging
the three remaining scores. Write a program that uses this method to calculate a
contestant's score. It should include the following functions:

- void getJudgeData() should ask the user for a judge's score, store it in a reference
  parameter variable, and validate it. This function should be called by main once for
  each of the five judges.
- void calcScore() should calculate and display the average of the three scores that
  remain after dropping the highest and lowest scores the performer received. This
  function should be called just once by main and should be passed the five scores.

The last tow functions, described below, should be called by calcScore, which uses
the returned information to determine which of the scores to drop.
- int findLowest() should find and return the lowest of the five scores passed to it.
- int findHighest() should find and return the highest of the five scores passed to it.

Input Validation: Do not accept judge scores lower than 0 or higher than 10.
*/

#include <iostream>

void getJudgeData(double& score);
void calcScore(double score1, double score2, double score3, double score4, double score5);
double findLowest(double score1, double score2, double score3, double score4, double score5);
double findHighest(double score1, double score2, double score3, double score4, double score5);

int main()
{
	using namespace std;

	double score1, score2, score3, score4, score5;

	cout << "Enter the score of first judge: ";
	getJudgeData(score1);
	cout << "Enter the score of second judge: ";
	getJudgeData(score2);
	cout << "Enter the score of third judge: ";
	getJudgeData(score3);
	cout << "Enter the score of fourth judge: ";
	getJudgeData(score4);
	cout << "Enter the score of fifth judge: ";
	getJudgeData(score5);

	calcScore(score1, score2, score3, score4, score5);

	return 0;
}

void getJudgeData(double& score)
{
	using namespace std;

	do
	{
		cin >> score;

		if (score < 0 || score > 10)
			cout << "Incorrect score. Enter the score between 0 and 10.\n";
		
	} while (score < 0 || score > 10);
}

void calcScore(double score1, double score2, double score3, double score4, double score5)
{
	using namespace std;

	double lowestScore = findLowest(score1, score2, score3, score4, score5);
	double highestScore = findHighest(score1, score2, score3, score4, score5);

	double sum = 0.0;

	if (score1 != lowestScore && score1 != highestScore)
		sum += score1;
	if (score2 != lowestScore && score2 != highestScore)
		sum += score2;
	if (score3 != lowestScore && score3 != highestScore)
		sum += score3;
	if (score4 != lowestScore && score4 != highestScore)
		sum += score4;
	if (score5 != lowestScore && score5 != highestScore)
		sum += score5;

	double average = sum / 3;

	cout << "Average score = " << average << endl;
}

double findLowest(double score1, double score2, double score3, double score4, double score5)
{
	double lowestScore = score1 < score2 ? score1 : score2;
	lowestScore = lowestScore < score3 ? lowestScore : score3;
	lowestScore = lowestScore < score4 ? lowestScore : score4;
	lowestScore = lowestScore < score5 ? lowestScore : score5;

	return lowestScore;
}

double findHighest(double score1, double score2, double score3, double score4, double score5)
{
	double highestScore = score1 > score2 ? score1 : score2;
	highestScore = highestScore > score3 ? highestScore : score3;
	highestScore = highestScore > score4 ? highestScore : score4;
	highestScore = highestScore > score5 ? highestScore : score5;

	return highestScore;
}