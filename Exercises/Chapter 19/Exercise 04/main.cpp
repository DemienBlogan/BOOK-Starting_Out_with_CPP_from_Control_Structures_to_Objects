/*
4. Dynamic Queue Template
Write your own version of a class template that will create a dynamic queue of any data
type. Demonstrate the class with a driver program.
*/

#include <iostream>
#include "Queue.h"

int main()
{
	Queue<int> myQueue;
	int value = 1;

	while (value != 10)
		myQueue.Enqueue(value++);

	while (!myQueue.IsEmpty())
		if (myQueue.Dequeue(value))
			std::cout << "We get value " << value << std::endl;

	return 0;
}