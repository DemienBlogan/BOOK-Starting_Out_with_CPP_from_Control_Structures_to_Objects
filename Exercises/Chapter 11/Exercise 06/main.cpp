/*
6. Soccer Scores
Write a program that stores the following data about a soccer player in a structure:
	Player's Name
	Player's Number
	Points Scored by Player
The program should keep an array of 12 of these structures. Each element is for a different
player on a team. When the program runs, it should ask the user to enter the data
for each player. It should then show a table that lists each player's number, name, and
points scored. The program should also calculate and display the total points earned by
the team. The number and name of the player who has earned the most points should
also be displayed.

Input Validation: Do not accept negative values for players' numbers or points scored.
*/

#include <iostream>
#include <string>

using namespace std;

struct Player
{
	string name;
	int number;
	int score;
};

void EnterTeam(Player team[], size_t size);
void ShowTeam(const Player team[], size_t size);
int CalculateTolalPoints(const Player team[], size_t size);
const Player& FindBestPlayer(const Player team[], size_t size);

int main()
{
	const size_t PLAYERS = 12;
	Player team[PLAYERS];

	EnterTeam(team, PLAYERS);
	ShowTeam(team, PLAYERS);

	int totalPoints = CalculateTolalPoints(team, PLAYERS);
	cout << "Total points = " << totalPoints << endl;

	const Player& bestPlayer = FindBestPlayer(team, PLAYERS);
	cout << "Best Player " << bestPlayer.name << " (" << bestPlayer.number << ")\n";

	return 0;
}

void EnterTeam(Player team[], size_t size)
{
	for (size_t i = 0; i < size; i++)
	{
		cout << "Player #" << i + 1 << ":\n";

		cout << "\t Enter name: ";
		getline(cin, team[i].name);

		cout << "\t Enter number: ";
		cin >> team[i].number;
		cin.ignore();

		cout << "\t Enter score: ";
		cin >> team[i].score;
		cin.ignore();
	}
}

void ShowTeam(const Player team[], size_t size)
{
	for (size_t i = 0; i < size; i++)
	{
		cout << "Player #" << i + 1 << ":\n";
		cout << "\tName: " << team[i].name << endl;
		cout << "\tNumber: " << team[i].number << endl;
		cout << "\tScore: " << team[i].score << endl;
	}
}

int CalculateTolalPoints(const Player team[], size_t size)
{
	int totalPoints = 0;

	for (size_t i = 0; i < size; i++)
		totalPoints += team[i].score;

	return totalPoints;
}

const Player& FindBestPlayer(const Player team[], size_t size)
{
	int bestScore = team[0].score;
	int bestPlayerIndex = 0;

	for (size_t i = 1; i < size; i++)
	{
		if (bestScore < team[i].score)
		{
			bestScore = team[i].score;
			bestPlayerIndex = i;
		}
	}

	return team[bestPlayerIndex];
}