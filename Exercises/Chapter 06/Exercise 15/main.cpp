/*
15. Overloaded Hospital
Write a program that computes and displays the charges for a patient's hospital
stay. First, the program should ask if the patient was admitted as an inpatient or an
outpaient. If the patient was an inpatient, the following data should be entered:
- The number of days spent in the hospital
- The daily rate
- Hospital medication charges
- Charges for hospital services (lab tests, etc.)

The program should ask for the following data if the patient was an outpatient:
- Charges for hospital services (lab tests, etc.)
- Hospital medication charges

The program should use two overloaded functions to calculate the total charges. One
of the functions should accept arguments for the inpatient data, while the other function
accpets arguments for outpatient information. Both functions should return the
total charges.

Input Validation: Do not accept negative number for any data.
*/

#include <iostream>
#include <iomanip>

double CalculateTotal(int spentDays, double dailyRate, double medicationCharges, double servicesCharges);
double CalculateTotal(double medicationCharges, double servicesCharges);

int main()
{
	using namespace std;

	cout << "Were you admitted as an inpatient (Y - yes, N - no): ";
	char inpatient;
	cin >> inpatient;

	double total;

	if (inpatient == 'Y')
	{
		cout << "Enter the number of days you spent: ";
		int spentDays;
		cin >> spentDays;

		if (spentDays < 0)
		{
			cout << "Incorrect number of spent days.\n";
			return 0;
		}

		cout << "Enter the daily rate: $";
		double dailyRate;
		cin >> dailyRate;

		if (dailyRate < 0)
		{
			cout << "Incorrect daily rate.\n";
			return 0;
		}

		cout << "Enter hospital medication charges: $";
		double medicationCharges;
		cin >> medicationCharges;

		if (medicationCharges < 0)
		{
			cout << "Incorrect number of medication charges.\n";
			return 0;
		}

		cout << "Enter charges for hospital services (lab tests, etc.):	";
		double servicesCharges;
		cin >> servicesCharges;

		if (medicationCharges < 0)
		{
			cout << "Incorrect number of charges for hospital services.\n";
			return 0;
		}

		total = CalculateTotal(spentDays, dailyRate, medicationCharges, servicesCharges);
	}
	else
	{
		cout << "Enter hospital medication charges: $";
		double medicationCharges;
		cin >> medicationCharges;

		if (medicationCharges < 0)
		{
			cout << "Incorrect number of medication charges.\n";
			return 0;
		}

		cout << "Enter charges for hospital services (lab tests, etc.):	";
		double servicesCharges;
		cin >> servicesCharges;

		if (medicationCharges < 0)
		{
			cout << "Incorrect number of charges for hospital services.\n";
			return 0;
		}

		total = CalculateTotal(medicationCharges, servicesCharges);
	}

	cout << fixed << setprecision(2);
	cout << "Total charges = $" << total << endl;

	return 0;
}

double CalculateTotal(int spentDays, double dailyRate, double medicationCharges, double servicesCharges)
{
	double total = spentDays * dailyRate + medicationCharges + servicesCharges;
	return total;
}

double CalculateTotal(double medicationCharges, double servicesCharges)
{
	double total = medicationCharges + servicesCharges;
	return total;
}