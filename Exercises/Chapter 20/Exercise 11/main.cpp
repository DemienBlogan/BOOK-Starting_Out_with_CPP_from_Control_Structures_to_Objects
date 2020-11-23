/*
11. Palindrome Detector
A palindrome is any word, phrase, or sentence that reads that same forward and backward.
Here are some well-known palindromes:

Able was I, ere I saw Elba
A man, a plan, a canal, Panama
Desserts, I stressed
Kayak

Write a bool function that uses recursion to determine if a string argument is a palindrome.
The function should return true if the argument reads the same forward and backward.
Demonstrate the function in a program.
*/

#include <iostream>
#include <string>

bool IsPalindrom(const std::string& str, size_t first, size_t last)
{
	if (first == last)
		return true;

	if (str[first] != str[last])
		return false;

	return IsPalindrom(str, first + 1, last - 1);
}

int main()
{
	std::string str1{ "radar" };

	if (IsPalindrom(str1, 0, str1.size() - 1))
		std::cout << str1 << " - is palindrom.\n";

	std::string str2{ "Hello" };

	if (IsPalindrom(str2, 0, str2.size() - 1))
		std::cout << str2 << " - is palindrom.\n";

	return 0;
}