/*
2. Characters for the ASCII Codes
Write a program that uses a loop to display the characters for the ASCII codes 0
through 127. Display 16 characters on each line.
*/

#include <iostream>

int main()
{
	using namespace std;

	for (char character = 0; character < 127; character++)
	{
		if (character % 16 == 0)
			cout << endl;

		cout << character << " ";
	}

	return 0;
}