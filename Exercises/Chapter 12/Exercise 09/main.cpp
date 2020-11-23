/*
9. File Encryption Filter
File encryption is the science of writing the contents of a file in a secret code. Your
encryption program should work like a filter, reading the contents of one file, modifying
the data into a code, then writing the coded contents out to a second file. The
second file will be a version of the first file, but written in a secret code.

Although there are complex encryption techniques, you should come up with a simple
one of your own. For example, you could read the first file one character at a time,
and add 10 to the ASCII code of each character before it is written to the second file.
*/

#include <iostream>
#include <fstream>

using namespace std;

int main()
{
	ifstream inputFile("InputFile.txt");
	ofstream outputFile("OutputFile.txt");

	if (!inputFile)
	{
		cerr << "Error. File 'InputFile.txt' could not been opened.\n";
		return 1;
	}

	if (!outputFile)
	{
		cerr << "Error. File 'outputFile.txt' could not been opened/created.\n";
		return 2;
	}

	int character;

	character = inputFile.get();
	while (!inputFile.eof())
	{
		character += 10;
		outputFile << static_cast<char>(character);
		character = inputFile.get();
	}

	cout << "Encryption completed!\n";

	inputFile.close();
	outputFile.close();

	return 0;
}