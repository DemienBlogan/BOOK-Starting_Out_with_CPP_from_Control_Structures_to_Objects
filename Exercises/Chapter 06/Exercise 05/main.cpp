/*
5. Falling Distance
When an object is falling because of gravity, the following formula can be used to
determine the distance the object falls in a specific time period:

d = (1 / 2) * g * t^2

The variables in the formula are as follows: d is the distance in meters, g is 9.8, and t
is the amount of time, in seconds, that the object has been falling.

Write a function named fallingDistance that accepts an object's falling time (in
seconds) as an argument. The function should return the distance, in meters, that the
object has fallen during that time interval. Write a program that demonstrates the
function by calling it in a loop that passes the values 1 through 10 as arguments and
displays the return value.
*/

#include <iostream>

double fallingDistance(double seconds);

int main()
{
	using namespace std;

	for (int seconds = 0; seconds <= 10; seconds++)
	{
		double meters = fallingDistance(seconds);
		cout << "After " << seconds << " object will pass " << meters << " meters.\n";
	}

	return 0;
}

double fallingDistance(double seconds)
{
	constexpr double g = 9.8;
	double meters = 0.5 * g * seconds * seconds;
	return meters;
}