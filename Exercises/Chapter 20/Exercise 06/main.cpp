/*
6. Recursive Power Function
Write a function that uses recursion to raise a number to a power. The function should
accept two arguments: the number to be raised and the exponent. Assume that the
exponent is a nonnegative integer. Demonstrate the function in a program.
*/

#include <iostream>

int Power(int number, int power)
{
	return power == 1 ? number : number * Power(number, power - 1);
}

int main()
{
	std::cout << "2^10 = " << Power(2, 10) << std::endl;

	return 0;
}