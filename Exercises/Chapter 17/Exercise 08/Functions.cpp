#include <iostream>
#include <algorithm>
#include "Functions.h"

int EnterPositiveNumber(int minLimit)
{
	int number;

	do
	{
		std::cout << "Enter a number greater than " << minLimit - 1 << ": ";
		std::cin >> number;

		if (number <= minLimit - 1)
			std::cout << "This number is less or equal to " << minLimit - 1 << ".\n";

	} while (number <= minLimit);

	return number;
}

void ShowPrimeNumbers(const std::vector<int>& numbers)
{
	std::cout << "All prime numbers in your diapasone: ";
	std::for_each(numbers.cbegin(), numbers.cend(), ShowPrimeNumber);
	std::cout << std::endl;
}

std::vector<int> GetAllNumbers(int min, int max)
{
	std::vector<int> numbers;

	for (int number = min; number <= max; number++)
		numbers.push_back(number);

	return numbers;
}

void ShowPrimeNumber(int number)
{
	if (IsPrime(number))
		std::cout << number << " ";
}

bool IsPrime(int number)
{
	if (number == 2)
		return true;

	if (number < 2)
		return false;

	for (int divider = 3; divider < number; divider++)
		if (number % divider == 0)
			return false;

	return true;
}