/*
3. Word Counter
Write a function that accepts a pointer to a C-string as an argument and returns the
number of words contained in the string. For instance, if the string argument is "Four
score and seven years ago" the function should return the number 6. Demonstrate the
function in a prgoram that asks the user to input a string then passes it to the function.
The number of words in the string should be displayed on the screen. Optional
Exercise: Write an overloaded version of this function that accepts a string class
object as its argument.
*/

#include <iostream>
#include <cstring>
#include <string>
#include <cctype>

int CountWords(const char* str);
int CountWords(const std::string& str);

int main()
{
	using namespace std;

	cout << "Enter C-string: ";
	const size_t SIZE = 50;
	char str1[SIZE];
	cin.getline(str1, SIZE);

	int words = CountWords(str1);
	cout << "Your C-string has " << words << " words.\n";

	cout << "Enter string: ";
	string str2;
	getline(cin, str2);

	words = CountWords(str2);
	cout << "Your string has " << words << " words.\n";

	return 0;
}

int CountWords(const char* str)
{
	int words = 0;
	char prevChar = '\0';
	size_t size = strlen(str);

	for (size_t i = 0; i < size; i++)
	{
		if (isalpha(str[i]) && !isalpha(prevChar))
			words++;

		prevChar = str[i];
	}

	return words;
}

int CountWords(const std::string& str)
{
	int words = 0;
	char prevChar = '\0';

	for (size_t i = 0; i < str.size(); i++)
	{
		if (isalpha(str[i]) && !isalpha(prevChar))
			words++;

		prevChar = str[i];
	}

	return words;
}