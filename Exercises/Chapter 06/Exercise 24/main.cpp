/*
24. Rock, Paper, Scissors Game
Write a program that lets the user play the game of Rock, Paper, Scissors against the
computer. The program should work as follows:

1. When the program begins, a random number in the range of 1 through 3 is generated.
   If the number is 1, then the computer has chosen rock. If the number is 2, then
   the computer has chosen paper. If the number is 3, then the computer has chosen
   scissors. (Don't display the computer's choice yet).
2. The user enters his or her choice of "rock", "paper", or "scissors" at the keyboard.
   (You can use a menu if you prefer).
3. The computer's choice is displayed.
4. A winner is selected according to the following rules:
   - If one player chooses rock and the other player chooses scissors, then rock wins.
     (The rock smashes the scissors).
   - If one player chooses scissors and the other player chooses paper, then rock scissors.
     (scissors cuts paper).
   - If one player chooses paper and the other player chooses rock, then paper wins.
     (Paper wraps rock).
   - If both players make the same choice, the game must be played again to determine
     the winner.

Be sure to divide the program into functions that perform each major task.
*/

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>

enum class Winner
{
	USER,
	COMPUTER,
	DRAW
};

enum class Figure
{
	ROCK,
	PAPER,
	SCISSORS
};

Figure ConvertNumberToFigure(int number);
Figure ComputerChoose();
Figure UserChoose();
void ShowFigures(const Figure& userChoice, const Figure& computerChoice);
Winner GetWinner(const Figure& userChoice, const Figure& computerChoice);
void ShowWinner(const Winner& winner);
void ShowFigure(const Figure& figure);

int main()
{
	using namespace std;

	srand(static_cast<unsigned>(time(nullptr)));

	Figure computerChoice, userChoice;
	Winner status;

	do
	{
		computerChoice = ComputerChoose();
		userChoice = UserChoose();
		ShowFigures(userChoice, computerChoice);
		status = GetWinner(userChoice, computerChoice);
		ShowWinner(status);

	} while (status == Winner::DRAW);

	return 0;
}

Figure ConvertNumberToFigure(int number)
{
	using namespace std;

	switch (number)
	{
	case 1:
		return Figure::ROCK;
	case 2:
		return Figure::PAPER;
	case 3:
		return  Figure::SCISSORS;
	default:
		cout << "Error in 'ConvertNumberToString'.\n";
		exit(0);
	}
}

Figure ComputerChoose()
{
	int choiceNumber = rand() % 3 + 1;

	return ConvertNumberToFigure(choiceNumber);
}

Figure UserChoose()
{
	using namespace std;

	int choiceNumber;

	do
	{
		cout << "1 - Rock      \n";
		cout << "2 - Paper     \n";
		cout << "3 - Scissors  \n";
		cout << "Make a choice:\n";
		cin >> choiceNumber;

		if (choiceNumber < 1 || choiceNumber > 3)
			cout << "Incorrect choice. Try again.\n";

	} while (choiceNumber < 1 || choiceNumber > 3);

	return ConvertNumberToFigure(choiceNumber);
}

void ShowFigures(const Figure& userChoice, const Figure& computerChoice)
{
	using namespace std;

	cout << "User choice: ";
	ShowFigure(userChoice);

	cout << "Computer choice: ";
	ShowFigure(computerChoice);
}

Winner GetWinner(const Figure& userChoice, const Figure& computerChoice)
{
	Winner winner;

	if ((userChoice == Figure::PAPER && computerChoice == Figure::PAPER) ||
		(userChoice == Figure::ROCK && computerChoice == Figure::ROCK) ||
		(userChoice == Figure::SCISSORS && computerChoice == Figure::SCISSORS))
		winner = Winner::DRAW;
	else if ((userChoice == Figure::PAPER && computerChoice == Figure::SCISSORS) ||
		(userChoice == Figure::ROCK && computerChoice == Figure::PAPER) ||
		(userChoice == Figure::SCISSORS && computerChoice == Figure::ROCK))
		winner = Winner::COMPUTER;
	else
		winner = Winner::USER;

	return winner;
}

void ShowWinner(const Winner& winner)
{
	using namespace std;

	switch (winner)
	{
	case Winner::USER:
		cout << "The winner is USER!\n";
		break;
	case Winner::COMPUTER:
		cout << "The winner is COMPUTER!\n";
		break;
	case Winner::DRAW:
		cout << "It is DRAW!\n";
		break;
	}
}

void ShowFigure(const Figure& figure)
{
	using namespace std;

	switch (figure)
	{
	case Figure::ROCK:
		cout << "Rock\n";
		break;
	case Figure::PAPER:
		cout << "Paper\n";
		break;
	case Figure::SCISSORS:
		cout << "Scissors\n";
		break;
	}
}