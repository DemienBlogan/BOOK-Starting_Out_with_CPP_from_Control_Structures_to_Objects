/*
12. Ship, CruiseShip, and CargoShip Classes
Design a Ship class that has the following members:

- A member variable for the name of the ship (a string)
- A member variable for the year that the ship was built (a string)
- A constructor and appropriate accessors and mutators
- A virtual print function that displays the ship's name and the year it was built

Design CruiseShip class that is derived from the Ship class. The CruiseShip class
should have the following members:

- A member variable for the maximum number of passengers (an int)
- A constructor and appropriate accessors and mutators
- A print function that overrides the print function in the base class. The CruiseShip
  class's print function should display only the ship's name and the maximum number
  of passengers.

Design a CargoShip class that is derived from the Ship clsas. The CargoShip class
should have the following members:

- A member variable for the cargo capacity in tonnage (an in)
- A constructor and appropriate accessors and mutators
- A print function that overrides the print function in the base class. The CargoShip
  class's print function should display only the ship's name and the ship's cargo capacity.

Demonstrate the classes in a program that has an array of Ship pointers. The array elements
should be initialized with the addresses of dynamically allocated Ship, CruiseShip,
and CargoShip objects. (See Program 15-14, lines 17 through 22, for an example of how
to do this). The program should then step through the array, calling each object's print
function.
*/

#include <iostream>
#include "Ship.h"

using std::cout;

int main()
{
	const size_t SIZE = 3;
	Ship* ships[SIZE] =
	{
		new Ship("Valkiriya", "23/12/1993"),
		new CruiseShip("Velko", "5/3/2005", 830),
		new CargoShip("Gurilla", "1/1/2020", 7323)
	};

	for (size_t i = 0; i < SIZE; i++)
	{
		cout << "Ship #" << i + 1 << ":\n";
		ships[i]->print();
	}

	for (size_t i = 0; i < SIZE; i++)
		delete ships[i];

	return 0;
}