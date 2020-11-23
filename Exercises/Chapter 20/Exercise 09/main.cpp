/*
9. String Reverser
Write a recursive function that accepts a string object as its argument and prints the
string in reverse order. Demonstrate the function in a driver program.
*/

#include <iostream>
#include <string>

void ShowReverse(const std::string& str, size_t index)
{
	if (index < str.size() - 1)
		ShowReverse(str, index + 1);

	std::cout << str[index];
}

int main()
{
	std::string str{ "Hello World" };

	ShowReverse(str, 0);

	return 0;
}