#pragma once

#include "MilTime.h"

class TimeClock : public MilTime
{
public:
	TimeClock(int startingTime, int endingTime);
	int GetElapsedTime() const;
};