/*
5. Recursive Multiplication
Write a recursive function that accepts two arguments into the parameteres x and y.
The function should return value the value of x times y. Remember, muptiplication can
be performd as repeated addition:
7 * 4 = 4 + 4 + 4 + 4 + 4 + 4 + 4
*/

#include <iostream>

int Multiple(int x, int y)
{
	return y <= 1 ? x : x + Multiple(x, y - 1);
}

int main()
{
	int x = 5, y = 3;
	int product = Multiple(x, y);

	std::cout << "5 * 3 = " << product << std::endl;

	return 0;
}