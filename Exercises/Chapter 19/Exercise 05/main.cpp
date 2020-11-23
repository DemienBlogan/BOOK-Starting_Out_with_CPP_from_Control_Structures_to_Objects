/*
5. Error Testing
The DynIntStack and DynIntQueue classes shown in this chapter are abstract data
types using a dynamic stack and dynamic queue, respectively. The classes do not
currently test for memory allocation errors. Modify the classes so they determine
whether new nodes cannot be created by handling the bad_alloc exception.

NOTE: If you have already done Programming Challenges 2 and 4, modify the templates
	  you created.
*/

#include <iostream>
#include "Queue.h"
#include "Stack.h"

int main()
{
	try
	{
		Stack<int> myStack;

		while (true)
			myStack.Push(1);
	}
	catch (const std::bad_alloc& exc)
	{
		std::cout << exc.what() << std::endl;
	}

	try
	{
		Queue<int> myQueue;

		while (true)
			myQueue.Enqueue(1);
	}
	catch (const std::bad_alloc& exc)
	{
		std::cout << exc.what() << std::endl;
	}

	return 0;
}