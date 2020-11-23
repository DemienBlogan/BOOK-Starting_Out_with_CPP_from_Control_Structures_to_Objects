/*
6. String Search
Write a program that asks the user for a file name and a string for which to search.
The program should search the file for every occurrence of a specified string. When
the string is found, the line that contains it should be displayed. After all the occurrences
have been located, the program should report the number of times the string
appeared in the file.

NOTE: Using an editor, you should create a simple text file that can be used to test
this program.
*/

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

string EnterFilename();
void OpenFile(ifstream& fin, const string& filename);
string ReadFile(ifstream& fin);
string EnterSearchString();
void StringSearch(const string& text, const string& searchStirng);

int main()
{
	string filename = EnterFilename();
	ifstream fin;

	OpenFile(fin, filename);

	string text = ReadFile(fin);
	string searchString = EnterSearchString();
	StringSearch(text, searchString);

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

string ReadFile(ifstream& fin)
{
	string text;
	char ch;
	while (!fin.eof())
	{
		ch = fin.get();
		text.push_back(ch);
	}

	return text;
}

string EnterSearchString()
{
	string searchString;
	cout << "Enter search string: ";
	getline(cin, searchString);
	return searchString;
}

void StringSearch(const string& text, const string& searchStirng)
{
	size_t findCount = 0;

	size_t findIndex = text.find(searchStirng);
	while (findIndex != string::npos)
	{
		findCount++;
		cout << "Finding line #" << findCount << ": ";

		// Find beginning of line.
		int index = findIndex;
		while (index > 0 && text[index] != '\n')
			index--;

		if (index != 0)
			index++;

		// Show full line.
		while (index < text.size() && text[index] != '\n')
			cout << text[index++];
		cout << endl;

		findIndex = text.find(searchStirng, findIndex + 1);
	}

	cout << "Finding count = " << findCount << endl;
}