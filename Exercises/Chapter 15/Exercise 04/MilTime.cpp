#include "MilTime.h"

MilTime::MilTime(int milHours, int milSeconds)
    : milHours(0), milSeconds(0), time()
{
    setTime(milHours, milSeconds);
}

void MilTime::setTime(int milHours, int milSeconds)
{
    if (milHours >= 0 && milHours <= 2359)
    {
        this->milHours = milHours;

        hour = milHours / 100;
        min = milHours % 100;
    }

    if (milSeconds >= 0 && milSeconds <= 59)
    {
        this->milSeconds = milSeconds;
        sec = milSeconds;
    }

}

int MilTime::getHour() const
{
    return milHours;
}

int MilTime::getStandHr() const
{
    return hour;
}