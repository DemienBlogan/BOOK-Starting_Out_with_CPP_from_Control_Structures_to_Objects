#include <iostream>
#include <ctime>

#include "Game.h"

using std::cout;
using std::cin;
using std::endl;

bool Game::AskUserAboutToss() const
{
	ShowUserPoints();

	cout << "You want to toss? (Y - yes, N - no): ";
	char answer;
	cin >> answer;

	ClearBuffer();

	return answer == 'Y' || answer == 'y';
}

void Game::ClearBuffer() const
{
	while (cin.get() != '\n')
		continue;
}

Game::Game()
	: user(2, 6), computer(2, 6)
{
	srand(static_cast<unsigned>(time(nullptr)));
}

void Game::PlayRound()
{
	// User turn
	bool userAnswerYes = AskUserAboutToss();

	if (userAnswerYes)
	{
		int previousUserPoints = user.GetPoints();
		user.Toss();
		int earnedPoints = user.GetPoints() - previousUserPoints;
		cout << "You get " << earnedPoints << endl;
	}

	// Computer turn
	if (computer.GetPoints() < 10)
	{
		computer.Toss();
		cout << "Computer toss.\n";
	}
	else
		cout << "Computer doesn't toss.\n";

	// Show result
	ShowUserPoints();

	// Stop game
	if (user.GetPoints() > 21 || !userAnswerYes)
		isPlaying = false;

	system("pause");
	system("cls");
}

bool Game::IsPlaying() const
{
	return isPlaying;
}

void Game::ShowUserPoints() const
{
	cout << "Your points now = " << user.GetPoints() << endl;
}

void Game::ShowComputerPoints() const
{
	cout << "Computer points now = " << computer.GetPoints() << endl;
}

void Game::ShowWinner() const
{
	cout << "Game is over.\n";

	int userPoints = user.GetPoints();
	int computerPoints = computer.GetPoints();

	ShowUserPoints();
	ShowComputerPoints();

	if (userPoints > 21 && computerPoints > 21)
		cout << "YOU BOTH LOSE!\n";
	else if (userPoints > 21 || userPoints < computerPoints)
		cout << "COMPUTER WIN!\n";
	else if (computerPoints > 21 || userPoints > computerPoints)
		cout << "YOU WIN!\n";
	else
		cout << "DRAW!\n";
}