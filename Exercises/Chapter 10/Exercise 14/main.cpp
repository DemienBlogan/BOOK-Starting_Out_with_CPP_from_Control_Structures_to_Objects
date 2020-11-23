/*
14. Word Separator
Write a program that accepts as input a sentence in which all of the words are run
together, but the first character of each word is uppercase. Convert the sentence to a
string in which the words are separated by spaces and only the first word starts with
an uppercase letter. For example, the string "StipAndSmellTheRoses." would be converted
to "Stop and smell the roses.".
*/

#include <iostream>
#include <string>

using namespace std;

void SeparateWords(string& sentence);
void ShowSentence(const string& sentence);
string EnterString();

int main()
{
	string sentence = EnterString();
	SeparateWords(sentence);
	ShowSentence(sentence);

	return 0;
}

void SeparateWords(string& sentence)
{
	string separetedSentence;

	size_t size = sentence.size();
	for (size_t i = 0; i < size; i++)
	{
		separetedSentence.push_back(sentence[i]);

		if (isupper(sentence[i + 1]))
			separetedSentence.push_back(' ');
	}

	sentence = separetedSentence;
}

void ShowSentence(const string& sentence)
{
	cout << sentence << endl;
}

string EnterString()
{
	cout << "Enter sentence: ";
	string sentence;
	cin >> sentence;

	return sentence;
}