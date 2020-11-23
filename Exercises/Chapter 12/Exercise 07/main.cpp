/*
7. Sentence Filter
Write a program that asks the user for two file names. The first file will be opened for
input, and the second file will be opened for output. (It will be assumed the first file contains
sentences that end with a period). The program will read the contents of the first
file and change all the letters to lowercase except the first letter of each sentence, which
should be made uppercase. The revised contents should be stored in the second file.

NOTE: Using an editor, you should create a simple text file that can be used to test
this program.
*/

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
	string inFileName, outFileName;

	// Enter file names.
	cout << "Enter input file name: ";
	getline(cin, inFileName);

	cout << "Enter output file name: ";
	getline(cin, outFileName);

	// Create and open files.
	ifstream inFile(inFileName);
	ofstream outFile(outFileName);

	// Check opening.
	if (!inFile || !outFile)
	{
		cerr << "ERROR: one or two files aren't created or been opened.\n";
		return 1;
	}

	// Read text from input file.
	string text;
	int ch;
	while (!inFile.eof())
	{
		ch = inFile.get();
		if (ch != EOF)
			text.push_back(static_cast<char>(ch));
	}

	// Filter text.
	bool newSentenceStarted = true;
	for (size_t i = 0; i < text.size(); i++)
	{
		if (newSentenceStarted && isalpha(text[i]))
		{
			text[i] = toupper(text[i]);
			newSentenceStarted = false;
		}
		else if (!newSentenceStarted)
			text[i] = tolower(text[i]);

		if (text[i] == '.' || text[i] == '?' || text[i] == '!')
			newSentenceStarted = true;
	}

	// Write text in output file.
	outFile << text;

	// Close files.
	inFile.close();
	outFile.close();

	return 0;
}