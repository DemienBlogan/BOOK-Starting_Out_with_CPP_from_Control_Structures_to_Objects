#pragma once

class TestScores
{
private:
	double average;

public:
	TestScores(const double arr[], size_t size);
	double GetAverage() const;
};