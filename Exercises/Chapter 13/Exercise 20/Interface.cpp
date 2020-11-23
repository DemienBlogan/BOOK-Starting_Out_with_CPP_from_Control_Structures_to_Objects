#include <iostream>
#include <iomanip>

#include "Interface.h"

using std::cout;
using std::cin;
using std::fixed;
using std::setprecision;
using std::endl;

void ShowMainMenu()
{
	cout << "1 - Buy medicine \n";
	cout << "2 - Make surgery \n";
	cout << "0 - Quit         \n";
}

void ShowPharmacyMenu()
{
	cout << "1 - Liquid       \n";
	cout << "2 - Tablet       \n";
	cout << "3 - Capsules     \n";
	cout << "4 - Drops        \n";
	cout << "5 - Injenctions  \n";
	cout << "0 - Quit         \n";
}

void ShowSurgeryMenu()
{
	cout << "1 - Bariatric        \n";
	cout << "2 - Breast           \n";
	cout << "3 - Colon and rectal \n";
	cout << "4 - Endicrine        \n";
	cout << "5 - Gynecological    \n";
	cout << "0 - Quit             \n";
}

char SelectItem()
{
	char item;
	cin >> item;

	system("cls");

	return item;
}

void ShowPatientTotalCharges(const PatientAccount& account)
{
	cout << fixed << setprecision(2);
	cout << "Total charges: $" << account.GetTotalCharges() << endl;
	cout << "Days spent in hostipal: " << account.GetDaysInHospital() << endl;
}

void ShowError()
{
	cout << "Incorrect item. Try again.\n";
	system("pause");
	system("cls");
}
