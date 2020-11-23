#include "PatientAccount.h"

PatientAccount::PatientAccount(int daysInHospital, double daylyPayRate)
	: daysInHospital(0), totalCharges(0)
{
	if (daysInHospital > 0)
		this->daysInHospital = daysInHospital;

	if (daylyPayRate > 0)
		totalCharges += this->daysInHospital * daylyPayRate;
}

void PatientAccount::AddCharges(double charges)
{
	if (charges > 0)
		totalCharges += charges;
}