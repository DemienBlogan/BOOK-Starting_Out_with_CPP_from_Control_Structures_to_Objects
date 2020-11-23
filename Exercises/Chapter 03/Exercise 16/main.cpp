/*
Madison County provides a $5,000 homeowner exemption for its senior citizens. For
example, if a senior's house is valued at $158,000, its assessed value would be $94,800,
as explained above. However, he would only pay tax on $89,800. At last year's tax
rate of $2.64 for each $100 of assessed value, the property tax would be $2,370.72. In
addition to the tax break, senior citizens are allowed to pay their property tax in four
equal payments. The quarterly payment due on this property would be $592.68. Write
a program chat asks the user to input the actual value of a piece of property and the
current tax race for each $100 of assessed value. The program should then calculate
and report how much annual property tax a senior homeowner will be charged for this
property, and what the quarterly tax bill will be.
*/

#include <iostream>
#include <iomanip>

int main()
{
	using namespace std;

	cout << "Enter the actual value of a piece of property: $";
	double pieceOfProperty;
	cin >> pieceOfProperty;

	cout << "Enter the current tax for each $100: $";
	double currentTaxForEach100;
	cin >> currentTaxForEach100;

	const double HOMEOWNER_EXEPTION = 5000.00; //$
	double payTax = pieceOfProperty - HOMEOWNER_EXEPTION;
	double assessedValue = payTax / 100 * currentTaxForEach100;
	double quartalyPaymentDue = assessedValue / 4;

	cout << fixed << setprecision(2);
	cout << "Assessed value = $" << assessedValue << endl;
	cout << "QuartalyPaymentDue = $" << quartalyPaymentDue << endl;

	return 0;
}