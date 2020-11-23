/*
4. Tail Program
Write a program that asks the user for the name of a file. The program should display
the last ten lines of the file on the screen (the "tail" of the file). If the file has fewer
than ten lines, the entire file should be displayed, with a message indicationg the entire
file has been displayed.

NOTE: Using an editor, you should create a simple text file that can be used to test
this program.
*/

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

string EnterFilename();
void OpenFile(ifstream& fin, const string& filename);
size_t CountLines(ifstream& fin);
void MoveSeek(ifstream& fin, size_t lines);
void ShowFile(ifstream& fin);

int main()
{
	string filename = EnterFilename();
	ifstream fin;

	OpenFile(fin, filename);
	int lines = CountLines(fin);
	int tailLines = 10;

	if (lines - tailLines <= 0)
	{
		ShowFile(fin);
		cout << "\nWe read the entire file.\n";
	}
	else
	{
		MoveSeek(fin, lines - tailLines);
		ShowFile(fin);
	}

	fin.close();

	return 0;
}

string EnterFilename()
{
	cout << "Enter filename: ";
	string filename;
	getline(cin, filename);

	return filename;
}

void OpenFile(ifstream& fin, const string& filename)
{
	fin.open(filename);

	if (!fin)
	{
		cerr << "File '" << filename << "' could not been opened.\n";
		exit(1);
	}
}

size_t CountLines(ifstream& fin)
{
	size_t lines = 0;

	while (fin)
		if (fin.get() == '\n')
			lines++;

	fin.clear();
	fin.seekg(0L, ios::beg);

	if (lines != 0)
		lines++;

	return lines;
}

void MoveSeek(ifstream& fin, size_t lines)
{
	string line;

	for (size_t i = 0; i < lines; i++)
	{
		if (!fin)
			break;

		getline(fin, line);
	}
}

void ShowFile(ifstream& fin)
{
	char ch;
	while (fin)
	{
		ch = fin.get();
		cout << ch;
	}
}