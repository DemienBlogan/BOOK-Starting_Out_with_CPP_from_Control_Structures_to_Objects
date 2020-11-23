/*
6. Word Frequency
Write a program that reads the contents of a text file. The program should create a
map in which the keys are the individual words found in the file and the values are
the number of times each word appears. For example, if the word "the" appears 128
times, the map would contain an element with "the" as the key and 128 as the value.
The program should either display the frequency of each word or create a second file
containing a list of each word and its frequency.

Hint: See Chapter 10 for a discussion of string tokenizing
*/

#include <map>
#include <string>
#include <vector>
#include "Functions.h"

int main()
{
	std::string filename{ "File1.txt" };
	std::string textFromFile = ReadFromFile(filename);
	std::vector<std::string> words = GetWords(textFromFile);
	std::map<std::string, unsigned> wordsCount = GetWordsCount(words);
	Show(wordsCount);

	return 0;
}