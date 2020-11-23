// This program demonstrates the insertNode member function.
#include <iostream>
#include "example 18-3-NumberList.h"
using namespace std;

int main()
{
	// Define a NumberList object.
	NumberList list;

	// Append some values to the list.
	list.appendNode(2.5);
	list.appendNode(7.9);
	list.appendNode(12.6);

	// Insert a node in the middle of the list.
	list.insertNode(10.5);

	// Display the list.
	list.displayList();
	return 0;
}