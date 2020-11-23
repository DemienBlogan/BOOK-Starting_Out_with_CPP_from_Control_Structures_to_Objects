/*
5. Text File Analysis
Write a program that reads the contents of two text files and compares them in the
following ways:

- It should display a list of all the unique words contained in both files.
- It should display a list of the words that appears in both files.
- It should display a list of the words that appears in the first file, but not the second
- It should display a list of the words that appears in the second file, but not the first.
- It should display a list of the words that appears in either the first or second file,
  but not in both.

Hint: Use set operations to perform these analyses. Also, see Chapter 10 for a discusion
	  of string tokenizing
*/

#include <iostream>
#include <fstream>
#include <string>
#include <set>
#include "Functions.h"

int main()
{
#pragma region READ TEXT FROM FILE 1
	std::string filename1{ "File1.txt" };
	std::string textFromFile1 = ReadFromFile(filename1);
#pragma endregion

#pragma region READ TEXT FROM FILE 2
	std::string filename2{ "File2.txt" };
	std::string textFromFile2 = ReadFromFile(filename2);
#pragma endregion

#pragma region UNIQUE WORDS FROM FILE 1
	std::set<std::string> uniqueWordsFromFile1 = GetUniqueWords(textFromFile1);
	std::cout << "Unique words from file #1:\n";
	ShowWords(uniqueWordsFromFile1);
#pragma endregion

#pragma region UNIQUE WORDS FROM FILE 1
	std::set<std::string> uniqueWordsFromFile2 = GetUniqueWords(textFromFile2);
	std::cout << "Unique words from file #2:\n";	
	ShowWords(uniqueWordsFromFile2);
#pragma endregion

#pragma region SAME WORDS
	std::set<std::string> sameWords = GetSameWords(uniqueWordsFromFile1, uniqueWordsFromFile2);
	std::cout << "Same words in both lists:\n";
	ShowWords(sameWords);
#pragma endregion

#pragma region WORDS APPEAR IN FILE 1 BUT NOT IN FILE 2
	std::set<std::string> notAppearedInFile2Words = GetNotAppearedWords(uniqueWordsFromFile1, uniqueWordsFromFile2);
	std::cout << "Words appear in file 1 but not in file 2:\n";
	ShowWords(notAppearedInFile2Words);
#pragma endregion

#pragma region WORDS APPEAR IN FILE 2 BUT NOT IN FILE 1
	std::set<std::string> notAppearedInFile1Words = GetNotAppearedWords(uniqueWordsFromFile2, uniqueWordsFromFile1);
	std::cout << "Words appear in file 2 but not in file 1:\n";
	ShowWords(notAppearedInFile1Words);
#pragma endregion

#pragma region WORDS APPEAR IN FILE 1 OR IN FILE 2 BUT NOT IN BOTH
	std::cout << "Words appear in file 1 or in file 2 but not in both:\n";
	ShowWords(notAppearedInFile2Words);
	ShowWords(notAppearedInFile1Words);
#pragma endregion

	return 0;
}