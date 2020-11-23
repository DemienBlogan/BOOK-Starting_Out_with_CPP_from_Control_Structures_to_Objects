/*
14. Balanced Parentheses
A string of characters has balanced parentheses if each right parenthesis occurring
in the string is matched with a preceding left parenthesis, in the same way that each
right brace in a C++ program is matched with a preceding left brace. Write a program
that uses a stack to determine whether a string entered at the keyboard has balanced
parentheses.
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
	bool correctOrder = true;

	while (!charStack.IsEmpty())
	{
		charStack.Pop(ch);

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
	}

	if (closedParantheses != 0)
		correctOrder = false;

	if (correctOrder)
		std::cout << "String has correct order of parantheses.\n";
	else
		std::cout << "String doesn't have correct order of parantheses.\n";

	return 0;
}