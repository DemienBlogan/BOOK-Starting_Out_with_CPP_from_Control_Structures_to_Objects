/*
21. Muliple Stock Sales
Use the function that you wrote for Programming Challenge 20 (Stock Profit) in a
program that calculates the profit or loss from the sale of multiple stocks. The
program should ask the user for the number of stock sales and the necessary data for 
each stock sale. It should accumulate the profit or loss for each stock sale, then display
the total.
*/

#include <iostream>
#include <iomanip>

double CalculateProfit(double numberShares, double salePricePerShare, double saleCommission,
	double purchasePricePerShare, double purchaseCommission);

int main()
{
	using namespace std;

	cout << "Enter the number of stock sales: ";
	int numberSales;
	cin >> numberSales;

	double totalProfit = 0;

	for (int i = 0; i < numberSales; i++)
	{
		cout << "Sale #" << i + 1 << ": ";
		cout << "\tEnter the number of shares: $";
		double numberShares;
		cin >> numberShares;

		cout << "\tEnter the sale price per share: $";
		double salePricePerShare;
		cin >> salePricePerShare;

		cout << "\tEnter the sale commission paid: $";
		double saleCommission;
		cin >> saleCommission;

		cout << "\tEnter the purchase price per share: $";
		double purchasePricePerShare;
		cin >> purchasePricePerShare;

		cout << "\tEnter the purchase commission paid: $";
		double purchaseCommission;
		cin >> purchaseCommission;

		double profit = CalculateProfit(numberShares, salePricePerShare, saleCommission,
			purchasePricePerShare, purchaseCommission);

		cout << fixed << setprecision(2);

		if (profit >= 0)
			cout << "\tProfit: $" << profit << endl;
		else
			cout << "\tLose: $" << -profit << endl;

		totalProfit += profit;
	}

	cout << "Total profit: $" << totalProfit << endl;

	return 0;
}

double CalculateProfit(double numberShares, double salePricePerShare, double saleCommission,
	double purchasePricePerShare, double purchaseCommission)
{
	double profit = ((numberShares * salePricePerShare) - saleCommission) -
		((numberShares * purchasePricePerShare) + purchaseCommission);

	return profit;
}