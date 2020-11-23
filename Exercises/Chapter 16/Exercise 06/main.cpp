/*
6. IntArray Class Exception
Chapter 14 presented an IntArray class that dynamically creates an array of integers
and performs bounds checking on the array. If an invalid subscript is used with
the class, it displays an error message and aborts the program. Modify the class so it
throws an exception instead.
*/

#include <iostream>
#include "IntArray.h"

using std::cout;
using std::exception;
using std::endl;

int main()
{
	IntArray arr{ 5 };

	try
	{
		for (size_t i = 0; i < arr.GetSize() + 3; i++)
			cout << arr[i] << " ";
	}
	catch (const std::exception& exc)
	{
		cout << exc.what() << endl;
	}

	return 0;
}