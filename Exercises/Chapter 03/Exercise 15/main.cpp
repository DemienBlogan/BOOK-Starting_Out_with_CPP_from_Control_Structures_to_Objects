/*
15. Property Tax
A county collects property taxes on the assessment value of property, which is 60 percent
of the property's actual value. If an acre of land is valued at $10,000, its assessment
value is $6,000. The property tax is then 75¢ for each $100 of the assessment value.
The tax for the acre assessed at $6,000 will be $45. Write a program that asks for the
actual value of a piece of property, then displays the assessment value and property rax.
*/

#include <iostream>
#include <iomanip>

int main()
{
	using namespace std;

	cout << "Enter actual value of a piece of property: $";
	double actualValue;
	cin >> actualValue;

	const double ASSESSMENT_VALUE_PERCENT = 0.6; // 6%
	double assessmentValue = actualValue * ASSESSMENT_VALUE_PERCENT;

	const double PROPERTY_TAX_FOR_100_DOLLARS = 0.75; // of dollar (cents)
	double propertyTax = assessmentValue / 100 * PROPERTY_TAX_FOR_100_DOLLARS;

	cout << fixed << setprecision(2);
	cout << "Assessment Value = $" << assessmentValue << endl;
	cout << "Property tax = $" << propertyTax << endl;

	return 0;
}