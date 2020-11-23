/*
8. Color Mixer
The colors red, blue, and yellow are known as primary colors because they cannot be
made by mixing other colors. When you mix two primary colors, you get a seconday
color, as shown here:

When you mix red and blue, you get purple
When you mix red and yellow, you get orange
When you mix blue and yellow, you get green

Write a program that prompts the user to enter the names of two primary color to
mix. If the use enters anything other than "red", "blue", or "yellow", the program
should display an error message. Otherwise, the program should display the name of
the secondary color that results by mixing two primary colors.
*/

#include <iostream>
#include <string>

int main()
{
	using namespace std;

	cout << "Enter two primary colors: ";
	string color1, color2;
	cin >> color1 >> color2;

	if ((color1 != "red" && color1 != "blue" && color1 != "yellow") ||
		(color2 != "red" && color2 != "blue" && color2 != "yellow"))
	{
		cout << "Error. One or two colors are not primary.\n";
	}
	else if ((color1 == "red" && color2 == "blue") ||
		     (color1 == "blue" && color2 == "red"))
	{
		cout << "Secondry color is purple.\n";
	}
	else if ((color1 == "red" && color2 == "yellow") ||
		     (color1 == "yellow" && color2 == "red"))
	{
		cout << "Secondry color is orange.\n";
	}
	else if ((color1 == "blue" && color2 == "yellow") ||
		     (color1 == "yellow" && color2 == "blue"))
	{
		cout << "Secondry color is green.\n";
	}

	return 0;
}