// Implementation file fro the Rectangle class.
// This version has a constructor.
#include "example 13-7-Rectangle.h" // Needed for the Rectangle class
#include <iostream>                 // Needed for cout
#include <cstdlib>	                // Needed for the exit function
using namespace std;

//******************************************************
// The constructor initializes width and length to 0.0 *
//******************************************************

Rectangle::Rectangle()
{
	width = 0.0;
	length = 0.0;
}

//************************************************
// setWidth assigns a value to the width member. *
//************************************************

void Rectangle::setWidth(double w)
{
	if (w >= 0)
		width = w;
	else
	{
		cout << "Invalid width\n";
		exit(EXIT_FAILURE);
	}
}

//**************************************************
// setLength assigns a value to the length member. *
//**************************************************

void Rectangle::setLength(double len)
{
	if (len >= 0)
		length = len;
	else
	{
		cout << "Invalid length\n";
		exit(EXIT_FAILURE);
	}
}