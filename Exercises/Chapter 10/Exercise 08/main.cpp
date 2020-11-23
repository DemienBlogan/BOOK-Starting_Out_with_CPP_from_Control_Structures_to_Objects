/*
8. Sum of Digits in a String
Write a program that asks the user to enter a series of single-digit numbers with nothing
separating them. Read the input as a C-string or a string object. The program
should display the sum of all the single-digit numbers in the string. For example, if the
user enters 2514, the program should display 12, which is the sum of 2, 5, 1, and 4.
The program should also display the highest and lowest digits in the string.
*/

#include <iostream>
#include <cstring>
#include <cctype>

int SumDigits(const char* str);
int GetHighestDigit(const char* str);
int GetLowestDigit(const char* str);
void EnterString(char* str, size_t size);

int main()
{
	using namespace std;

	const size_t SIZE = 30;
	char digitStr[SIZE];

	EnterString(digitStr, SIZE);

	int sum = SumDigits(digitStr);
	int max = GetHighestDigit(digitStr);
	int min = GetLowestDigit(digitStr);

	cout << "Sum = " << sum << endl;
	cout << "Max = " << max << endl;
	cout << "Min = " << min << endl;
	
	return 0;
}

int SumDigits(const char* str)
{
	int sum = 0;

	size_t size = strlen(str);
	for (size_t i = 0; i < size; i++)
		sum += str[i] - 48;

	return sum;
}

int GetHighestDigit(const char* str)
{
	int highestDigit = str[0] - 48;

	size_t size = strlen(str);
	for (size_t i = 1; i < size; i++)
		if (highestDigit < str[i] - 48)
			highestDigit = str[i] - 48;

	return highestDigit;
}

int GetLowestDigit(const char* str)
{
	int lowestDigit = str[0] - 48;

	size_t size = strlen(str);
	for (size_t i = 1; i < size; i++)
		if (lowestDigit > str[i] - 48)
			lowestDigit = str[i] - 48;

	return lowestDigit;
}

void EnterString(char* str, size_t size)
{
	using namespace std;

	cout << "Enter digit-string: ";
	cin.getline(str, size);
}