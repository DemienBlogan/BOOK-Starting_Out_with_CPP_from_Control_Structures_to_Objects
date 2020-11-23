/*
1. String Length
Write a function that returns an integer and accepts a pointer to a C-string as an argument.
The function should count the number of characters in the string and return that
number. Demonstrate the function in a simple program that asks the user to input a
string, passes it to the function, then displays the function's return value.
*/

#include <iostream>

int CountChars(const char* str);

int main()
{
	using namespace std;

	cout << "Enter string: ";
	const size_t SIZE = 50;
	char str[SIZE];
	cin.getline(str, SIZE);

	int chars = CountChars(str);

	cout << "Your string has " << chars << " characters.\n";

	return 0;
}

int CountChars(const char* str)
{
	int chars = 0;

	while (*(str++) != '\0')
		chars++;

	return chars;
}