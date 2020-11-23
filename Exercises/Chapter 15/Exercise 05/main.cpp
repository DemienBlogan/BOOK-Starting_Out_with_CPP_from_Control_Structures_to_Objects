/*
5. Time Clock
Design a class named TimeClock. The class should be derived from the MilTime class
you designed in Programming Challenge 4 (Time Format). The class should allow the
programmer to pass two times to it: starting time and ending time. The class should
have a member function that returns the amount of time elapsed between the two
times. For example, if the starting time is 900 hours (9:00 a.m.), and the ending time
is 1300 hours (1:00 p.m.), the elapsed time is 4 hours.

Input Validation: The class should not accept hours greater than 2359 or less than 0.
*/

#include <iostream>

#include "TimeClock.h"

using std::cout;
using std::endl;

int main()
{
    TimeClock clock{ 900, 1300 };

    cout << "Elapsed hours = " << clock.GetElapsedTime() << endl;

    return 0;
}