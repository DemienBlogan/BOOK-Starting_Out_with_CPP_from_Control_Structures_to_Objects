/*
2. Dynamic Stack Template
Write your own version of a class template that will create a dynamic stack of any
data type. Demonstrate the class with a driver program.
*/

#include <iostream>
#include "Stack.h"

int main()
{
	Stack<int> myStack;
	int value = 1;

	while (value != 10)
		myStack.Push(value++);

	while (!myStack.IsEmpty())
		if (myStack.Pop(value))
			std::cout << "We get value " << value << std::endl;

	return 0;
}