/*
1. Your Own Linked List
Design your own linked list class to hold a series of integers. The class should have
member functions for appending, inserting, and deleting nodes. Don't forget to add a
destructor that destroys the list. Demonstrate the class with a driver program.
*/

#include <iostream>
#include "LinkedList.h"

int main()
{
	LinkedList list;

	for (int i = 0; i < 10; i += 2)
	{
		list.Append(i);
		
		std::cout << "List: ";
		list.Print();
		std::cout << std::endl;
	}

	for (int i = 1; i < 10; i += 2)
	{
		list.Insert(i);

		std::cout << "List: ";
		list.Print();
		std::cout << std::endl;
	}

	for (int i = 0; i < 10; i++)
	{
		if (list.Delete(i))
			std::cout << "Value " << i << " was deleted.\n";

		std::cout << "List: ";
		list.Print();
		std::cout << std::endl;
	}

	return 0;
}