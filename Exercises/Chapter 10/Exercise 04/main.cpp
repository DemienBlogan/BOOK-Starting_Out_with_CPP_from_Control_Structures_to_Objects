/*
4. Average Number of Letters
Modify the program you wrote for Programming Challenge 3 (Word Counter), so it
also displays the average number of letters in each word.
*/

#include <iostream>
#include <cstring>
#include <string>
#include <cctype>

int CountAverageLetters(const char* str);
int CountAverageLetters(const std::string& str);

int main()
{
	using namespace std;

	cout << "Enter C-string: ";
	const size_t SIZE = 50;
	char str1[SIZE];
	cin.getline(str1, SIZE);

	int averageLetters = CountAverageLetters(str1);
	cout << "Your C-string has " << averageLetters << " average letters.\n";

	cout << "Enter string: ";
	string str2;
	getline(cin, str2);

	averageLetters = CountAverageLetters(str2);
	cout << "Your string has " << averageLetters << " average letters.\n";

	return 0;
}

int CountAverageLetters(const char* str)
{
	int words = 0;
	int letters = 0;
	char prevChar = '\0';
	size_t size = strlen(str);

	for (size_t i = 0; i < size; i++)
	{
		if (isalpha(str[i]))
			letters++;

		if (isalpha(str[i]) && !isalpha(prevChar))
			words++;

		prevChar = str[i];
	}

	int averageLetters = letters / words;

	return averageLetters;
}

int CountAverageLetters(const std::string& str)
{
	int words = 0;
	int letters = 0;
	char prevChar = '\0';

	for (size_t i = 0; i < str.size(); i++)
	{
		if (isalpha(str[i]))
			letters++;

		if (isalpha(str[i]) && !isalpha(prevChar))
			words++;

		prevChar = str[i];
	}

	int averageLetters = letters / words;

	return averageLetters;
}