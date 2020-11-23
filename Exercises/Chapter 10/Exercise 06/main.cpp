/*
6. Vowels and Consonants
Write a function that accepts a pointer to a C-string as its argument. The function
should count the number of vowels appearing in the string and return that number.

Write another function that accepts a pointer to a C-string as its argument. This function
should count the number of consonants appearing in the string and return that number.

Demonstrate these two functions in a program that performs the following steps:
1. The user is asked to enter a string.
2. The program displays the following menu:
   A) Count the number of vowels in the string
   B) Count the number of consonants in the string
   C) Count both the vowels and consonats in the string
   D) Enter another string
   E) Exit the program
3. The program performs the operation selected by the user and repeats until the user
   selects E to exit the program.
*/

#include <iostream>
#include <cstring>
#include <cctype>

bool IsVowel(char ch);
bool IsConsonant(char ch);
int CountVowels(const char* text);
int CountConsonants(const char* text);
void EnterString(char* text, size_t size);

int main()
{
	using namespace std;

	const size_t SIZE = 50;
	char text[SIZE];
	char menuItem;

	cout << "Enter text: ";
	EnterString(text, SIZE);

	do
	{
		cout << "A) Count the number of vowels in the string           \n";
		cout << "B) Count the number of consonants in the string       \n";
		cout << "C) Count both the vowels and consonants in the string \n";
		cout << "D) Enter another string                               \n";
		cout << "E) Exit the program                                   \n";
		cin >> menuItem;
		cin.ignore();

		switch (menuItem)
		{
		case 'A': case 'a':
			cout << "Number of vowels = " << CountVowels(text) << endl;
			break;

		case 'B': case 'b':
			cout << "Number of consonants = " << CountConsonants(text) << endl;
			break;

		case 'C': case 'c':
			cout << "Number of vowels and consonants = ";
			cout << CountVowels(text) + CountConsonants(text) << endl;
			break;

		case 'D': case 'd':
			cout << "Enter text: ";
			EnterString(text, SIZE);
			break;

		case 'E' : case 'e':
			cout << "Goodbye!\n";
			break;

		default:
			cout << "Incorrect input. Try again.\n";
			break;
		}

	} while (menuItem != 'E' && menuItem != 'e');

	return 0;
}

bool IsVowel(char ch)
{
	return ch == 'A' || ch == 'a' || 
		   ch == 'E' || ch == 'e' || 
		   ch == 'I' || ch == 'i' ||
		   ch == 'O' || ch == 'o' ||
		   ch == 'U' || ch == 'u' ? true : false;
}

bool IsConsonant(char ch)
{
	return isalpha(ch) && !IsVowel(ch) ? true : false;
}

int CountVowels(const char* text)
{
	int vowels = 0;

	size_t size = strlen(text);
	for (size_t i = 0; i < size; i++)
		if (IsVowel(text[i]))
			vowels++;

	return vowels;
}

int CountConsonants(const char* text)
{
	int consonants = 0;

	size_t size = strlen(text);
	for (size_t i = 0; i < size; i++)
		if (IsConsonant(text[i]))
			consonants++;

	return consonants;
}

void EnterString(char* text, size_t size)
{
	using namespace std;

	cin.getline(text, size);
}