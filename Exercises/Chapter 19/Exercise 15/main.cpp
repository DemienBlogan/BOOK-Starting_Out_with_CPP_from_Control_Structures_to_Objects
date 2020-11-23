/*
15. Balanced Multiple Delimiters
A string may use more than one type of delimiter to bracket information into "blocks".
For example, a string may use braces {}, parentheses (), and brackets [] as delimiters.
A string is properly delimited if each right delimiter is matched with a preceding left
delimiter of the same type in such a way that either the resulting block of information
are disjoint, or one of them is completely nested within the other. Write a program
that uses a single stack to check whether a string containing braces, parentheses, and
brackets is properly delimited.
*/

#include <iostream>
#include <string>
#include "Stack.h"

int main()
{
	std::cout << "Enter string: ";
	std::string str;
	std::getline(std::cin, str);

	Stack<char> charStack;

	for (size_t i = 0; i < str.length(); i++)
		charStack.Push(str[i]);

	char ch;

	int closedParantheses = 0, openedParantheses = 0;
	int closedBraces = 0, openedBraces = 0;
	int closedBrackets = 0, openedBrackets = 0;

	bool correctOrder = true;

	while (!charStack.IsEmpty())
	{
		charStack.Pop(ch);

		// PARANTHESES ()
		if (ch == '(')
		{
			if (closedParantheses == 0)
			{
				correctOrder = false;
				break;
			}
			else
			{
				openedParantheses++;
				closedParantheses--;
			}
		}
		else if (ch == ')')
			closedParantheses++;
		// BRACKETS []
		else if (ch == '[')
		{
			if (closedBrackets == 0)
			{
				correctOrder = false;
				break;
			}
			else
			{
				openedBrackets++;
				closedBrackets--;
			}
		}
		else if (ch == ']')
			closedBrackets++;
		// BRACERS []
		else if (ch == '[')
		{
			if (closedBraces == 0)
			{
				correctOrder = false;
				break;
			}
			else
			{
				openedBrackets++;
				closedBraces--;
			}
		}
		else if (ch == ']')
			closedBraces++;
	}

	if (closedParantheses != 0 || closedBrackets != 0 || closedBraces != 0)
		correctOrder = false;

	if (correctOrder)
		std::cout << "String has correct order of parantheses.\n";
	else
		std::cout << "String doesn't have correct order of parantheses.\n";

	return 0;
}