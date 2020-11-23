/*
9. SearchableVector Modification
Modify the SearchableVector class template presented in this chapter so it performs
a binary search instead of a linear search. Test the template in a driver program.
*/

#include <iostream>
#include "SearchableVector.h"

using std::cout;

int main()
{
	SearchableVector<int> vector;

	for (size_t i = 0; i < 10; i++)
		vector.push_back(i + 1);

	int foundIndex = vector.findItem(3);

	if (foundIndex != -1)
		cout << "Array has element with index #" << foundIndex << " that has value 3.\n";
	
	foundIndex = vector.findItem(100);

	if (foundIndex == -1)
		cout << "Array doesn't have value 100.\n";

	return 0;
}