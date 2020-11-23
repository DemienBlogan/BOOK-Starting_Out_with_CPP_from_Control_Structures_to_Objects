#include <iostream>
#include "Ship.h"

using std::cout;
using std::endl;

Ship::Ship(const string& name, const string& builtYear)
	: name(name), builtYear(builtYear)
{ }

void Ship::SetName(const string& name)
{
	this->name = name;
}

void Ship::SetBuiltYear(const string& builtYear)
{
	this->builtYear = builtYear;
}

string Ship::GetName() const
{
	return name;
}

string Ship::GetBuiltYear() const
{
	return builtYear;
}

void Ship::print() const
{
	cout << "\tName: " << name << endl;
	cout << "\tBuilt year: " << builtYear << endl;
}

CruiseShip::CruiseShip(const string& name, const string& builtYear, int maxPassengers)
	: Ship(name, builtYear), maxPassengers(maxPassengers)
{ }

void CruiseShip::SetMaxPassengers(int maxPassengers)
{
	this->maxPassengers = maxPassengers;
}

int CruiseShip::GetMaxPassengers() const
{
	return maxPassengers;
}

void CruiseShip::print() const
{
	Ship::print();
	cout << "\tMaximum amount of passengers: " << maxPassengers << endl;
}

CargoShip::CargoShip(const string& name, const string& builtYear, int cargoCapacity)
	: Ship(name, builtYear), cargoCapacity(cargoCapacity)
{ }

void CargoShip::SetCargoCapacity(int cargoCapacity)
{
	this->cargoCapacity = cargoCapacity;
}

int CargoShip::GetCargoCapacity() const
{
	return cargoCapacity;
}

void CargoShip::print() const
{
	Ship::print();
	cout << "\tCargo Capacity: " << cargoCapacity << endl;
}