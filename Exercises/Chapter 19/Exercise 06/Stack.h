#pragma once
#include <list>

template <typename T>
class Stack
{
private:
	std::list<T> container;

public:
	Stack() = default;

	bool IsEmpty() const { return container.empty(); }

	void Push(const T& value)
	{
		container.push_back(value);
	}

	bool Pop(T& value)
	{
		if (IsEmpty())
			return false;

		value = container.back();
		container.pop_back();

		return true;
	}
};