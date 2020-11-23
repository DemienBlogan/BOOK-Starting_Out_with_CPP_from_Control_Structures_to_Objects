// This program uses the == operator to compare a string entered
// by the user with the valid part numbers.
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

int main()
{
	const double APRICE = 249.0; // Price for part A
	const double BPRICE = 199.0; // Price for part B
	string partNum;              // Part number

	cout << "The headphone part numbers are:\n";
	cout << "\tNoise canceling, part number S147-29A\n";
	cout << "\tWireless, part number S147-29B\n";
	cout << "Enter the part number of the desired headphones: ";
	cin >> partNum;
	cout << fixed << showpoint << setprecision(2);

	if (partNum == "S147-29A")
		cout << "The price is $" << APRICE << endl;
	else if (partNum == "S147-29B")
		cout << "The price is $" << BPRICE << endl;
	else
		cout << partNum << " is not a valid part number.\n";
	return 0;
}