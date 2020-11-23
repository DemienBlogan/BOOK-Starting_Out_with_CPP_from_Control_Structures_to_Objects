/*
1. File Head Program
Write a program that asks the user for the name of a file. The program should display
the first ten lines of the file on the screen (the "head" of the file). If the file has fewer
than ten lines, the entire file should be displayed, with a message indicationg the entire
file has been displayed.

NOTE: Using an editor, you should create a simple text file that can be used to test
this program.
*/

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
	cout << "Enter the name of a file: ";
	string filename;
	getline(cin, filename);

	ifstream fin(filename);

	if (!fin)
	{
		cerr << "File '" << filename << "' could not been opened.\n";
		return 1;
	}

	size_t lines = 10;
	string line;
	size_t i;

	for (i = 0; i < lines; i++)
	{
		getline(fin, line);

		if (!fin)
			break;

		cout << "Line #" << i + 1 << ": " << line << endl;
	}

	fin.close();

	if (i != lines)
		cout << "We read the entire file.\n";

	return 0;
}