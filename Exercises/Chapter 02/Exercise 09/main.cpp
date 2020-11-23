/*
9. Cyborg Data Type Sizes
You have been give a job as a programmer on a Cyborg supercomputer. In order to
accomplish some calculations, you need to know how many bytes the following data
types use: char, int, float, and double. You do not have any technical documentation,
so you can't look this information up. Write a C++ program that will determine
the amount of memory used by these types and display the information on the screen.
*/

#include <iostream>
using namespace std;

int main()
{
	size_t intBytes = sizeof(int), charBytes = sizeof(char);
	size_t floatBytes = sizeof(float), doubleBytes = sizeof(double);

	cout << "Bytes of type 'int' = " << intBytes << endl;
	cout << "Bytes of type 'char' = " << charBytes << endl;
	cout << "Bytes of type 'float' = " << floatBytes << endl;
	cout << "Bytes of type 'double' = " << doubleBytes << endl;

	return 0;
}