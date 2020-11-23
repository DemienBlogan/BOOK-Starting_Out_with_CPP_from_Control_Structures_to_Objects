#include <cstdlib>

#include "Die.h"

Die::Die(int sides)
	: sides(sides), value(0)
{ }

void Die::Toss()
{
	if (sides > 0)
		value = rand() % sides;
}

int Die::GetValue() const
{
	return value;
}