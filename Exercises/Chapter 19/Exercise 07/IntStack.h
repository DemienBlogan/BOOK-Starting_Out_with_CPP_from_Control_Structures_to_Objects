#pragma once

class IntStack
{
private:
	int* stackArray;
	int stackSize;
	int top;

public:
	IntStack(int);

	IntStack(const IntStack&);

	~IntStack();

	void push(int);
	void pop(int&);
	bool isFull() const;
	bool isEmpty() const;
};