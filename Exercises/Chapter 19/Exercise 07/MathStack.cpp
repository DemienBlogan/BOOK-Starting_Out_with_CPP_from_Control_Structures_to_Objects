#include "MathStack.h"

void MathStack::add()
{
	int num, sum;

	pop(sum);
	pop(num);

	sum += num;

	push(sum);
}

void MathStack::sub()
{
	int num, diff;

	pop(diff);
	pop(num);

	diff -= num;

	push(diff);
}

void MathStack::mult()
{
	int num, prod;

	pop(prod);
	pop(num);

	prod *= num;

	push(prod);
}

void MathStack::div()
{
	int num, division;

	pop(division);
	pop(num);

	division /= num;

	push(division);
}

void MathStack::addAll()
{
	int sum = 0;
	int value;

	while (!isEmpty())
	{
		pop(value);
		sum += value;
	}

	push(sum);
}

void MathStack::multAll()
{
	int product = 1;
	int value;

	while (!isEmpty())
	{
		pop(value);
		product *= value;
	}

	push(product);
}