/*
3. List Copy Constructor
Modify your linked list class of Programming Challenges 1 and 2 to add a copy constructor.
Test your class by making a list, making a copy of the list, then displaying the values
in the copy.
*/

#include <iostream>
#include "LinkedList.h"

int main()
{
	LinkedList list1;

	for (int i = 0; i < 10; i++)
		list1.Append(i);

	LinkedList list2{ list1 };

	std::cout << "List1: ";
	list1.Print();
	std::cout << std::endl;

	std::cout << "List2: ";
	list2.Print();
	std::cout << std::endl;

	return 0;
}