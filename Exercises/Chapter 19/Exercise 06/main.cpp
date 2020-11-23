/*
6. Dynamic String Stack
Desing a class that stores strings on a dynamic stack. The strings should not be fixed
in length. Demonstrate the class with a driver program.
*/

#include <iostream>
#include <vector>
#include <string>
#include "Stack.h"

int main()
{
	Stack<std::string> myStack;

	std::vector<std::string> names =
	{
		"Demien", "Olga", "Vita",
		"Marina", "David", "Nazar"
	};

	for (const auto& name : names)
		myStack.Push(name);

	std::string name;
	while (!myStack.IsEmpty())
		if (myStack.Pop(name))
			std::cout << "We get value " << name << std::endl;

	return 0;
}