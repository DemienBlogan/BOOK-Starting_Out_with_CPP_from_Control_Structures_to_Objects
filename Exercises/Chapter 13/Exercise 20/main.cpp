/*
20. Patient Fees
You are to write a program that computes a patient's bill for a hospital stay. The
different components of the program are
The PatientAccount class
The Surgery class
The Pharmacy class
The main program

- The PatientAccount class will keep a total of the patient's charges. It will also
  keep track of the number of days spent in the hospital. The group must decide
  on the hospital's daily rate.
- The Surgery class will have stored within it the charges for at least five types
  of surgery. It can update the charges variable of the PatientAccount class.
- The Pharmacy class will have stored within it the price of at least five types of
  medication. It can update the charges variable of the PatientAccount class.
- The student who designs the main program will design a menu that allows the
  user to enter a type of surgery and a type of medication, and check the patient
  out of the hospital. When the patient checks out, the total charges should be
  displayed.
*/

#include "PatientAccount.h"
#include "Pharmacy.h"
#include "Surgery.h"
#include "Interface.h"

int main()
{
	PatientAccount patient{ 10 };
	Pharmacy pharmacy;
	Surgery surgery;
	char mainMenuItem;
	char pharmacyMenuItem;
	char surgeryMenuItem;

	do
	{
		ShowMainMenu();
		mainMenuItem = SelectItem();

		switch (mainMenuItem)
		{
		case '0':
			// No code
			break;

		case '1':
			do
			{
				ShowPharmacyMenu();
				pharmacyMenuItem = SelectItem();

				switch (pharmacyMenuItem)
				{
				case '0':
					// No code
					break;
				case '1':
					pharmacy.AddCharges(patient, Pharmacy::MedicineType::LIQUID);
					break;
				case '2':
					pharmacy.AddCharges(patient, Pharmacy::MedicineType::TABLET);
					break;
				case '3':
					pharmacy.AddCharges(patient, Pharmacy::MedicineType::CAPSULES);
					break;
				case '4':
					pharmacy.AddCharges(patient, Pharmacy::MedicineType::DROPS);
					break;
				case '5':
					pharmacy.AddCharges(patient, Pharmacy::MedicineType::INJECTIONS);
					break;
				default:
					ShowError();
					break;
				}

			} while (pharmacyMenuItem != '0');
			break;

		case '2':
			do
			{
				ShowSurgeryMenu();
				surgeryMenuItem = SelectItem();

				switch (surgeryMenuItem)
				{
				case '0':
					// No code
					break;
				case '1':
					surgery.AddCharges(patient, Surgery::SurgeryType::BARIATRIC);
					break;
				case '2':
					surgery.AddCharges(patient, Surgery::SurgeryType::BREAST);
					break;
				case '3':
					surgery.AddCharges(patient, Surgery::SurgeryType::COLON_AND_RECTAL);
					break;
				case '4':
					surgery.AddCharges(patient, Surgery::SurgeryType::ENDOCRINE);
					break;
				case '5':
					surgery.AddCharges(patient, Surgery::SurgeryType::GYNECOLOGICAL);
					break;
				default:
					ShowError();
					break;
				}

			} while (surgeryMenuItem != '0');
			break;

		default:
			ShowError();
			break;
		}

	} while (mainMenuItem != '0');

	ShowPatientTotalCharges(patient);

	return 0;
}