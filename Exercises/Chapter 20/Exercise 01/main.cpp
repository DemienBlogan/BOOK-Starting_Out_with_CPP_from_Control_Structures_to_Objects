/*
1. Iterative Factorial
Write an iterative version (using a loop instread of recursion) of the factorial function
shown in this chapter. Test it with a driver program.
*/

#include <iostream>

double Factorial(int number)
{
	double factorial = 1;

	for (int i = 1; i <= number; i++)
		factorial *= i;

	return factorial;
}

int main()
{
	std::cout << "!5 = " << Factorial(5) << std::endl;
	std::cout << "!0 = " << Factorial(0) << std::endl;
	
	return 0;
}