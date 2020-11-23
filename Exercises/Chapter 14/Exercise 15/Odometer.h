#pragma once

#include "FuelGauge.h"

class Odometer
{
private:
	int mileage;
	int spendMiles;
	FuelGauge& gauge;

	static const int MILES_PER_GALLON = 24;

public:
	Odometer(FuelGauge& gauge);
	int GetMileage() const;
	bool IncreaseBy1Mile();
};