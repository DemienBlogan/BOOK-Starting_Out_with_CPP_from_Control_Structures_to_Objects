#include "ParkedCar.h"

ParkedCar::ParkedCar(
	const string& make,
	const string& model, 
	const string& color, 
	const string& licenseNumber,
	int minutesParked)
	: make(make),
	model(model),
	color(color),
	licenseNumber(licenseNumber),
	minutesParked(minutesParked)
{ }

void ParkedCar::SetMake(const string & make)
{
	this->make = make;
}

void ParkedCar::SetModel(const string& model)
{
	this->model = model;
}

void ParkedCar::SetColor(const string& color)
{
	this->color = color;
}

void ParkedCar::SetLicenseNumber(const string& licenseNumber)
{
	this->licenseNumber = licenseNumber;
}

void ParkedCar::SetMinutesParked(int minutesParked)
{
	this->minutesParked = minutesParked;
}

string ParkedCar::GetMake() const
{
	return make;
}

string ParkedCar::GetModel() const
{
	return model;
}

string ParkedCar::GetColor() const
{
	return color;
}

string ParkedCar::GetLicenseNumber() const
{
	return licenseNumber;
}

int ParkedCar::GetMinutesParked() const
{
	return minutesParked;
}