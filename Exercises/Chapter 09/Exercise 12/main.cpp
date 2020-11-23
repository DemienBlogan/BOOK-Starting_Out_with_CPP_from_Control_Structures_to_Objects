/*
12. Element Shifter
Write a function that accepts an int array and the array's size as arguments. The
function should create a new array that is one element larger that the argument array.
The first element of the new array should be set to 0. Element 0 of the argument array
should be copied to element 1 of the new array, element 1 of the argument array should
be copied to element 2 of the new array, and so forth. The function should return a
pointer to the new array.
*/

int* CreateShiftedArray(const int arr[], size_t size)
{
	int* shiftedArr = new int[size + 1]{};

	for (size_t i = size; i > 0; i--)
		shiftedArr[i] = arr[i - 1];

	return shiftedArr;
}

int main() 
{
	int arr[3] = { 1, 2, 4 };
	CreateShiftedArray(arr, 3);
}