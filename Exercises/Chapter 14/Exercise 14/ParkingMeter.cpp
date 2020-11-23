#include "ParkingMeter.h"

ParkingMeter::ParkingMeter(int minutesPurchased)
	: minutesPurchased(minutesPurchased)
{ }

void ParkingMeter::SetMinutesPurchased(int minutesPurchased)
{
	this->minutesPurchased = minutesPurchased;
}

int ParkingMeter::GetMinutesPurchased() const
{
	return minutesPurchased;
}
