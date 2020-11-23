/*
16. Pig Latin
Write a program that reads a sentence as input and converts each word to "Pig Latin".
In one version, to convert a word to Pig Latin, you remove the first letter and place
that letter at the end of the word. Then you append the string "ay" to the word. Here
is an example:

English:    I SLEPT MOST OF THE NIGHT
Pig Lation: IAY LEPTSAY OSTMAY FOAY HETAY IGHTNAY
*/

#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

string EnterSentence();
vector<string> SeparateByWords(const string& sentence);
void ConvertPigLatin(vector<string>& words);
string ConcateWords(const vector<string>& words);
void ShowSentence(const string& sentence);

int main()
{
	string sentence = EnterSentence();

	vector<string> words = SeparateByWords(sentence);
	ConvertPigLatin(words);
	sentence = ConcateWords(words);

	ShowSentence(sentence);

	return 0;
}

string EnterSentence()
{
	cout << "Enter sentence: ";
	string sentence;
	getline(cin, sentence);

	return sentence;
}

vector<string> SeparateByWords(const string& sentence)
{
	stringstream ss(sentence);

	vector<string> words;
	string word;

	while (ss >> word)
		words.push_back(word);

	return words;
}

void ConvertPigLatin(vector<string>& words)
{
	size_t size = words.size();
	for (size_t i = 0; i < size; i++)
	{
		if (words[i].size() > 1)
		{
			words[i].push_back(words[i][0]);
			words[i].erase(0, 1);
		}

		words[i] += "AY";
	}
}

string ConcateWords(const vector<string>& words)
{
	string sentence;

	size_t size = words.size();
	for (size_t i = 0; i < words.size(); i++)
		sentence += i == 0 ? words[i] : " " + words[i];

	return sentence;
}

void ShowSentence(const string& sentence)
{
	cout << sentence << endl;
}