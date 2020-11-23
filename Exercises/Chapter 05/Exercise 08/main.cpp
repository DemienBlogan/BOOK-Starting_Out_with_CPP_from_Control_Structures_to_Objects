/*
8. Math Tutor
This program started in Programming Challenge 17, of Chapter 3, and was modified
in Programming Challenge 11 of Chapter 4. Modify the program again so it displays
a menu allowing the user to select an addition, subtraction, multiplication, or division
problem. The final selection on the menu should let the user quit the program. After
the user has finished the math problem, the program should display the menu again.
This process is repeated until the user chooses the quit the program.

Input Validation: If the user selects an item not on the menu, display an error message
and display the menu again.
*/

#include <iostream>
using namespace std;

int main()
{
	using namespace std;

	int menuItem;
	double number1, number2;
	double result;

	do
	{
		cout << "1 - Addition       \n";
		cout << "2 - Subtraction    \n";
		cout << "3 - Multiplication \n";
		cout << "4 - Division       \n";
		cout << "0 - Exit           \n";
		cout << "Select the item: ";
		cin >> menuItem;

		if (menuItem == 0)
			continue;

		switch (menuItem)
		{
		case 1:
			cout << "\nEnter two numbers: ";
			cin >> number1 >> number2;
			result = number1 + number2;
			cout << number1 << " + " << number2 << " = " << result << "\n\n";
			break;

		case 2:
			cout << "\nEnter two numbers: ";
			cin >> number1 >> number2;
			result = number1 - number2;
			cout << number1 << " - " << number2 << " = " << result << "\n\n";
			break;

		case 3:
			cout << "\nEnter two numbers: ";
			cin >> number1 >> number2;
			result = number1 * number2;
			cout << number1 << " * " << number2 << " = " << result << "\n\n";
			break;

		case 4:
			cout << "\nEnter two numbers: ";
			cin >> number1 >> number2;

			if (number2 == 0)
			{
				cout << "\nYou cannot divide by zero.\n\n";
				continue;
			}

			result = number1 / number2;
			cout << number1 << " / " << number2 << " = " << result << "\n\n";
			break;

		default:
			cout << "\nIncorrect item. Enter again.\n\n";
			break;
		}

	} while (menuItem != 0);

	return 0;
}