/*
8. List Template
Create a list class template based on the list class you created in the previous programming
challenges.
*/

#include <iostream>
#include "LinkedList.h"

int main()
{
	LinkedList<char> list;

	for (char letter = 'A'; letter <= 'Z'; letter++)
		list.Append(letter);

	std::cout << "List: ";
	list.Print();
	std::cout << std::endl;

	list.Reserve();

	std::cout << "List: ";
	list.Print();
	std::cout << std::endl;

	return 0;
}