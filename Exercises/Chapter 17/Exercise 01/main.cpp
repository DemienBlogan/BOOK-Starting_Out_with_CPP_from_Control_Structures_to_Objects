/*
1. Unique Words
Write a program that opens a specified text file then displays a list of all the unique
words found in the file.

Hint: Store each word as an element of a set.
*/

#include <iostream>
#include <fstream>
#include <string>
#include <set>

using std::ifstream;
using std::string;
using std::set;
using std::cout;
using std::endl;

int main()
{
	ifstream file{ "File.txt" };
	set<string> uniqueWords;
	string word;

	while (file >> word)
		uniqueWords.insert(word);

	file.close();

	cout << "Unique words: ";

	for (const string& word : uniqueWords)
		cout << word << " ";
	cout << endl;

	return 0;
}