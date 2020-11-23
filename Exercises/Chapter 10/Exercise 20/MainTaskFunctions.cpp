#include <iostream>
#include <ctime>
#include <cstdlib>

#include "MainTaskFunctions.h"

void SetRandom()
{
	srand(static_cast<unsigned>(time(nullptr)));
}

void OpenFile(ifstream& file, const string& fileName)
{
	file.open(fileName);

	if (!file)
	{
		cerr << "File '" << fileName << "' could not been found.\n";
		exit(1);
	}
}

void ReadFromFile(ifstream& file, vector<array<int, 5>>& allWinCombinations, vector<int>& allPowerBallWinNumbers)
{
	while (!file.eof())
	{
		// Read win combinations
		array<int, 5> winCombination;

		for (size_t i = 0; i < winCombination.size(); i++)
			file >> winCombination[i];

		allWinCombinations.push_back(winCombination);

		// Read PowerBall win number
		int powerBallWinNumber;
		file >> powerBallWinNumber;

		allPowerBallWinNumbers.push_back(powerBallWinNumber);
	}
}

void SetTicket(array<int, 5>& userTicket)
{
	bool numberAlreadyExists;

	for (size_t i = 0; i < userTicket.size(); i++)
	{
		numberAlreadyExists = false;

		userTicket[i] = rand() % 69 + 1; // 1...69

		for (size_t j = 0; j < i; j++)
		{
			if (userTicket[i] == userTicket[j])
			{
				numberAlreadyExists = true;
				break;
			}
		}

		if (numberAlreadyExists)
			i--;
	}
}

void SetPowerBallNumber(int& userPowerBallNumber)
{
	userPowerBallNumber = rand() % 26 + 1;
}

void ShowUserCombination(const array<int, 5>& userTicket, int userPowerBallNumber)
{
	cout << "Your ticket: ";
	for (size_t i = 0; i < userTicket.size(); i++)
		cout << userTicket[i] << " ";
	cout << endl;

	cout << "Your PowerBall number: " << userPowerBallNumber << "\n\n";
}

void ShowWinCombination(const array<int, 5>& winCombination, int winPowerBallNumber)
{
	cout << "Win combination: ";
	for (size_t i = 0; i < winCombination.size(); i++)
		cout << winCombination[i] << " ";
	cout << endl;

	cout << "Win PowerBall number: " << winPowerBallNumber << "\n\n";
}

size_t SelectWin5NumbersIndex(size_t allWinCombinationsSize)
{
	if (allWinCombinationsSize == 0)
	{
		cerr << "Error in function 'SelectWin5NumbersIndex': incorrect size.\n";
		exit(2);
	}

	return rand() % allWinCombinationsSize;
}

size_t SelectWinPowerBallIndex(size_t allPowerBallWinNumbersSize)
{
	if (allPowerBallWinNumbersSize == 0)
	{
		cerr << "Error in function 'SelectWinPowerBallIndex': incorrect size.\n";
		exit(3);
	}

	return rand() % allPowerBallWinNumbersSize;
}

int CountSameNumbers(
	const array<int, 5>& winCombination, const array<int, 5>& userTicket,
	int winPowerBallNumber, int userPowerBallNumber)

{
	int sameNumbers = 0;

	for (size_t i = 0; i < userTicket.size(); i++)
	{
		for (size_t j = 0; j < winCombination.size(); j++)
		{
			if (userTicket[i] == winCombination[j])
			{
				sameNumbers++;
				break;
			}
		}
	}

	if (userPowerBallNumber == winPowerBallNumber)
		sameNumbers++;

	return sameNumbers;
}

void ShowResult(int sameNumbers)
{
	switch (sameNumbers)
	{
	case 0:
		cout << "You didn't win anything.\n";
		break;
	case 1:
		cout << "You win $10.\n";
		break;
	case 2:
		cout << "You win $100.\n";
		break;
	case 3:
		cout << "You win $1,000.\n";
		break;
	case 4:
		cout << "You win $10,000.\n";
		break;
	case 5:
		cout << "You win $100,000.\n";
		break;
	case 6:
		cout << "You win $1,000,000. It's jackpot!\n";
		break;
	default:
		cerr << "Error in function 'ShowResult': incorrect number of same numbers.\n";
		exit(4);
	}
}