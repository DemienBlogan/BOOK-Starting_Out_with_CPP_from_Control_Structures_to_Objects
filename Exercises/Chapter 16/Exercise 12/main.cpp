/*
12. Specialized Templates
In this chapter, the section Specialized Templates within Section 16.4 describes how
to design templates that are specialized for one particular data type. The section introduces
a method for specializing a version of the SimpleVector class template so it
will work with strings. Complete the specialization for both the SimpleVector and
SearchableVector templates. Demonstrate them with a simple driver program.
*/

#include <iostream>
#include "SimpleVector.h"

using std::cout;
using std::endl;

int main()
{
	char arr1[] = "Hello";
	char arr2[] = "Goodbye";
	char arr3[] = "What?";

	SimpleVector<char*> vector;

	vector.push_back(arr1);
	vector.push_back(arr2);
	vector.push_back(arr3);
	
	for (size_t i = 0; i < vector.GetSize(); i++)
		cout << vector[i] << " ";
	cout << endl;

	return 0;
}