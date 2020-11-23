/*
15. Average Number of Words
If you have downloaded this book's soruce code, you will find names text.txt
in the Chapter 12 folder. The text that is in the file is stored as one sentence per line.
Write a program that reads the file's contents and calculates the average number of
words per sentence.
*/

#include <iostream>
#include <fstream>
#include <string>
#include <cctype>
#include <iomanip>

using std::cout;
using std::cin;
using std::cerr;
using std::endl;
using std::string;
using std::getline;
using std::ifstream;
using std::fixed;
using std::setprecision;

void OpenFileForRead(ifstream& fin, const string& filename);
string ReadSentenceFromFile(ifstream& fin);
int CalculateWords(const string& sentence);

int main()
{
	const string FILENAME = "File.txt";
	ifstream fin;

	OpenFileForRead(fin, FILENAME);

	int totalSentences = 0;
	int totalWords = 0;

	while (!fin.eof())
	{
		string sentence = ReadSentenceFromFile(fin);
		int words = CalculateWords(sentence);

		totalWords += words;
		totalSentences++;
	}

	double averageWords = static_cast<double>(totalWords) / totalSentences;

	cout << fixed << setprecision(1);
	cout << "Average number of words = " << averageWords << endl;

	fin.close();

	return 0;
}

void OpenFileForRead(ifstream& fin, const string& filename)
{
	fin.open(filename);

	if (!fin)
	{
		cerr << "File '" << filename << "' could not been opened.\n";
		exit(1);
	}
}

string ReadSentenceFromFile(ifstream& fin)
{
	string sentence;
	getline(fin, sentence);
	return sentence;
}

int CalculateWords(const string& sentence)
{
	int words = 0;
	bool wordStarted = false;

	for (size_t i = 0; i < sentence.length(); i++)
	{
		if (isalpha(sentence[i]) && !wordStarted)
		{
			words++;
			wordStarted = true;
		}
		else if (!isalpha(sentence[i]) && wordStarted)
			wordStarted = false;
	}

	return words;
}