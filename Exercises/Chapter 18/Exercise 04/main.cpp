/*
4. List Reverse
Modify the linked list class you created in the previous programming challenges to
include a member function named reverse that rearranges the nodes in the list so their
order is reversed. Demonstrate the function in a simple driver program.
*/

#include <iostream>
#include "LinkedList.h"

int main()
{
	LinkedList list1;

	for (int i = 0; i < 10; i++)
		list1.Append(i);

	LinkedList list2{ list1 };
	list2.Reserve();

	std::cout << "List1: ";
	list1.Print();
	std::cout << std::endl;

	std::cout << "List2: ";
	list2.Print();
	std::cout << std::endl;

	return 0;
}