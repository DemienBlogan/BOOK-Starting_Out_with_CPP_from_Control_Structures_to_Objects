#pragma once

#include "PatientAccount.h"

class Pharmacy
{
private:
	double liquidMedicineCharges;
	double tabletMedicineCharges;
	double capsulesMedicineCharges;
	double dropsMedicineCharges;
	double injectionsMedicineCharges;

public:
	Pharmacy(double liquidMedicineCharges = 20.30,
		double tabletMedicineCharges = 15.60,
		double capsulesMedicineCharges = 21.40,
		double dropsMedicineCharges = 5.99,
		double injectionsMedicineCharges = 41.50);

	enum class MedicineType
	{
		LIQUID,
		TABLET,
		CAPSULES,
		DROPS,
		INJECTIONS
	};

	void AddCharges(PatientAccount& account, MedicineType medicineType) const;
};