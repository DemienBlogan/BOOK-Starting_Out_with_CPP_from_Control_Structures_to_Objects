/*
1. Array Allocator
Write a function that dynamically allocates an array of integers. The function should
accept an integer argument indicating the number of elements to allocate. The function
should return a pointer to the array.
*/

int* CreateIntArray(size_t size)
{
	return size != 0 ? new int[size] : nullptr;	
}