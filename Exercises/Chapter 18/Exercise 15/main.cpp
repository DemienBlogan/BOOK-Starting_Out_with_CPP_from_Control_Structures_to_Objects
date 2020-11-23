/*
15. pop and push Member Functions
The STL list container has member function named pop_back, pop_front, puch_back,
and push_front, as described in Table 18-2. Modify the linked list class you created
in Programming Challenge 1 (or the LinkedList template presented in this chapter) by
adding your own versions of these member functions.
*/

#include <iostream>
#include "LinkedList.h"

int main()
{
	LinkedList<int> list;

	for (int i = 0; i < 10; i++)
		list.Append(i);

	list.Print();
	std::cout << std::endl;

	list.pop_front();
	list.pop_front();

	list.Print();
	std::cout << std::endl;

	list.pop_back();
	list.pop_back();
	list.pop_back();

	list.Print();
	std::cout << std::endl;

	list.push_front(100);
	list.push_front(200);
	list.push_front(300);

	list.Print();
	std::cout << std::endl;

	list.push_back(1000);
	list.push_back(2000);

	list.Print();
	std::cout << std::endl;

	return 0;
}