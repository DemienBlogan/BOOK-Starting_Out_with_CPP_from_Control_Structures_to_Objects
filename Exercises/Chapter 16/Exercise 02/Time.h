#pragma once

class Time
{
protected:
	int hour;
	int min;
	int sec;

public:
	Time(int h = 0, int m = 0, int s = 0)
		: hour(h), min(m), sec(s)
	{ }

	int getHours() const
	{
		return hour;
	}

	int getMin() const
	{
		return min;
	}

	int getSec() const
	{
		return sec;
	}
};