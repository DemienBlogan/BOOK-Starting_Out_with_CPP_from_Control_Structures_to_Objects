/*
5. Membership Fees Increase
A country club, which currently charges $2,500 per year for membership, has announced
it will increase its membership fee by 4 percent each year for the next 6 years. Write a
program that uses a loop to display the projected rates for the next 6 years.
*/

#include <iostream>
#include <iomanip>

int main()
{
	using namespace std;

	double charges = 2'500.00;

	for (int year = 1; year <= 6; year++)
	{
		charges += charges * 0.04;
		cout << fixed << setprecision(2);
		cout << "After 1 year country club chages $" << charges << endl;
	}

	return 0;
}