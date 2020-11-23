/*
3. Static Queue Template
Write your own version of a class template that will create a static queue of any data
type. Demonstrate the class with a driver program.
*/

#include <iostream>
#include "Queue.h"

int main()
{
	Queue<int, 10> myQueue;
	int value = 1;

	while (!myQueue.IsFull())
		if (!myQueue.Enqueue(value++))
			std::cout << "Queue is full!\n";

	while (!myQueue.IsEmpty())
		if (myQueue.Dequeue(value))
			std::cout << "We get value " << value << std::endl;

	return 0;
}