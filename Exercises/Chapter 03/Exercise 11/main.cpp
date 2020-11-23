/*
11. Automobile Costs
Write a program that asks the user to enter the monthly costs for the following expenses
incurred from operating his or her automobile: loan payment, insurance, gas, oil, tires,
and maintenance. The program should then display the total monthly cost of these
expenses, and the tota l annual cost of th ese expenses.
*/

#include <iostream>
#include <iomanip>

int main()
{
	using namespace std;

	cout << "Enter loan payment expense: $";
	double loanPaymentExpense;
	cin >> loanPaymentExpense;

	cout << "Enter insurance expense: $";
	double insuranceExpense;
	cin >> insuranceExpense;

	cout << "Enter gas expense: $";
	double gasExpense;
	cin >> gasExpense;

	cout << "Enter oil expense: $";
	double oilExpense;
	cin >> oilExpense;

	cout << "Enter tires expense: $";
	double tiresExpense;
	cin >> tiresExpense;

	cout << "Enter maintenance expense: $";
	double maintenanceExpense;
	cin >> maintenanceExpense;

	double monthlyCost = loanPaymentExpense + insuranceExpense + gasExpense +
		oilExpense + tiresExpense + maintenanceExpense;

	const int MONTHS_IN_YEAR = 12;
	double annualCost = monthlyCost * MONTHS_IN_YEAR;

	cout << fixed << setprecision(2);
	cout << "Total monthly cost = $" << monthlyCost << endl;
	cout << "Total annual cost = $" << annualCost << endl;

	return 0;
}