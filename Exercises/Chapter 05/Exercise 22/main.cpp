/*
22. Square Display
Write a program that asks the user for a positive integer no greater than 15. The program
should then display a square on the screen using the character 'X'. The number
entered by user will be the length of each side of the square.
*/

#include <iostream>

int main()
{
	using namespace std;

	cout << "Enter a positive integer no greater than 15: ";
	int number;
	cin >> number;

	if (number > 15)
	{
		cout << "Incorrect number.\n";
		return 0;
	}

	for (int i = 0; i < number; i++)
	{
		for (int j = 0; j < number; j++)
			cout << 'X';
		cout << endl;
	}

	return 0;
}