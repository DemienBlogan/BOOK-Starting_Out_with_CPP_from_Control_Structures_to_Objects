/*
21. The Speed of Sound in Gases
When sound travels through a gas, its speed depends primarily on the density of
the medium. The less dense the medium, the faster the speed will be. The following
table shows the approximate speed of sound at 0 degrees centigrade, measured
in meters per second, when traveling through carbon dioxide, air, helium,
and hydrogen.
-----------------------------------------------
Medium                Speed (Meters per Second)
Carbon dioxide        258.0
Air                   331.5
Helium                972.0
Hydrogen              1,270.0
-----------------------------------------------
Write a program that displays a menu allowing the user to select one of these four
gases. After a selection has been made, the user should enter the number of seconds it
took for the sound to travel in this medium from its source to the location at which it
was detected. The program should then report how far away (in meters) the source of
the sound was from the detection location.
Input Validation: Check that the user has selected one of the available menu choices.
Do not accept times less than 0 seconds or more than 30 seconds.
*/

#include <iostream>

int main()
{
	using namespace std;

	cout << "1 - Carbon dioxide \n";
	cout << "2 - Air            \n";
	cout << "3 - Helium         \n";
	cout << "4 - Hydrogen       \n";
	cout << "Select medium: ";
	char choice;
	cin >> choice;

	double speed;

	switch (choice)
	{
	case '1':
		speed = 258.0;   // Meters
		break;
	case '2':
		speed = 331.5;   // Meters
		break;
	case '3':
		speed = 972.0;   // Meters
		break;
	case '4':
		speed = 1'270.0; // Meters
		break;
	default:		
		cout << "Incorrect choice.\n";
		return 0;
	}

	cout << "Enter time (seconds) from 1 to than 30: ";
	double time;
	cin >> time;

	if (time < 1 || time > 30)
	{
		cout << "Incorrect time.\n";
		return 0;
	}

	double distance = time * speed;
	cout << "Distance = " << distance << endl;

	return 0;
}