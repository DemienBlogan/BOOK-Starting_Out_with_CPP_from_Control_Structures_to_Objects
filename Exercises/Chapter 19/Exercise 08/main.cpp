/*
8. Dynamic MathStack Template
Currently, the MathStack class is derived from the IntStack class. Modify it so it is a
template, derived from the template you created in Programming Challenge 2 (Dynamic
Stack Template).
*/

#include <iostream>
#include "MathStack.h"

using namespace std;

int main()
{
	int catchVar;

	MathStack<int> stack;

	for (int value = 1; value <= 5; value++)
	{
		cout << "Pushing " << value << "\n";
		stack.Push(value);
	}

	stack.addAll();

	cout << "The sum is ";
	stack.Pop(catchVar);
	cout << catchVar << endl << endl;

	for (int value = 1; value <= 5; value++)
	{
		cout << "Pushing " << value << "\n";
		stack.Push(value);
	}

	stack.multAll();

	cout << "The product is ";
	stack.Pop(catchVar);
	cout << catchVar << endl << endl;

	return 0;
}