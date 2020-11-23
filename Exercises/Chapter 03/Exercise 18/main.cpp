/*
18. Interest Earned
Assuming there are no deposits other than the original investment, the balance in a
savings account after one year may be calculated as

Amount = Principal * (1 + Rate / T) ^ T

Principal is the balance in the savings account, Rate is the interest rate, and T is
the number of times the interest is compounded during a year (T is 4 if the interest is
compounded quarterly).
Write a program that asks for the principal, the interest rare, and the number of times
the interest is compounded. It should display a report similar ro:
Interest Rate:     4.25%
Times Compounded : 12
Principal :        $ 1000.00
Interest:          $ 43.34
Amount in Savings: $ 1043.34
*/

#include <iostream>
#include <iomanip>
#include <cmath>

int main()
{
	using namespace std;

	cout << "Enter the principal: $";
	double principal;
	cin >> principal;

	cout << "Enter the interest rate: ";
	double interestRate;
	cin >> interestRate;

	cout << "Enter the number of times the interest is compounded: ";
	int timesCompounded;
	cin >> timesCompounded;

	double amountInSavings = principal *
		pow((1.0 + interestRate / timesCompounded), timesCompounded);
	double interest = amountInSavings - principal;
	double interestPercent = interestRate * 100;

	cout << fixed << setprecision(2);
	cout << "Interest Rate:	     " << interestPercent << "%\n";
	cout << "Times Compounded:   " << setw(7) << timesCompounded << endl;
	cout << "Principal:         $" << setw(7) << principal << endl;
	cout << "Interest:          $" << setw(7) << interest << endl;
	cout << "Amount of Savings: $" << setw(7) << amountInSavings << endl;

	return 0;
}