#include "PoliceOfficer.h"

void PoliceOfficer::ExamineTime()
{
	int minutesParked = car.GetMinutesParked();
	int minutesPurchased = meter.GetMinutesPurchased();

	if (minutesParked <= minutesPurchased)
	{
		timeIsExpired = false;
		fine = 0.0;
	}
	else
	{
		timeIsExpired = true;

		int minutes = minutesParked - minutesPurchased;
		int hours = minutes / 60;

		fine = 25;

		hours--;

		while (hours != 0)
		{
			fine += 10;
			hours--;
		}
	}
}

PoliceOfficer::PoliceOfficer(const string& name, const string& badge, const ParkedCar& car, const ParkingMeter& meter)
	: name(name), badge(badge), car(car), meter(meter)
{
	ExamineTime();
}

void PoliceOfficer::SetName(const string& name)
{
	this->name = name;
}

void PoliceOfficer::SetBadge(const string& badge)
{
	this->badge = badge;
}

void PoliceOfficer::ChangeCar(const ParkedCar& car)
{
	this->car = car;
	ExamineTime();
}

void PoliceOfficer::ChangeMeter(const ParkingMeter& meter)
{
	this->meter = meter;
	ExamineTime();
}

bool PoliceOfficer::IsTimeExpired() const
{
	return timeIsExpired;
}

string PoliceOfficer::GetName() const
{
	return name;
}

string PoliceOfficer::GetBadge() const
{
	return badge;
}

double PoliceOfficer::GetFine() const
{
	return fine;
}
