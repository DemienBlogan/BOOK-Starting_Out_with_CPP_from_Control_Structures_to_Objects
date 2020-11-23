/*
14. Overloaded [] Operator
Modify the linked list class you created in Programming Challenge 1 (or the
LinkedList template presented in this chapter) by adding an overloaded [] operator
function. This will give the linked list the ability to access nodes using a subscript,
like an array. The subscript 0 will reference the first node in the list, the subscript 1
will reference the second node in the list, and so forth. The subscript of the last node
will be the number of nodes minus 1. If an invalid subscript is used, the function should
throw an exception.
*/

#include <iostream>
#include "LinkedList.h"

int main()
{
	LinkedList<int> list;

	for (int i = 0; i < 10; i++)
		list.Append(i);

	try
	{
		for (int i = 0; i < 11; i++)
		{
			if (i == 5)
				list[i] = 1000;

			std::cout << list[i] << " ";
		}
		std::cout << std::endl;
	}
	catch (const std::out_of_range& exc)
	{
		std::cout << exc.what() << std::endl;
	}

	return 0;
}