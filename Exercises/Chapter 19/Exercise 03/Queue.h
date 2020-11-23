#pragma once
template <typename T, size_t SIZE>
class Queue
{
private:
	T arr[SIZE];
	int first;
	int last;
	size_t currentSize;
public:
	Queue()
		: arr{}, last(-1), first(-1), currentSize(0)
	{ }

	bool Enqueue(const T& value)
	{
		if (IsFull())
			return false;

		last = (last + 1) % SIZE;
		arr[last] = value;

		currentSize++;

		return true;
	}

	bool Dequeue(T& value)
	{
		if (IsEmpty())
			return false;

		first = (first + 1) % SIZE;
		value = arr[first];

		currentSize--;

		return true;
	}

	bool IsEmpty() const
	{
		return currentSize == 0;
	}

	bool IsFull() const
	{
		return currentSize == SIZE;
	}
};