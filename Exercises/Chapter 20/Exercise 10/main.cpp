/*
10. maxNode Function
Add a member function named maxNode to the NumberList class discussed in this
chapter. The function should return the largest value stored in the list. Use recursion
in the function to traverse the list. Demonstrate the function in a driver.
*/

#include <iostream>
#include "NumberList.h"

int main()
{
	NumberList list;

	list.appendNode(11.2);
	list.appendNode(35.21);
	list.appendNode(3.54);
	list.appendNode(7.39);
	list.appendNode(19.32);

	double maxValue = list.GetMaxNode();

	std::cout << maxValue << std::endl;

	return 0;
}