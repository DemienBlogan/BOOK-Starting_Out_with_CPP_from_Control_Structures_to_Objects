/*
25. Using Files-Student Line Up
Modify the Student Line Up program described in Programming Challenge 14 so it
gets the names from a file. Names should be read in until there is no more data to
read. If you have downloaded this book's source code you will find a file named
LineUp.txt in the Chapter 05 folder. You can use this file to test the program.
*/

#include <iostream>
#include <fstream>
#include <string>

int main()
{
	using namespace std;

	ifstream file("LineUp.txt");

	if (!file)
	{
		cout << "The file 'LineUp.txt' could not been found.\n";
		return 1;
	}

	string name, frontName, endName;

	if (!(file >> name))
	{
		cout << "The list of names is empty.\n";
		return 2;
	}

	frontName = endName = name;
	while (file >> name)
	{
		if (frontName > name)
			frontName = name;
		if (endName < name)
			endName = name;
	}

	cout << "Front student is " << frontName << endl;
	cout << "End student is " << endName << endl;

	return 0;
}