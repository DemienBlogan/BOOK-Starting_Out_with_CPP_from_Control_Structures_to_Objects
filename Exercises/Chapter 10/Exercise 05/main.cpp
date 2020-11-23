/*
5. Sentence Capitalizer
Write a function that accepts a pointer to a C-string as an argument and capitalizes
the first character of each sentence in the string. For instance, if the string argument is
"hello. my name is Joe. what is your name?" the function should manipulate
the string so that it contains "Hello. My name is Joe. What is your name?"
Demonstrate the function in a program that asks the user to input a string then passes
it to the function. The modified string should be displayed on the screen. Optional
Exercse: Write an overloaded version of this function that accepts a string class object
as its argument.
*/

#include <iostream>
#include <cstring>
#include <string>
#include <cctype>

void Capitalize(char* str);
void Capitalize(std::string& str);

int main()
{
	using namespace std;

	cout << "Enter C-string: ";
	const size_t SIZE = 100;
	char str1[SIZE];
	cin.getline(str1, SIZE);

	Capitalize(str1);

	cout << "Your C-string (capitalized): " << str1 << endl;

	cout << "Enter string: ";
	string str2;
	getline(cin, str2);

	Capitalize(str2);

	cout << "Your string (capitalized): " << str2 << endl;

	return 0;
}

void Capitalize(char* str)
{
	size_t size = strlen(str);

	bool sentenceStarted = false;

	for (size_t i = 0; i < size; i++)
	{
		if (isalpha(str[i]) && !sentenceStarted)
		{
			str[i] = toupper(str[i]);
			sentenceStarted = true;
		}

		if (str[i] == '.' || str[i] == '!' || str[i] == '?')
			sentenceStarted = false;
	}
}

void Capitalize(std::string& str)
{
	bool sentenceStarted = false;

	for (size_t i = 0; i < str.size(); i++)
	{
		if (isalpha(str[i]) && !sentenceStarted)
		{
			str[i] = toupper(str[i]);
			sentenceStarted = true;
		}

		if (str[i] == '.' || str[i] == '!' || str[i] == '?')
			sentenceStarted = false;
	}
}