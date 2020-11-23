/*
4. Absolute Value Template
Write a function template that accepts an argument and returns its absolute value.
The absolute value of a numbe ris its value with no sign. For example, the absolute of
-5 is 5, and the absolute value of 2 is 2. Test the template in a simple driver program.
*/

#include <iostream>

using std::cout;
using std::endl;

template <typename T>
T AbsoluteValue(const T& value);

int main()
{
	int intValue1 = -4, intValue2 = 5;
	double doubleValue1 = 2.56, doubleValue2 = -23.9;

	int absoluteIntValue1 = AbsoluteValue(intValue1);
	int absoluteIntValue2 = AbsoluteValue(intValue2);
	double absoluteDoubleValue1 = AbsoluteValue(doubleValue1);
	double absoluteDoubleValue2 = AbsoluteValue(doubleValue2);

	cout << "Type: int\n";
	cout << "Value = " << intValue1 << ", absolute value = " << absoluteIntValue1 << endl;
	cout << "Value = " << intValue2 << ", absolute value = " << absoluteIntValue2 << "\n\n";
	
	cout << "Type: double\n";
	cout << "Value = " << doubleValue1 << ", absolute value = " << absoluteDoubleValue1 << endl;
	cout << "Value = " << doubleValue2 << ", absolute value = " << absoluteDoubleValue2 << "\n\n";

	return 0;
}

template <typename T>
T AbsoluteValue(const T& value)
{
	return value < 0 ? -value : value;
}