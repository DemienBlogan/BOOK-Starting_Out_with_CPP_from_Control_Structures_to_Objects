/*
3. Punch Line
Write a program that reads and prints a joke and its punch line from two different files.
The first file contains a joke, but not its punch line. The second file has the punch line
as its last line, preceded by "garbage". The main function of your program should open
the two files then call two functions, passing each one the file it needs. The first function
should read and display each line in the file it is passed (the joke file). The second function
should display only the last line of the file it is passed (the punch line file). It should
find this line by seeking to the end of the file and then backing up to the beginning of the
last line. Data to test your program can be found in the joke.txt and punchline.txt files.
*/

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

string ReadJoke(ifstream& jokeFile);
string ReadPunchLine(ifstream& punchLineFilename);

int main()
{
	string punchLineFilename = "PunchLine.txt";
	string jokeFilename = "Joke.txt";
	ifstream punchLineFile(punchLineFilename);
	ifstream jokeFile(jokeFilename);

	if (!punchLineFile)
	{
		cerr << "File '" << punchLineFilename << "' could not been opened.\n";
		return 1;
	}

	if (!jokeFile)
	{
		cerr << "File '" << jokeFilename << "' could not been opened.\n";
		return 1;
	}

	string joke = ReadJoke(jokeFile);
	string punchLine = ReadPunchLine(punchLineFile);

	cout << "Joke:\n" << joke << "\n\n";
	cout << "Punch Line:" << punchLine << endl;

	punchLineFile.close();
	jokeFile.close();

	return 0;
}

string ReadJoke(ifstream& jokeFile)
{
	string joke;

	while (jokeFile)
	{
		string line;
		getline(jokeFile, line);
		joke += line;
	}

	return joke;
}

string ReadPunchLine(ifstream& punchLineFilename)
{
	string punchLine;

	char ch;

	punchLineFilename.seekg(-1L, ios::end);
	punchLineFilename.get(ch);

	while (ch != '\n')
	{
		punchLineFilename.seekg(-2L, ios::cur);
		punchLineFilename.get(ch);
	}

	while (!punchLineFilename.eof())
	{
		punchLine.push_back(ch);
		punchLineFilename.get(ch);
	}

	return punchLine;
}