#include <exception>
#include "TestScores.h"

TestScores::TestScores(const double arr[], size_t size)
    : average(0)
{
	double sum = 0;

	for (size_t i = 0; i < size; i++)
	{
		if (arr[i] < 0)
			throw std::exception("The array of scores has negative value");

		sum += arr[i];
	}

	average = sum / size;
}

double TestScores::GetAverage() const
{
    return average;
}