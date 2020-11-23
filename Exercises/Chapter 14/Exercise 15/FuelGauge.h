#pragma once

class FuelGauge
{
private:
	double fuelGallons;
	
public:
	FuelGauge();
	double GetFuelGallons() const;
	bool FillUp1Gallon();
	bool Burn1Gallon();
};