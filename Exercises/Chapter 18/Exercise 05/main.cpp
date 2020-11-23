/*
5. List Search
Modify the linked list class you created in the previous programming challenges to
include a member function named search that returns the position of a specific value,
x, in the linked list. The first node in the list is at position 0, the second node is
at position 1, and so on. If x is not found on the list, the search should return -1. Test
the new member function using an appropriate driver program.
*/

#include <iostream>
#include "LinkedList.h"

int main()
{
	LinkedList list;

	for (int i = 0; i < 10; i++)
		list.Append(i);

	std::cout << "List: ";
	list.Print();
	std::cout << std::endl;

	std::cout << "Searching for value 3. ";
	int findIndex = list.Search(3);
	if (findIndex != -1)
		std::cout << "List has this value. Index " << findIndex << std::endl;
	else
		std::cout << "List doesn't have this value.\n";


	std::cout << "Searching for value 5. ";
	findIndex = list.Search(5);
	if (findIndex != -1)
		std::cout << "List has this value. Index " << findIndex << std::endl;
	else
		std::cout << "List doesn't have this value.\n";

	std::cout << "Searching for value 100. ";
	findIndex = list.Search(100);
	if (findIndex != -1)
		std::cout << "List has this value. Index " << findIndex << std::endl;
	else
		std::cout << "List doesn't have this value.\n";

	return 0;
}