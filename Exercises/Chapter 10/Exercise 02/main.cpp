/*
2. Backward String
Write a function that accepts a pointer to a C-string as an argument and displays its
contents backward. For instance, if the string argument is "Gravity" the function
should display "ytivarG". Demonstrate the function in a program that asks the user
to input a string passes it to the function.
*/

#include <iostream>
#include <cstring>

void ShowReverse(const char* str);

int main()
{
	using namespace std;

	cout << "Enter string: ";
	const size_t SIZE = 50;
	char str[SIZE];
	cin.getline(str, SIZE);

	cout << "Your string: " << str << endl;
	cout << "Reverse str: ";
	ShowReverse(str);

	return 0;
}

void ShowReverse(const char* str)
{
	using namespace std;

	size_t size = strlen(str);
	for (int i = size - 1; i >= 0; i--)
		cout << str[i];
	cout << endl;
}