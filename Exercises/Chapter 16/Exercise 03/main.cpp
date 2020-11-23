/*
3. Minimum/Maximum Templates
Write templates for the two functions minimum and maximum. The minimum function
should accept two arguments and return the value of the argument that is the lesser
of the two. The maximum function should accept two arguments and return the value
of the argument that is the greater of the two. Design a simple driver program that
demonstrates the templates with various data types.
*/

#include <iostream>

using std::cout;
using std::endl;

template <typename T>
T minimum(const T& first, const T& second);

template <typename T>
T maximum(const T& first, const T& second);

int main()
{
	int intValue1 = 5, intValue2 = 10;
	int intMax = minimum(intValue1, intValue2);

	cout << "Type: int\n";
	cout << "Value1 = " << intValue1 << endl;
	cout << "Value2 = " << intValue2 << endl;
	cout << "Min    = " << intMax << endl;

	double doubleValue1 = 2.35, doubleValue2 = 6.43;
	double doubleMax = maximum(doubleValue1, doubleValue2);

	cout << "Type: double\n";
	cout << "Value1 = " << doubleValue1 << endl;
	cout << "Value2 = " << doubleValue2 << endl;
	cout << "Max    = " << doubleMax << endl;

	return 0;
}

template <typename T>
T minimum(const T& first, const T& second)
{
	return first < second ? first : second;
}

template <typename T>
T maximum(const T& first, const T& second)
{
	return first > second ? first : second;
}