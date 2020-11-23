/*
7. Member Removal by Position
Modify the linked list class you created in the previous programming challenges by
adding a member function for deleting a node at a specified position. A value of 0
for the position means the first node in the list (the current head) is deleted. The
function does nothing if the specified position is greater than or equal to the 
length of the list.
*/

#include <iostream>
#include "LinkedList.h"

int main()
{
	LinkedList list;

	for (int i = 10; i < 20; i++)
		list.Append(i);

	std::cout << "List: ";
	list.Print();
	std::cout << std::endl;

	list.Delete(static_cast<size_t>(3));
	list.Delete(static_cast<size_t>(7));
	list.Delete(static_cast<size_t>(20));

	std::cout << "List: ";
	list.Print();
	std::cout << std::endl;

	return 0;
}