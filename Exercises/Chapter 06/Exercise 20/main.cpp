/*
20. Stock Profit
The profit from the sale of a stock can be calculated as follows:

Profit = ((NS * SP) - SC) - ((NS * PP) + PC)

where NS is the number of shares, SP is the sale price per share, SC is the sale commission
paid, PP is the purchase price per share, and PC is the purchase commission paid.
If the calculation yields a positive value, then the sale of the stock resulted in a profit.
If the calculation yields a negative number, then the sale resulted in a loss.

Write a function that accepts as arguments the number of shares, the purchase price per
share, the puchase commission paid, the sale price per share, and the sale commission
paid. The function should return the profit (or loss) from the sale of stock.

Demonstrate the function in a program that asks the user the necessary data
and displays the amount of the profit or loss.
*/

#include <iostream>
#include <iomanip>

double CalculateProfit(double numberShares, double salePricePerShare, double saleCommission,
	double purchasePricePerShare, double purchaseCommission);

int main()
{
	using namespace std;

	cout << "Enter the number of shares: $";
	double numberShares;
	cin >> numberShares;

	cout << "Enter the sale price per share: $";
	double salePricePerShare;
	cin >> salePricePerShare;

	cout << "Enter the sale commission paid: $";
	double saleCommission;
	cin >> saleCommission;

	cout << "Enter the purchase price per share: $";
	double purchasePricePerShare;
	cin >> purchasePricePerShare;

	cout << "Enter the purchase commission paid: $";
	double purchaseCommission;
	cin >> purchaseCommission;

	double profit = CalculateProfit(numberShares, salePricePerShare, saleCommission,
		purchasePricePerShare, purchaseCommission);

	cout << fixed << setprecision(2);

	if (profit >= 0)
		cout << "Profit: $" << profit << endl;
	else
		cout << "Lose: $" << -profit << endl;

	return 0;
}

double CalculateProfit(double numberShares, double salePricePerShare, double saleCommission,
	double purchasePricePerShare, double purchaseCommission)
{
	double profit = ((numberShares * salePricePerShare) - saleCommission) -
		((numberShares * purchasePricePerShare) + purchaseCommission);

	return profit;
}