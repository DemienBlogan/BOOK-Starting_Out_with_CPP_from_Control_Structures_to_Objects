#pragma once

class ParkingMeter
{
private:
	int minutesPurchased;

public:
	ParkingMeter(int minutesPurchased = 0);

	void SetMinutesPurchased(int minutesPurchased);
	int GetMinutesPurchased() const;
};