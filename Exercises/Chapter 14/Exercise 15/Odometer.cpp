#include "Odometer.h"

Odometer::Odometer(FuelGauge& gauge)
    : mileage(0), gauge(gauge), spendMiles(0)
{ }

int Odometer::GetMileage() const
{
    return mileage;
}

bool Odometer::IncreaseBy1Mile()
{
	if (gauge.GetFuelGallons() == 0)
		return false;

	spendMiles++;

	if (spendMiles >= MILES_PER_GALLON)
	{
		gauge.Burn1Gallon();
		spendMiles = 0;
	}

	if (mileage < 999'999)
	{
		mileage++;
	}
	else
		mileage = 0;

	return true;
}