/*
20. Lottery Statistics
To play the PowerBall lottery, you buy a ticket that has five numbers in the range of
1-69, and a "PowerBall" number in the range of 1-26. (You can pick the numbers
yourself, or you can let the ticket machine randomly pick them for you). Then, on
a specified date, a winning set of numbers are randomly selected by a machine. If
your first five numbers match the first five winning numbers in any order, and your
PowerBall number matches the winning PowerBall number, then you win the jack-pot,
which is a very large amount of money. If your numbers match only some of the winning
numbers, you win a lesser amount, depending on how many of the winning
numbers you have matched.

In the student sample programs for this book, you will find a file named pbnumbers.txt,
containing the winning lottery numbers that were selected between Februare 3, 2010
and May 11, 2016 (the file contains 654 sets of winning numbers).

Each line in the file contains the set of six numbers that were selected on a given date.
The numbers are separated by a space, and the last number in each line is the PowerBall
number for that day. For example, the first line in the file shows the numbers for
February 3, 2010, which are 17, 22, 36, 37, 52, and the PowerBall number 24.

Write one or more programs that work with this file to perform the following:
- Display the 10 most common numbers, ordered by frequency.
- Display the 10 least common numbers, ordred by frequency.
- Display the 10 most overdue numbers (numbers that haven't been drawn in a long
  time), ordered from most overdue to least overdue.
- Display the frequency of each number 1-69, and the frequency of each PowerBall
  number 1-26.
*/

#include <iostream>
#include <string>

#include "MainTaskFunctions.h"
#include "ExtraTaskFunctions.h"

using namespace std;

int main()
{
	// --- Main task ---
	cout << "--- Main Task --- \n\n";

	SetRandom();

	string fileName = "pbnumbers.txt";
	ifstream file;
	OpenFile(file, fileName);

	vector<array<int, 5>> allWinCombinations;
	vector<int> allPowerBallWinNumbers;
	ReadFromFile(file, allWinCombinations, allPowerBallWinNumbers);

	file.close();

	array<int, 5> userTicket;
	SetTicket(userTicket);

	int userPowerBallNumber;
	SetPowerBallNumber(userPowerBallNumber);

	size_t win5NumbersIndex = SelectWin5NumbersIndex(allWinCombinations.size());
	size_t winPowerBallIndex = SelectWinPowerBallIndex(allPowerBallWinNumbers.size());

	const array<int, 5>& winCombination = allWinCombinations[win5NumbersIndex];
	int winPowerBall = allPowerBallWinNumbers[winPowerBallIndex];

	ShowUserCombination(userTicket, userPowerBallNumber);
	ShowWinCombination(winCombination, winPowerBall);

	int sameNumbers = CountSameNumbers(winCombination, userTicket, winPowerBall, userPowerBallNumber);

	ShowResult(sameNumbers);

	system("pause");
	system("cls");

	// --- Extra task ---
	cout << "--- Extra Task --- \n\n";

	vector<int> numbers = ConvertToVectorNumbers(allWinCombinations, allPowerBallWinNumbers);

	Display10MostCommonNumbers(numbers);

	system("pause");
	system("cls");

	Display10LeastCommonNumbers(numbers);

	system("pause");
	system("cls");

	Display10MostOverdueNumbers(numbers);

	system("pause");
	system("cls");

	DisplayNumbersFrequency(allWinCombinations, allPowerBallWinNumbers);

	system("pause");
	system("cls");

	return 0;
}