// Specification file for the MathStack class
#pragma once
#include "IntStack.h"

class MathStack : public IntStack
{
public:
	MathStack(int s) 
		: IntStack(s)
	{ }

	void add();
	void sub();
	void mult();
	void div();
	void addAll();
	void multAll();
};