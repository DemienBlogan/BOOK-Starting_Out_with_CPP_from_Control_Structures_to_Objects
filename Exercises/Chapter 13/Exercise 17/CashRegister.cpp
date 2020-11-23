#include <iostream>
#include <iomanip>

#include "CashRegister.h"

using std::cout;
using std::cin;
using std::endl;
using std::fixed;
using std::setprecision;

void CashRegister::Show() const
{
	double subtotal = GetPurchaseSubtotal();
	double tax = GetSalesTax();
	double total = subtotal + tax;

	cout << fixed << setprecision(2);
	cout << "Description: " << item.getDescription() << endl;
	cout << "Subtotal = $" << subtotal << endl;
	cout << "Tax = $" << tax << endl;
	cout << "Total = $ " << total << endl;
}

void CashRegister::EnterQuantity()
{
	cout << "Enter quantity of units: ";
	int units;
	cin >> units;

	item.setUnits(units);
}