/*
15. Mortgage Payment
Design a class that will determine the monthly payment on a home mortgage. The
monthly payment with interest compounded monthly can be calculated as follows:

Payment = (Loan * (Rate / 12) * Term) / (Term - 1)

where

Term = (1 + (Rate / 12))^(12 * Years)

Payment = the monthly payment
Loan = the dollar amount of the loan
Rate = the annual interest rate
Years = the number of years of the loan

The class should have member functions for setting the loan amount, interest rate, and
number of years of the loan. It should also have member functions for returning the
monthly payment amount and the total amount paid to the bank at the end of the loan
period. Implement the class in a complete program.

Input Validation: Do not accept negative numbers for any of the loan values.
*/

#include <iostream>
#include <iomanip>

#include "Payment.h"

using std::cin;
using std::cout;
using std::endl;
using std::fixed;
using std::setprecision;

void Show(const Payment& payment);

int main()
{
	Payment mortgage;

	cout << "Enter loan: ";
	double loan;
	cin >> loan;
	mortgage.SetLoan(loan);

	cout << "Enter rate: ";
	double rate;
	cin >> rate;
	mortgage.SetRate(rate);

	cout << "Enter years: ";
	int years;
	cin >> years;
	mortgage.SetYears(years);

	Show(mortgage);

	return 0;
}

void Show(const Payment& payment)
{
	cout << fixed << setprecision(2);

	cout << "Payment = $" << payment.GetPayment() << endl;
	cout << "Loan = $" << payment.GetLoan() << endl;
	cout << "Rate = $" << payment.GetRate() << endl;
	cout << "Term = $" << payment.GetTerm() << endl;
	cout << "Years = " << payment.GetYears() << endl;
}