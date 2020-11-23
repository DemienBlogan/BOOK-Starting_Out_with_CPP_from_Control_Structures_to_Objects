/*
19. Using Files - Hospital Report
Modify Programming Challenge 15 (overloaded Hospital) to write the report it creates
to a file.
*/

#include <iostream>
#include <fstream>
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

	ofstream fout("Result.txt");

	fout << fixed << setprecision(2);
	fout << "Total charges = $" << total << endl;

	fout.close();

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