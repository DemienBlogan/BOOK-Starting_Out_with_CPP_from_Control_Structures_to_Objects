#include "Pharmacy.h"

Pharmacy::Pharmacy(double liquidMedicineCharges,
	double tabletMedicineCharges,
	double capsulesMedicineCharges,
	double dropsMedicineCharges,
	double injectionsMedicineCharges)
	: liquidMedicineCharges(0),
	tabletMedicineCharges(0),
	capsulesMedicineCharges(0),
	dropsMedicineCharges(0),
	injectionsMedicineCharges(0)
{
	if (liquidMedicineCharges > 0)
		this->liquidMedicineCharges = liquidMedicineCharges;

	if (tabletMedicineCharges > 0)
		this->tabletMedicineCharges = tabletMedicineCharges;

	if (capsulesMedicineCharges > 0)
		this->capsulesMedicineCharges = capsulesMedicineCharges;

	if (dropsMedicineCharges > 0)
		this->dropsMedicineCharges = dropsMedicineCharges;

	if (injectionsMedicineCharges > 0)
		this->injectionsMedicineCharges = injectionsMedicineCharges;
}

void Pharmacy::AddCharges(PatientAccount& account, MedicineType medicineType) const
{
	switch (medicineType)
	{
	case Pharmacy::MedicineType::LIQUID:
		account.AddCharges(liquidMedicineCharges);
		break;
	case Pharmacy::MedicineType::TABLET:
		account.AddCharges(tabletMedicineCharges);
		break;
	case Pharmacy::MedicineType::CAPSULES:
		account.AddCharges(capsulesMedicineCharges);
		break;
	case Pharmacy::MedicineType::DROPS:
		account.AddCharges(dropsMedicineCharges);
		break;
	case Pharmacy::MedicineType::INJECTIONS:
		account.AddCharges(injectionsMedicineCharges);
		break;
	}
}