#pragma once

class Boiler
{
private:
	enum Table
	{
		ETHYL_ALCOHOL_FREEZING = -173,
		ETHYL_ALCOHOL_BOILING = 172,
		OXYGEN_FREEZING = -362,
		OXYGEN_BOILING = -306,
		WATER_FREEZING = 32,
		WATER_BOILING = 212
	};


	double temperature;

public:
	Boiler(double temperature)
		: temperature(temperature)
	{ }

	void SetTemperature(double temperature) { this->temperature = temperature; }

	double GetTemperature() const { return temperature; }

	bool IsEthylFreezing() const { return temperature <= ETHYL_ALCOHOL_FREEZING; }
	bool IsEthylBoiling() const { return temperature >= ETHYL_ALCOHOL_BOILING; }

	bool IsOxygenFreezing() const { return temperature <= OXYGEN_FREEZING; }
	bool IsOxygenBoiling() const { return temperature >= OXYGEN_BOILING; }

	bool IsWaterFreezing() const { return temperature <= WATER_FREEZING; }
	bool IsWaterBoiling() const { return temperature >= WATER_BOILING; }
};