#pragma once

template <typename T, size_t SIZE>
class Stack
{
private:
	T arr[SIZE];
	size_t top;

public:
	Stack()
		: top(0), arr{}
	{ }

	bool IsEmpty() const { return top == 0; }
	bool IsFull() const { return top == SIZE; }

	bool Push(const T& value)
	{
		if (IsFull())
			return false;

		arr[top++] = value;

		return true;
	}

	bool Pop(T& value)
	{
		if (IsEmpty())
			return false;

		value = arr[--top];
		
		return true;
	}
};