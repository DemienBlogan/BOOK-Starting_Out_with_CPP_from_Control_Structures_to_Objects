/*
9. Median Function
In statistics, when a set of values is sorted in ascending or descending order, its median
is the middle value. If the set contains an even number of values, the median is the
mean, or average, of the two middle values. Write a function that accepts as arguments
the following:

A) An array of integers
B) An integer that indicates the number of elements in the array

The function should determine the median of the array. This value should be returned
as a double. (Assume the values in the array are already sorted).

Demonstrate your pointer prowess by using pointer notation instead of array notation
in this function.
*/

double FindMedian(const double arr[], size_t size)
{
	if (size % 2 != 0)
		return arr[size / 2];

	double middle1 = arr[size / 2 - 1], middle2 = arr[size / 2];
	double median = (middle1 + middle2) / 2;
	return median;
}