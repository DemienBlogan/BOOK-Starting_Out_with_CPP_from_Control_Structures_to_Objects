#include "TimeClock.h"

TimeClock::TimeClock(int startingTime, int endingTime)
	: MilTime()
{
    if (startingTime >= 0 && startingTime <= 2359 &&
        endingTime >= 0 && endingTime <= 2359)
    {
        this->milHours = endingTime - startingTime;

        hour = milHours / 100;
        min = milHours % 100;
    }
}

int TimeClock::GetElapsedTime() const
{
    return hour;
}
