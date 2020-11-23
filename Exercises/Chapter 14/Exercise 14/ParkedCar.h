#pragma once

#include <string>

using std::string;

class ParkedCar
{
private:
	string make;
	string model;
	string color;
	string licenseNumber;
	int minutesParked;

public:
	ParkedCar(
		const string& make = "",
		const string& model = "",
		const string& color = "",
		const string& licenseNumber = "",
		int minutesParked = 0);

	void SetMake(const string& make);
	void SetModel(const string& model);
	void SetColor(const string& color);
	void SetLicenseNumber(const string& licenseNumber);
	void SetMinutesParked(int minutesParked);

	string GetMake() const;
	string GetModel() const;
	string GetColor() const;
	string GetLicenseNumber() const;
	int GetMinutesParked() const;
};