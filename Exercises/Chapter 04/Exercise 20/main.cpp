/*
20. The Speed of Sound
The following table shows the approximate speed of sound in air, water, and steel.
-------------------------------------
Medium         Speed
-------------------------------------
Air            1,100 feet per second
Water          4,900 feet per second
Steel          16,400 feet per second
-------------------------------------
Write a program that displays a menu allowing the user to select air, water, or steel.
After the user has made a selection, he or she should be asked to enter the distance a
sound wave will travel in the selected medium. The program will then display the
amount of time it will take. (Round the answer to four decimal places).
Input Validation: Check that the user has selected one of the available choices from the
menu. Do not accept distances less than 0.
*/

#include <iostream>
#include <iomanip>

int main()
{
	using namespace std;

	cout << "1 - Air   \n";
	cout << "2 - Water \n";
	cout << "3 - Steel \n";
	cout << "Select environment: ";
	char choice;
	cin >> choice;

	double speed;

	switch (choice)
	{
	case '1':
		speed = 1'100;  // Feet
		break;
	case '2':
		speed = 4'900;  // Feet
		break;
	case '3':
		speed = 16'400; // Feet
		break;
	default:
		cout << "Incorrect choice.\n";
		return 0;
	}

	cout << "Enter distance: ";
	double distance;
	cin >> distance;

	if (distance <= 0)
	{
		cout << "Incorrect distance.\n";
		return 0;
	}

	double time = distance / speed;
	cout << fixed << setprecision(4) << "Time: " << time << endl;

	return 0;
}