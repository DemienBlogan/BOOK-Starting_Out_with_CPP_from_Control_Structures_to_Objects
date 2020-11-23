/*
8. SimpleVector Modification
Modify the SimpleVector class template presented in this chapter to include the
member functions push_back and pop_back. The push_back function should accept an
argument and insert its value at the end of the array. The pop_back function should
accept no argument and remove the last element from the array. Test the calss with a
driver program.
*/

#include <iostream>
#include "SimpleVector.h"

using std::cout;
using std::endl;

int main()
{
	SimpleVector<int> vector;

	for (size_t i = 0; i < 3; i++)
		vector.push_back(i + 1);

	for (size_t i = 0; i < vector.GetSize(); i++)
		cout << vector[i] << " ";
	cout << endl;

	size_t size = vector.GetSize();
	for (size_t i = 0; i < size; i++)
		vector.pop_back();

	if (vector.GetSize() == 0)
		cout << "Vector in empty now.\n";

	return 0;
}