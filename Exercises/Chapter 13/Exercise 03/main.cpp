/*
3. Car Class
Write a class named Car that has the following member variables:
- yearModel - an int that holds the car's year model
- make - a string that holds the make of the car
- speed - an int that holds the car's current speed

In addition, the class should have the following constructor and other member functions:
- Constructor - The constructor should accept the car's year model and make as arguments.
  These values should be assigned to the object's yearModel and make member
  variables. The constructor should also assign 0 to the speed member variables.
- Accessor - appropriate accessor functions to get the values stored in an object's
  yearModel, make, and speed member variables
- accelerate - The accelerate function should add 5 to the speed member variable
  each time it is called.
- brake - The brake function should subtract 5 from the speed member variable
  each time it is called.

Demonstrate the class in a program that creates a Car object, then calls the accelerate
function five times. After each call to the accelerate function, get the current speed
of the car and display it. Then, call the brake function five times. After each call to the
brake function, get the current speed of the car and display it.
*/

#include <iostream>

#include "Car.h"

using std::cout;
using std::endl;

int main()
{
	Car car(2020, "Renault Megane");
	size_t times = 5;

	for (size_t i = 0; i < times; i++)
	{
		car.Accelerate();		
		cout << "Car " << car.GetMake() << " (" << car.GetYearModel() << "), speed = ";
		cout << car.GetSpeed() << endl;
	}	
	
	for (size_t i = 0; i < times; i++)
	{
		car.Brake();
		cout << "Car " << car.GetMake() << " (" << car.GetYearModel() << "), speed = ";
		cout << car.GetSpeed() << endl;
	}

	return 0;
}