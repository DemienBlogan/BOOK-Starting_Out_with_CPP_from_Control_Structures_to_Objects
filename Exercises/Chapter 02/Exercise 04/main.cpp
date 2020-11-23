/*
4. Restaurant Bill
Write a program that computes the tax and tip on a restaurant bill for a patron with
a $88.67 meal charge. The tax should be 6.75 percent of the meal cost. The tip should
be 20 percent of the total after adding the tax. Display the meal cost, tax amount, tip
amount, and total bill on the screen.
*/

#include <iostream>
#include <iomanip>

int main()
{
	using namespace std;

	double mealCost = 88.67; // $
	const double TAX_PERCENT = 0.0675; // 6.75%
	const double TIP_PERCENT = 0.2;    // 20%
	double tax = mealCost * TAX_PERCENT;
	double tip = (mealCost - tax) * TIP_PERCENT;
	double totalBill = mealCost + tax + tip;

	cout << fixed << setprecision(2);
	cout << "Meal cost = $" << mealCost << endl;
	cout << "Tax = $" << tax << endl;
	cout << "Tip = $" << tip << endl;
	cout << "Total Bill = $" << totalBill << endl;

	return 0;
}