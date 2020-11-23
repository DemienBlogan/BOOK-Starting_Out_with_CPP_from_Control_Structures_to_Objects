/*
8. Prime Number Generation
A positive integer greater than 1 is said to be prime if it has no divisors other than 1 and
itself. A positive integer greater than 1 is composite if it is not prime. Write a program
that asks the user to enter an integer greater than 1, then displays all of the prime numbers
that are less than or equal to the number entered. The program should work as follows:

- Once the user has entered a number, the program should populate a vector with
  all of the integers from 2, up through the value entered.
- The program should then use the STL's for_each function to step through the
  vector. The for_each function should pass each element to a function object that
  displays the element if it is a prime number.
*/

#include "Functions.h"

int main()
{
	int minLimit = 2;
	int number = EnterPositiveNumber(minLimit);
	std::vector<int> numbers = GetAllNumbers(minLimit, number);
	ShowPrimeNumbers(numbers);

	return 0;
}