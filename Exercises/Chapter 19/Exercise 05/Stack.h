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
		try
		{
			container.push_back(value);
		}
		catch (const std::bad_alloc& exc)
		{
			throw exc;
		}
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