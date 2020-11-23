/*
10. Number Array Class
Design a class that has an array of floating-point numbers. The constructor should
accept an integer argument and dynamically allocate the array to hold that many
numbers. The destructor should free the memory held by the array. In addition, there
should be member functions to perform the following operations:
- Store a number in any element of the array
- Retrieve a number from any element of the array
- Return the highest value stored in the array
- Return the lowest value stored in the array
- Return the average of all the numbers stored in the array
Demonstrate the class in a program.
*/

#include <iostream>
#include <ctime>

#include "NumberArray.h"

using std::cout;
using std::endl;

int main()
{
	srand(static_cast<unsigned>(time(nullptr)));

	size_t size = 5;

	NumberArray arr{ 5 };

	for (size_t i = 0; i < size; i++)
		cout << arr.GetElement(i) << " ";
	cout << endl;

	for (size_t i = 0; i < size; i++)
		arr.SetElement(i, rand() % 20 + 10);

	for (size_t i = 0; i < size; i++)
		cout << arr.GetElement(i) << " ";
	cout << endl;

	float max = arr.GetMax();
	float min = arr.GetMin();
	float average = arr.GetAverage();

	cout << "Max = " << max << endl;
	cout << "Min = " << min << endl;
	cout << "Average = " << average << endl;

	return 0;
}