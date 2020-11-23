#pragma once
#include <list>

template <typename T>
class Queue
{
private:
	std::list<T> container;

public:
	Queue() = default;

	void Enqueue(const T& value)
	{
		container.push_back(value);
	}

	bool Dequeue(T& value)
	{
		if (IsEmpty())
			return false;

		value = container.front();
		container.pop_front();

		return true;
	}

	bool IsEmpty() const
	{
		return container.empty();
	}
};