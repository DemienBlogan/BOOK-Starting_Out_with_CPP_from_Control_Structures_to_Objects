/*
5. Line Numbers
(This assignment could be done as a modification of the program in Programming
Challenge 2). Write a program that asks the user for the name of a file. The program
should display the contents of the file on the screen. Each line of screen output should
be preceded with a line number, followed by a colon. The line numbering should start
at 1. Here is an example:

1. George Rolland
2. 127 Academy Street
3: Brasstown, NC 28706

If the file's contents won't fit on a single screen, the program should display 24 lines of
output at a time, and then pause. Each time program pauses, it should wait for the
user to strike a key before the next 24 lines are displayed.

NOTE: Using an editor, you should create a simple text file that can be used to test
this program.
*/

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
	cout << "Enter filename: ";
	string filename;
	getline(cin, filename);

	ifstream fin(filename);

	if (!fin)
	{
		cerr << "File '" << filename << "' could not been opened.\n";
		return 1;
	}

	string line;
	size_t lineNumber = 0;

	while (fin)
	{
		getline(fin, line);
		lineNumber++;

		cout << lineNumber << ": " << line << endl;

		if (lineNumber % 24 == 0)
		{
			system("pause");
			system("cls");
		}
	}

	fin.close();

	return 0;
}