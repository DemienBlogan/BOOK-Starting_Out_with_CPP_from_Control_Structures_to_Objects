// This program averages 3 test scores. The braces
// were inadvertently left out of the if statement.
#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	const int HIGH_SCORE = 95;  // A high score is 95 or greater
	int score1, score2, score3; // To hold three test scores
	double average;             // To hold the average score

	// Get the three test scores.
	cout << "Enter 3 test scores and I will average them: ";
	cin >> score1 >> score2 >> score3;

	// Calculate and display the average score.
	average = (score1 + score2 + score3) / 3.0;
	cout << fixed << showpoint << setprecision(1);
	cout << "Your average is " << average << endl;

	// ERROR! THis if statement is missing it's braces!
	if (average > HIGH_SCORE)
		cout << "Congratulation!\n";
		cout << "That's a high score.\n";
		cout << "You deserve a pat on the back!\n";
	return 0;
}