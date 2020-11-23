#pragma once

class NumDays
{
private:
	int workedHours;

public:
	NumDays(int workedHours);

	double GetDays() const;

	NumDays operator+(const NumDays& other) const;
	NumDays operator-(const NumDays& other) const;
	NumDays& operator++();
	NumDays operator++(int);
	NumDays& operator--();
	NumDays operator--(int);
};