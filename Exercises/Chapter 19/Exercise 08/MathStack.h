// Specification file for the MathStack class
#pragma once
#include "Stack.h"

template <typename T>
class MathStack : public Stack<T>
{
public:
	MathStack()
		: Stack<T>()
	{ }

	void Add()
	{
		int num, sum;

		Stack<T>::Pop(sum);
		Stack<T>::Pop(num);

		sum += num;

		Stack<T>::Push(sum);
	}

	void Subtract()
	{
		int num, diff;

		Stack<T>::Pop(diff);
		Stack<T>::Pop(num);

		diff -= num;

		Stack<T>::Push(diff);
	}

	void Muliple()
	{
		int num, prod;

		Stack<T>::Pop(prod);
		Stack<T>::Pop(num);

		prod *= num;

		Stack<T>::Push(prod);
	}

	void Divide()
	{
		int num, division;

		Stack<T>::Pop(division);
		Stack<T>::Pop(num);

		division /= num;

		Stack<T>::Push(division);
	}

	void addAll()
	{
		int sum = 0;
		int value;

		while (!Stack<T>::IsEmpty())
		{
			Stack<T>::Pop(value);
			sum += value;
		}

		Stack<T>::Push(sum);
	}

	void multAll()
	{
		int product = 1;
		int value;

		while (!Stack<T>::IsEmpty())
		{
			Stack<T>::Pop(value);
			product *= value;
		}

		Stack<T>::Push(product);
	}
};