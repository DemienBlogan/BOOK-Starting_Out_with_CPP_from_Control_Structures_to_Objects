/*
2. Roman Numeral Converter
Write a program that asks the user to enter a number within the range of 1 through 10.
Use a switch statement to display the Roman numeral version of that number.

Input Validation: Do not accept a number less than 1 or greater than 10.
*/

#include <iostream>

int main()
{
	using namespace std;

	cout << "Enter a number within the range of 1 through 10: ";
	int number;
	cin >> number;

	if (number < 1 || number > 10)
	{
		cout << "Do not accept a number less than 1 or greater than 10.\n";
		return 0;
	}

	switch (number)
	{
	case 1:
		cout << "Roman Numeral: I \n";
		break;
	case 2:
		cout << "Roman Numeral: II \n";
		break;
	case 3:
		cout << "Roman Numeral: III \n";
		break;
	case 4:
		cout << "Roman Numeral: IV \n";
		break;
	case 5:
		cout << "Roman Numeral: V \n";
		break;
	case 6:
		cout << "Roman Numeral: VI \n";
		break;
	case 7:
		cout << "Roman Numeral: VII \n";
		break;
	case 8:
		cout << "Roman Numeral: VIII \n";
		break;
	case 9:
		cout << "Roman Numeral: IX \n";
		break;
	case 10:
		cout << "Roman Numeral: X \n";
		break;
	}

	return 0;
}