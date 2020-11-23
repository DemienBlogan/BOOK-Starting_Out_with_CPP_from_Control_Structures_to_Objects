#pragma once

#include "Time.h"

class MilTime : public Time
{
private:
	Time time;
	int milHours;
	int milSeconds;

public:
	MilTime(int milHours = 0, int milSeconds = 0);
	void setTime(int milHours, int milSeconds);
	int getHour() const;
	int getStandHr() const;
};