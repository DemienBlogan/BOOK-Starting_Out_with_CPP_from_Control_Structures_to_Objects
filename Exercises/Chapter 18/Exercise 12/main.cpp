/*
12. Double Merge
Modify the NumberList class shown in this chapter to include a member function
named mergeArray. The mergeArray function should take an array of doubles as
its first argument, and an integer as its second argument. (The second argument will
specify the size of the array being passed into the first argument).

The function should merge the values in the array into the linked list. The value in
each element of the array should be inserted (not appended) into the linked list. When
the values are inserted, they should be in numerical order. Demonstrate the function
with a driver program. When you are satisfied with the function, incorporate it into
the LinkedList template.
*/

#include <iostream>
#include "NumberList.h"

int main()
{
	NumberList list;

	for (int i = 0; i < 30; i += 3)
		list.appendNode(i);

	list.displayList();
	
	std::cout << "---------\n";

	const size_t SIZE = 5;
	double arr[SIZE] = { 10.1, 20.2, 3.3, 5.5, 4.4 };

	list.mergeArray(arr, SIZE);
	list.displayList();

	return 0;
}