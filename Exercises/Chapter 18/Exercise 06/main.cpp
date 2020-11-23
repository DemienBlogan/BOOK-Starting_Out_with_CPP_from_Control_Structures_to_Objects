/*
6. Member Insertion by Position
Modify the linked list class you created in the previous programming challenges by
adding a member function for inserting a new item at a specified position. A position of 0
means that the value will become the first item on the list, a position of 1 means the value
will become the second item on the list, and so on. A position equal to or greater than the
length of the list means the value is placed at the end of the list.
*/

#include <iostream>
#include "LinkedList.h"

int main()
{
	LinkedList list;

	for (int i = 0; i < 10; i++)
		list.Append(i);

	list.Insert(100, 3);
	list.Insert(200, 5);

	std::cout << "List: ";
	list.Print();
	std::cout << std::endl;

	return 0;
}