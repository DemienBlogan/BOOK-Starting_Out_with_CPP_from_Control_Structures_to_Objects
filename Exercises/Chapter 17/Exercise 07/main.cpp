/*
7. Word Index
Write a program that reads the contents of a text file. The program should create a map
in which the key-value pairs are described as follows:

- Key    - The keys are the individual words found in the file.
- Values - Each value is a set that contains the line numbers in the file where the
  word (the key) is found.

For example, suppose the word "robot" is found in lines 7, 18, 94, and 138. The map
would contain an element in which the key was the string "robot", and the value was
a set containing the numbers 7, 18, 94, and 138.

Once the map is built, the program should create another text file, known as a word
index, listing the contents of the map. The word index file should contain an alhabetical
listing of the words that are stored as keys in the map, along with the line numbers
where the words appears in the original file. Figure 17-9 shows an example of an
original text file (Kennedy.txt) and its index file (index.txt).

Hint: See Chapter 10 for a discussion of string tokenizing.
*/

#include <iostream>
#include <string>
#include <map>
#include <set>
#include "Functions.h"

int main()
{
	std::string filename1{ "File1.txt" };
	std::string textFromFile = ReadFromFile(filename1);
	std::map<std::string, std::set<int>> wordsLines = GetWordsLines(textFromFile);
	std::string filename2{ "File2.txt" };
	WriteToFile(filename2, wordsLines);

	return 0;
}