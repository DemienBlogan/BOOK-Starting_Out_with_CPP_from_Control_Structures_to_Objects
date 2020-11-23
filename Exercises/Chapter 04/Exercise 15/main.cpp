/*
15. Shipping Charges
The Fast Freight Shipping Company charges the following rates:
----------------------------------------------------------------
Weight of Package (in Kilograms)      Rate per 500 Miles Shipped
----------------------------------------------------------------
2 kg or less                          $1.00
Over 2 kg but not more that 6 kg      $2.20
Over 6 kg but not more that 10 kg     $3.70
Over 10 kg but not more that 20 kg    $4.80
----------------------------------------------------------------
Write a program that asks for the weight of the package and the distance it is to be
shipped, then displays the charges.
Input Validation: Do not accept values of 0 or less for the weight of the package. Do
not accept weights of more than 20 kg (this is the maximum weight the company will
ship). Do not accept distances of less than 10 miles or more than 3,000 miles. These
are the company's minimum and maximum shipping distances.
*/

#include <iostream>
#include <iomanip>

int main()
{
	using namespace std;

	cout << "Enter the weight of the package: ";
	double packageWeight;
	cin >> packageWeight;

	if (packageWeight <= 0 || packageWeight > 20)
	{
		cout << "Weight has to be from 1kg to 20kg.\n";
		return 0;
	}

	cout << "Enter the distance it is to be shipped: ";
	int milesShipped;
	cin >> milesShipped;

	if (milesShipped < 10 || milesShipped > 3000)
	{
		cout << "Miles distance has to be from 10 miles to 3000 miles.\n";
		return 0;
	}

	double rate; // $

	if (packageWeight <= 2)
		rate = 1.10;
	else if (packageWeight > 2 && packageWeight <= 6)
		rate = 2.20;
	else if (packageWeight > 6 && packageWeight <= 10)
		rate = 3.70;
	else
		rate = 4.80;

	double charges;

	if (milesShipped % 500 == 0)
		charges = milesShipped / 500 * rate;
	else
		charges = (milesShipped + 1) / 500 * rate;

	cout << fixed << setprecision(2);
	cout << "Charges = $" << charges << endl;

	return 0;
}