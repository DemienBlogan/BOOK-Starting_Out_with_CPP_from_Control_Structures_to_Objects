/*
23. Prime Number List
Use the isPrime function that you wrote in Programming Challenge 22 (isPrime function)
in a program that stores a list of all the prime numbers from 1 through 100 in a file.
*/

#include <iostream>
#include <fstream>
bool isPrime(int number);

int main()
{
	using namespace std;

	ofstream fout("PrimeNumbers.txt");

	if (!fout)
	{
		cout << "Error. Cannot open or create the file.\n";
		return 0;
	}

	fout << "Prime numbers:\n";

	for (int number = 1; number <= 100; number++)
		if (isPrime(number))
			fout << number << endl;

	fout.close();

	return 0;
}

bool isPrime(int number)
{
	for (int divider = 2; divider < number; divider++)
		if (number % divider == 0)
			return false;

	return true;
}