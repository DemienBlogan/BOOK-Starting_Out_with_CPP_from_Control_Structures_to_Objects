#include <iostream>

#include "ParkingTicket.h"

using std::cout;
using std::endl;

ParkingTicket::ParkingTicket(const ParkedCar& car, const PoliceOfficer& officer)
	: car{ car }, officer{ officer }
{ }

void ParkingTicket::ReportCar() const
{
	cout << "--- Car Information ---\n";
	cout << "Make: " << car.GetMake() << endl;
	cout << "Model: " << car.GetModel() << endl;
	cout << "Color: " << car.GetColor() << endl;
	cout << "License number: " << car.GetLicenseNumber() << endl;
	cout << "Minutes parked: " << car.GetMinutesParked() << endl;
}

void ParkingTicket::ReportFine() const
{
	cout << "--- Fine Information ---\n";
	cout << "Fine: $" << officer.GetFine() << endl;
}

void ParkingTicket::ReportOfficerInfo() const
{
	cout << "--- Officer Information ---\n";
	cout << "Name: " << officer.GetName() << endl;
	cout << "Badge: " << officer.GetBadge() << endl;
}