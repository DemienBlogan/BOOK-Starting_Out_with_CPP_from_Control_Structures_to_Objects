#include "FuelGauge.h"

FuelGauge::FuelGauge()
	: fuelGallons(0)
{ }

double FuelGauge::GetFuelGallons() const
{
    return fuelGallons;
}

bool FuelGauge::FillUp1Gallon()
{
	if (fuelGallons < 15)
	{
		fuelGallons++;
		return true;
	}

	return false;
}

bool FuelGauge::Burn1Gallon()
{
	if (fuelGallons > 0)
	{
		fuelGallons--;
		return true;
	}

	return false;
}