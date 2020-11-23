/*
14. Fishing Game Simulation
For this assignment, you will write a program that program simulates a fishing game. In this
game, a six-sided die is rolled to determine what the user has cought. Each possible item
is worth a certain number of fishing points. The points will not be displayed until the
user has finished fishing, then a message is displayed congratulating the user depending
on the number of fishing points gained.

Here are some suggestions for the game's design:
- Each round of the game is performed as an iteration of a loop that repeats as long
  as the palyer wants to fish for more items.
- At the beginning of each round, the program will ask the user whether he or she
  wants to continue fishing.
- The program simulates the rolling of a six-sided die (use the Die class the was
  demonstrated in this chapter).
- Each item that can be caught is represented by a number generated from the die. For
  example, 1 for "a huge fish", 2 for "an old shoe", 3 for "a little fish", and so on.
- Each item the user catches is worth a different amount of points.
- The loop keeps a running total of the user's fishing points.
- After the loop has finished, the total number of fishing points is displayed, along
  with a message that varies depending on the number of points earned.
*/

#include <iostream>
#include <string>

#include "Die.h"

using std::cout;
using std::cin;
using std::string;
using std::endl;

int GetFishingPoints(int value);
string GetFishName(int value);

int main()
{
	Die die;
	int points = 0;
	
	bool continueFishing = true;

	while (continueFishing)
	{
		die.roll();

		cout << "You've caught: " << GetFishName(die.getValue()) << endl;

		points += GetFishingPoints(die.getValue());

		cout << "You want to continue fishing? (Y - yes, N - no): ";
		char answer;
		cin >> answer;

		if (answer == 'N' || answer == 'n')
			continueFishing = false;
	}

	cout << "Your points = " << points << endl;

	return 0;
}

int GetFishingPoints(int value)
{
	switch (value)
	{
	case 1:
		return 10;
	case 2:
		return 20;
	case 3:
		return 30;
	case 4:
		return 40;
	case 5:
		return 50;
	case 6:
		return 60;
	default:
		return 0;
	}
}

string GetFishName(int value)
{
	switch (value)
	{
	case 1:
		return "Gold fish";
	case 2:
		return "Silver fish";
	case 3:
		return "Killer Krokk";
	case 4:
		return "Amadeus";
	case 5:
		return "Gladius";
	case 6:
		return "God fish";
	default:
		return "Error fish";
	}
}