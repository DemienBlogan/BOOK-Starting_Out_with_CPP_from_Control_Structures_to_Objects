#pragma once
#include "Time.h"

class BadHour
{
public:
	void ShowErrorMessage() const;
};

class BadSeconds
{
public:
	void ShowErrorMessage() const;
};

class MilTime : public Time
{
private:
	int milHours;
	int milSeconds;

public:
	MilTime(int milHours = 0, int milSeconds = 0);
	void setTime(int milHours, int milSeconds);
	int getHour() const;
	int getStandHr() const;
};