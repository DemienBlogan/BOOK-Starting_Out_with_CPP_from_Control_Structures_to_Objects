/*
1. Static Stack Template
Write your own version of a class template that will create a static stack of any data
type. Demonstrate the class with a driver program.
*/

#include <iostream>
#include "Stack.h"

int main()
{
	Stack<int, 5> myStack;
	int value = 1;

	while (!myStack.IsFull())
		if (!myStack.Push(value++))
			std::cout << "Stack is full!\n";

	while (!myStack.IsEmpty())
		if (myStack.Pop(value))
			std::cout << "We get value " << value << std::endl;

	return 0;
}