/*
8. Date Class Modification
Modify the Date class in Programming Challenge 1 of Chapter 13. The new version
should have the following overloaded operators:

++ Prefix and postfix increment operators. These operators should increment the
   object's day member.
++ Prefix and postfix decrement operators. These operators should decrement the
   object's day member.
-  Subtraction operator. If one Date object is subtracted from another, the operator
   should give the numbe rof days between the dates. For example, if April 10,
   2014 is subtracted from April 18, 2014, the result will be 8.
<< cout's stream insertion operator. This operator should cause the date to be displayed
   in the form
   April 18, 2018

>> cin's stream extraction operator. This operator should prompt the user for a date
   to be stored in a Date object.

The class should detect the following conditions and handle them accordingly:
- When a date is set to the last day of the month and incremented, it should become
  the first day of the following month.
- When a date is set to December 31 and incremented, it should become January 1 of
  the following year.
- When a day is set to the first day of the month and decremented, it should become
  the last day of the previous month.
- When a date is set to January 1 and decremented, it should become December 31 of
  the previous year.

Demonstrate the class's capabilities in a simple program.

Input Validation: The overloaded >> operator should not accept invalid dates. For
example, the date 13/45/2018 should not be accepted.
*/

#include <iostream>
#include "Date.h"

using std::cout;
using std::cin;
using std::endl;

int main()
{
	Date date1;

	cout << "Enter month, day and year: ";
	cin >> date1;

	cout << date1 << endl;
	date1++;
	cout << date1 << endl;
	++date1;
	cout << date1 << endl;

	Date date2;
	cout << "Enter month, day and year: ";
	cin >> date2;

	cout << date2 << endl;
	date2--;
	cout << date2 << endl;
	--date2;
	cout << date2 << endl;

	int daysBetween = date2 - date1;

	cout << "Days between: " << daysBetween << endl;

	return 0;
}