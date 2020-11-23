/*
2. Recursive Conversion
Convert the following function to one that uses recursion.

void sign(int n)
{
	while (n > 0)
	{
		cout << "No Parking\n";
		n--;
	}
}
*/

#include <iostream>

void sign(int n)
{
	if (n <= 0)
		return;

	std::cout << "No Parking\n";

	sign(n - 1);
}

int main()
{
	sign(3);
	return 0;
}