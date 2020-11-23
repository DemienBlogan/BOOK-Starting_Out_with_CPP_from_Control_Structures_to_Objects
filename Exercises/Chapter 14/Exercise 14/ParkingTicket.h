#pragma once

#include "ParkedCar.h"
#include "PoliceOfficer.h"

class ParkingTicket
{
private:
	ParkedCar car;
	PoliceOfficer officer;

public:
	ParkingTicket(const ParkedCar& car, const PoliceOfficer& officer);
	void ReportCar() const;
	void ReportFine() const;
	void ReportOfficerInfo() const;
};