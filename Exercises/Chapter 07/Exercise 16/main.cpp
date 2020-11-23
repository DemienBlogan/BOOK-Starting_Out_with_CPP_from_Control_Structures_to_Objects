/*
16. World Series Champions
If you have downloaded this book's source code, you will find the following files in this
chapter's folder:

- Teams.txt - This file contains a list of several Major League baseball teams in alphabetical
  order. Each team listed in the file has won the World Series at least once.
- WorldSeriesWinners.txt - This file contains a chronological list of the World Series
  winning teams from 1903 to 2012. (The first line in the file is the name of the team
  that won in 1903, and the last line is the name of the team that won in 2012. Note
  the World Series was not played in 1904 or 1994).

Write a program that displays the contents of the Teams.txt file on the screen and
prompts the user to enter the name of one of the teams. The program should then display
the number of times that team has won the World Series in the time period from
1903 to 2012.

TIP: Read the contents of the WorldSeriesWinners.txt file into an array or vector.
When the user enters the name of a team, the program should step through the array
or vector counting the number of times the selected team appears.
*/

#include <iostream>
#include <fstream>
#include <vector>
#include <string>

int main()
{
	using namespace std;

	ifstream teamsFile("Teams.txt");
	ifstream worldSeriesWinnersFile("WorldSeriesWinners.txt");

	if (!teamsFile)
	{
		cout << "Error. File 'Teams.txt' could not been opened.\n";
		return 1;
	}

	if (!worldSeriesWinnersFile)
	{
		cout << "Error. File 'WorldSeriesWinners.txt' could not been opened.\n";
		return 2;
	}

	string team;

	// Reading teams
	vector<string> teams;
	while (!teamsFile.eof())
	{
		getline(teamsFile, team);
		teams.push_back(team);
	}

	// Reading world winners
	vector<string> worldWinners;
	while (!worldSeriesWinnersFile.eof())
	{
		getline(worldSeriesWinnersFile, team);
		worldWinners.push_back(team);
	}

	teamsFile.close();
	worldSeriesWinnersFile.close();

	cout << "All teams:\n";
	for (const string& team : teams)
		cout << team << endl;

	cout << "Enter the team you are interested in: ";
	string userTeam;
	getline(cin, userTeam);

	// 1. Перевірити, чи userTeam існує в teams.
	// 2. Пройтись по worldWinners, найти в ньому команду userTeam і порахувати, скільки
	// разів вона виграла. 
	// 3. Вивести на екран.

	return 0;
}