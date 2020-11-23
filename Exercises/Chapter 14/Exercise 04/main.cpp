/*
4. NumDays Class
Design a class called NumDays. The class's purpose is to store a value that represents a
number of work hours and convert it to a number of days. For example, 8 hours would
be converted to 1 day, 12 hours would be converted to 1.5 days, and 18 hours would
be converted to 2.25 days. The class should have a constructor that accepts a number
of hours, as well as member functions for storing and retrieving the hours and days.
The class should also have the following overloaded operators:

+ Addition operator. When two NumDays objects are together, the overloaded + operator
  should return the sum of the two objects' hours members.

- Subtraction operator. When one NumDays object is subtracted from another, the
  overloaded - operator should return the difference of the two objects' hours members.

++ Prefix and postfix increment operators. These operators should increment the number
   of hours stored in the object. When incremented, the number of days
   should be automatically recalculated.

-- Prefix and postfix decrement operators. These operators should decrement the number
   of hours stored in the object. When decremented, the number of days
   should be automatically recalculated.
*/

#include <iostream>
#include "NumDays.h"

using std::cout;
using std::endl;

int main()
{
	NumDays num1{ 8 }, num2{ 12 }, num3{ 18 };
	NumDays num4{ num1 + num2 };
	NumDays num5{ num3 - num2 };

	cout << "Worker #1: " << num1.GetDays() << endl;
	cout << "Worker #2: " << num2.GetDays() << endl;
	cout << "Worker #3: " << num3.GetDays() << endl;
	cout << "Worker #4: " << num4.GetDays() << endl;
	cout << "Worker #5: " << num5.GetDays() << endl;

	cout << "-----------------\n";

	NumDays incrTest1 = num1++;
	NumDays incrTest2 = ++num2;

	NumDays decrTest1 = num3--;
	NumDays decrTest2 = --num4;

	cout << "Worker #1: " << num1.GetDays() << endl;
	cout << "Worker #2: " << num2.GetDays() << endl;
	cout << "Worker #3: " << num3.GetDays() << endl;
	cout << "Worker #4: " << num4.GetDays() << endl;

	cout << "Increment test #1: " << incrTest1.GetDays() << endl;
	cout << "Increment test #2: " << incrTest2.GetDays() << endl;
	cout << "Decrement test #1: " << decrTest1.GetDays() << endl;
	cout << "Decrement test #2: " << decrTest2.GetDays() << endl;

	return 0;
}