/*
11. Inheritance Modification
Assuming you have completed Programming Challenges 9 and 10, modify the inheritance
hierarchy of the SearchableVector class template so it is derived from the
SortableVector class instead of the SimpleVector class. Implement a member function
named sortAndSearch, both a sort and a binary search.
*/

#include <iostream>
#include "SearchableVector.h"

using std::cout;

int main()
{
	SearchableVector<int> vector;

	for (int i = 10; i >= 0; i--)
		vector.push_back(i + 1);

	int foundIndex = vector.sortAndSearch(3);

	if (foundIndex != -1)
		cout << "Array has element with index #" << foundIndex << " that has value 3.\n";

	foundIndex = vector.sortAndSearch(100);

	if (foundIndex == -1)
		cout << "Array doesn't have value 100.\n";

	return 0;
}