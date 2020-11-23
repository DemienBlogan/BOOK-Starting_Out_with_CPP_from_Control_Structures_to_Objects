/*
22. isPrime Function
A prime number is a number that is only evenly divisible by itself and 1. For example,
the number 5 is prime because it can only be evenly divided by 1 and 5. The number 6,
however, is not prime because it can be divided evenly by 1, 2, 3, and 6.

Write a function name isPrime, which takes an integer as an argument and returns
true if the argument is a prime number, or false otherwise. Demonstrate the function
in a completer program.

TIP: Recall that the % operator divides one number by another, and returns the remainder
of the division. In an expression such as num1 % num2, the % operator will return 0
if num1 is evenly divisible by num2.
*/

#include <iostream>

bool isPrime(int number);

int main()
{
	using namespace std;

	cout << "Enter a number: ";
	int number;
	cin >> number;

	if (isPrime(number))
		cout << "Your number is prime.\n";
	else
		cout << "Your number is not prime.\n";

	return 0;
}

bool isPrime(int number)
{
	for (int divider = 2; divider < number; divider++)
		if (number % divider == 0)
			return false;

	return true;
}