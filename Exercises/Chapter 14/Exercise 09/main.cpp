/*
9. FeetInches Modification
Modify the FeetInches class discussed in this chapter so it overloads the following
operators:
<=
>=
!=
Demonstrate the class's capabilities in a simple program.
*/

#include <iostream>
#include "FeetInches.h"

using std::cout;

int main()
{
	FeetInches first{ 5, 4 };
	FeetInches second{ 6, 3 };

	if (first >= second)
		cout << "first >= second\n";

	if (first != second)
		cout << "first != second\n";

	if (second <= first)
		cout << "second != first\n";

	return 0;
}