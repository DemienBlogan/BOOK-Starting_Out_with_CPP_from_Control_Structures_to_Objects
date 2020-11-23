/*
10. How Much Insurance?
Many financial experts advise chat property owners should insure their homes or buildings
for at least 80 percent of the amount it would cost to replace the structure. Write
a program that asks the user to enter the replacement cost of a building, then displays
the minimum amount of insurance he or she should b uy for the property.
*/

#include <iostream>
#include <iomanip>

int main()
{
	using namespace std;

	const double INSURE_PERCENT = 0.8; // 80%

	cout << "Enter the replacement cost of a building: $";
	double replacementCost;
	cin >> replacementCost;

	double amountInsurance = replacementCost * INSURE_PERCENT;

	cout << fixed << setprecision(2);
	cout << "The minimum amount of insurance you should pay = $" << amountInsurance << endl;

	return 0;
}