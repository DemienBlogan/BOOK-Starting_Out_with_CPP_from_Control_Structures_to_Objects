/*
19. Monthly Payments
The monthly payment on a loan may be calculated by the following formula:

Payment = (Rate * (1 + Rate) ^ N) / ((1 + Rate) ^ N) - 1) * L

Rate is the monthly interest rare, which is the annual interest rate divided by 12.
(12 percent annual inrerest would be 1 percent monthly interest). N is the number of
payments, and L is the amount of the loan. Write a program that asks for these values
then displays a report similar to:
Loan Amount:           $ 10000.00
Monthly Interest Rate: 1%
Number of Payments:    36
Monthly Payment:       $   332.14
Amount Paid Back:      $ 11957.15
Interest Paid:         $  1957.15
*/

#include <iostream>
#include <iomanip>
#include <cmath>

int main()
{
	using namespace std;

	cout << "Enter the interest rate: ";
	double interestRate;
	cin >> interestRate;

	cout << "Enter the number of payments: ";
	int numberOfPayments;
	cin >> numberOfPayments;

	cout << "Enter the amount of the loan: $";
	double loanAmount;
	cin >> loanAmount;

	double numerator = interestRate * pow((1 + interestRate), numberOfPayments);
	double denominator = pow((1.0 + interestRate), numberOfPayments) - 1.0;
	double monthlyPayment = numerator / denominator * loanAmount;
	int interestRatePercent = interestRate * 100; // %
	double amountPaidBack = monthlyPayment * numberOfPayments;
	double interestPaid = amountPaidBack - loanAmount;

	cout << fixed << setprecision(2);
	cout << "Loan Amount:            $" << loanAmount << endl;
	cout << "Monthly Interest Rate:  " << interestRatePercent << "%\n";
	cout << "Number of Payments:     " << numberOfPayments << endl;
	cout << "Monthly Payment:        $" << monthlyPayment << endl;
	cout << "Amount Paid Back:       $" << amountPaidBack << endl;
	cout << "Interest Paid:          $" << interestPaid << endl;

	return 0;
}