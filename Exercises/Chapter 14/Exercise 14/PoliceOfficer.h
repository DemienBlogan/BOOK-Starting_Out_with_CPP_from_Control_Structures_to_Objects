#pragma once

#include <string>
#include "ParkedCar.h"
#include "ParkingMeter.h"

using std::string;

class PoliceOfficer
{
private:
	string name;
	string badge;
	ParkedCar car;
	ParkingMeter meter;
	bool timeIsExpired;
	double fine;

	void ExamineTime();

public:
	PoliceOfficer(
		const string& name,
		const string& badge,
		const ParkedCar& car,
		const ParkingMeter& meter);

	void SetName(const string& name);
	void SetBadge(const string& badge);
	void ChangeCar(const ParkedCar& car);
	void ChangeMeter(const ParkingMeter& meter);
	bool IsTimeExpired() const;
	string GetName() const;
	string GetBadge() const;
	double GetFine() const;
};