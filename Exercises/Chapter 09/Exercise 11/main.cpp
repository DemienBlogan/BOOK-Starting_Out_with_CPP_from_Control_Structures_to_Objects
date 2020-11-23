/*
11. Array Expander
Write a function that accepts an int array and the array's size as arguments. The
function should create a new array that is twice the size of the argument array. The
function should copy the contents of the argument array to the new array and initialize
the unused elements of the second array with 0. The function should return a pointer
to the new array.
*/

int* CreateDoubleSizedArray(const int arr[], size_t size)
{
	size_t newSize = size * 2;

	int* newArr = new int[newSize] {};

	for (size_t i = 0; i < size; i++)
		newArr[i] = arr[i];

	return newArr;
}