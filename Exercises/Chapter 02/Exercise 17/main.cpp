/*
17. Stock Commision
Kathryn bought 750 shares of stock at a price of $35.00 per share. She must pay her
stockbroker a 2 percent com mission for the transaction. Write a program that calculates
and displays the following:
- The amount paid for the stock alone (without the commission).
- The amount of the commission.
- The total amount paid (for the stock plus the commission).
*/

#include <iostream>
#include <iomanip>

int main()
{
	using namespace std;

	int sharesOfStock = 750;
	double stockPrice = 35.00; // $
	double commissionPercent = 0.02;  // 2%
	double amountPaidWithoutCommission = sharesOfStock * stockPrice;
	double commission = amountPaidWithoutCommission * commissionPercent;
	double amountPaidWithCommission = amountPaidWithoutCommission - commission;

	cout << fixed << setprecision(2);
	cout << "Amount paid (without commission) = $" << amountPaidWithoutCommission << endl;
	cout << "Amount paid (with commission)    = $" << amountPaidWithCommission << endl;
	cout << "commission = $" << commission << endl;

	return 0;
}