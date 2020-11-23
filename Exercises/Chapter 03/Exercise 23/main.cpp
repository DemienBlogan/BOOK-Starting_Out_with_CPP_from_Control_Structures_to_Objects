/*
23. Stock Transaction Program
Last month Joe purchased some stock in Acme Software, Inc. Here are the details of
the purchase:
- The number of shares that Joe purchased was 1,000.
- When Joe purchased the stock, he paid $45.50 per share.
- Joe paid his stockbroker a commission that amoumed to 2 percent of the amount
   he paid for the stock.

Two weeks later, Joe sold the stock. Here are the derails of the sale:
- The number of shares that Joe sold was 1,000.
- He sold the stock for $56.90 per share.
- He paid his stockbroker another comm ission that amounted to 2 percent of the
  amount he received for the stock.

Write a program that displays the following information:
- The amount of money Joe paid for the stock.
- The amount of commission Joe paid his broker when he bought the stock.
- The amount that Joe sold the stock for.
- The amount of commission Joe paid his broker when be sold the stock.
- Display the amount of profit that Joe made after selling his stock and paying the
  two commissions to his broker. (If the amount of profit that your program displays
  is a negative number, then Joe lost money on the transaction).
*/

#include <iostream>
#include <iomanip>

int main()
{
	using namespace std;

	int purchasedShares = 1000, soldShares = 1000;
	double purchasedPaidPerShare = 45.50, soldPaidPerShare = 56.90;

	double purchasedPaid = (purchasedShares * purchasedPaidPerShare);
	double soldPaid = (soldShares * soldPaidPerShare);

	const double COMMISSION_PERCENT = 0.02; // 2%
	double commissionPurchased = purchasedPaid * COMMISSION_PERCENT;
	double commissionSold = purchasedPaid * COMMISSION_PERCENT;

	cout << fixed << setprecision(2);

	cout << "Amount of money Joe paid for the stock: $" << purchasedPaid << endl;
	cout << "The amount of commission (buying): $" << commissionPurchased << endl;

	cout << "Amount of money Joe sold the stock for: $" << soldPaid << endl;
	cout << "The amount of commission (buying): $" << commissionSold << endl;

	double purchasedMoney = purchasedPaid + commissionSold;
	double soldMoney = soldPaid - commissionSold;
	double profit = soldMoney - purchasedMoney;

	cout << "Profit = $" << profit << endl;

	return 0;
}