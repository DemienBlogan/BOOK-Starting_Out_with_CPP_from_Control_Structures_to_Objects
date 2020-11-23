/*
7. Dynamic MathStack
The MathStack class shown in this chapter has only two member functions: add and
sub. Write the following additional member functions:

----------------------------------------------------------------------------------------
Function        Description
----------------------------------------------------------------------------------------
mult            Pops the top two values off the stack, multiplies them, and pushes
                their product onto the stack.

div             Pops the top two values off the stack, divides the second value by
                the first, and pushes the quotient onto the stack.

addAll          Pops all values off the stack, adds them, and pushes their sum onto
                the stack.

multAll         Pops all values off the stack, multiplies them, and pushes their product
                onto the stack.
----------------------------------------------------------------------------------------

Demonstrate the class with a driver program.
*/

#include <iostream>
#include "MathStack.h"

using namespace std;

int main()
{
	int catchVar;

	MathStack stack(5);

	for (int value = 1; value <= 5; value++)
	{
		cout << "Pushing " << value << "\n";
		stack.push(value);
	}

	stack.addAll();

	cout << "The sum is ";
	stack.pop(catchVar);
	cout << catchVar << endl << endl;

	for (int value = 1; value <= 5; value++)
	{
		cout << "Pushing " << value << "\n";
		stack.push(value);
	}

	stack.multAll();

	cout << "The product is ";
	stack.pop(catchVar);
	cout << catchVar << endl << endl;

	return 0;
}