#pragma once

class PatientAccount
{
private:
	double totalCharges;
	int daysInHospital;

public:
	PatientAccount(int daysInHospital, double daylyPayRate = 10.00);
	void AddCharges(double charges);

	double GetTotalCharges() const { return totalCharges; }
	int GetDaysInHospital() const { return daysInHospital; }
};