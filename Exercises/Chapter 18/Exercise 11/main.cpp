/*
11. List Search
Modify the LinkedList template shown in this chapter to include a member function
named search. The function should search the list for a specified value. If the value
is found, it should return a number indicating its position in the list. (The first node
is node 1, the second node is node 2, and so forth). If the value is not found, the function
should return 0. Demonstrate the function in a driver program.
*/

#include <iostream>
#include "LinkedList.h"

int main()
{
	LinkedList<int>	list;

	for (int i = 10; i < 20; i++)
		list.appendNode(i);

	list.displayList();

	int foundNode = list.search(3);
	if (foundNode != 0)
		std::cout << "Value 3 is in node #" << foundNode << std::endl;
	else
		std::cout << "List doesn't have value 3\n";

	foundNode = list.search(14);
	if (foundNode != 0)
		std::cout << "Value 14 is in node #" << foundNode << std::endl;
	else
		std::cout << "List doesn't have value 3\n";

	return 0;
}