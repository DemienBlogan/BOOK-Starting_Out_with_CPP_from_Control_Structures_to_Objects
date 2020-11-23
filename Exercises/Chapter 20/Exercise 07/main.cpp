/*
7. Sum of Numbers
Write a function that accepts an integer argument and returns the sum of all the integers
from 1 up to the number passed as an argument. For example, if 50 is passed as
an argument, the function will return the sum 1, 2, 3, 4, ... 50. Use recursion to
calculate the sum. Demonstrate the function in a program.
*/

#include <iostream>

int Sum(int number)
{
	return number == 1 ? number : number + Sum(number - 1);
}

int main()
{
	std::cout << "Sum of 1...10 = " << Sum(10) << std::endl;

	return 0;
}