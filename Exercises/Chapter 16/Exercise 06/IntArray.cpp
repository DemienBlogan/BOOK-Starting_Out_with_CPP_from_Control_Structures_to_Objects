#include <iostream>
#include <cstdlib>
#include "IntArray.h"

using namespace std;

IntArray::IntArray(int size)
{
	this->size = size;
	arr = new int[size] { 0 };
}

IntArray::IntArray(const IntArray& other)
{
	this->size = other.size;
	arr = new int[size];

	for (size_t i = 0; i < size; i++)
		arr[i] = other.arr[i];
}

IntArray::~IntArray()
{
	if (size > 0)
	{
		delete[] arr;
		arr = nullptr;
		size = 0;
	}
}

const IntArray IntArray::operator=(const IntArray& other)
{
	if (this != &other)
	{
		delete[] arr;
		size = other.size;
		arr = new int[size];

		for (size_t i = 0; i < size; i++)
			arr[i] = other.arr[i];
	}

	return *this;
}

int& IntArray::operator[](const int& index)
{
	if (index < 0 || index >= size)
		throw std::out_of_range("Index in operator[] is out of range");

	return arr[index];
}