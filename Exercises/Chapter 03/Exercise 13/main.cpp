/*
13. Curency
Write a program that will convert U.S. dollar amounts to Japanese yen and to euros,
storing the conversion factors in the constants YEN_PER_DOLLAR and EUROS_PER_DOLLAR. 
To get the most up-to-dare exchange rates, search the Internet using the term
"currency exchange rare". If you cannot find the most recent exchange rates, use the
following:
l Dollar = 98.93 Yen
1 Dollar = 0.74 Euros
Format your currency amounts in fixed-point notation, with two decimal places of
precision, and be sure the decimal point is always displayed.
*/

#include <iostream>
#include <iomanip>

int main()
{
	using namespace std;

	cout << "Enter amount of U.S. dollar: ";
	double usDollars;
	cin >> usDollars;

	const double YEN_PER_DOLLAR = 98.93;
	const double EUROS_PER_DOLLAR = 0.74;

	double yen = usDollars * YEN_PER_DOLLAR;
	double euros = usDollars * EUROS_PER_DOLLAR;

	cout << usDollars << " dollars = " << yen << " yen = " << euros << " euros \n";

	return 0;
}