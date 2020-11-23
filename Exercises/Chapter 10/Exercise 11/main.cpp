/*
11. Case Manipulator
Write a program with three functions: upper, lower, and reverse. The upper function
should accept a pointer to a C-string as an argument. It should tep through each
charater in the string, converting it to uppercase. The lower function, too, should
accept a pointer to a C-string as an argument. It should step through each character
in the string, converting it to lowercase. Like upper and lower, reverse should also
accept a pointer to a string. As it steps through the stirng, it should test each character
to determine whether it is uppercase or lowercase. If a character is uppercase, it should
be converted to lowercase. Likewise, if a character is lowercase, it should be converted
to uppercase.

Test the functions by asking for a string in function main, then passing it to them 
in the following order: reverse, lower, and upper.
*/

#include <iostream>
#include <cstring>
#include <cctype>

void upper(char* str);
void lower(char* str);
void reverse(char* str);

int main()
{
	using namespace std;

	const size_t SIZE = 40;
	char str[SIZE];

	cout << "Enter string: ";
	cin.getline(str, SIZE);

	cout << "Origin string: " << str << endl;
	reverse(str);
	cout << "Reverse string: " << str << endl;
	lower(str);
	cout << "Lower string: " << str << endl;
	upper(str);
	cout << "Upper string: " << str << endl;
	
	return 0;
}

void upper(char* str)
{
	size_t size = strlen(str);

	for (size_t i = 0; i < size; i++)
		str[i] = toupper(str[i]);
}

void lower(char* str)
{
	size_t size = strlen(str);

	for (size_t i = 0; i < size; i++)
		str[i] = tolower(str[i]);
}

void reverse(char* str)
{
	size_t size = strlen(str);

	for (size_t i = 0; i < size; i++)
	{
		if (islower(str[i]))
			str[i] = toupper(str[i]);
		else if (isupper(str[i]))
			str[i] = tolower(str[i]);
	}
}