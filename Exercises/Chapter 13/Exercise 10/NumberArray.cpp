#include <cstdlib>

#include "NumberArray.h"

NumberArray::NumberArray(size_t size)
	: arr(new float[size]), size(size)
{
	for (size_t i = 0; i < size; i++)
		arr[i] = rand() % 10;
}

NumberArray::~NumberArray()
{
	delete[] arr;
	arr = nullptr;
}

float NumberArray::GetMax() const
{
	float max = arr[0];

	for (size_t i = 1; i < size; i++)
		if (max < arr[i])
			max = arr[i];

	return max;
}

float NumberArray::GetMin() const
{
	float min = arr[0];

	for (size_t i = 1; i < size; i++)
		if (min > arr[i])
			min = arr[i];

	return min;
}

float NumberArray::GetAverage() const
{
	float sum = 0.0f;

	for (size_t i = 0; i < size; i++)
		sum += arr[i];

	float average = sum / size;
	return average;
}