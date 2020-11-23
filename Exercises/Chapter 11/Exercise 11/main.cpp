/*
11. Monthly Budget
A student has established the following monthly budget:
	Housing               $500.00
	Utilities             $150.00
	Household Expenses    $65.00
	Transportation        $50.00
	Food                  $250.00
	Medical               $30.00
	Insurance             $100.00
	Entertainment         $150.00
	Clothing              $75.00
	Miscellaneous         $50.00
Write a program that has a MonthlyBudget structure designed to hold each of these
expense categories. The program should pass the structure to a function that asks the
user to enter the amounts spent in each budget category during a month. The program
should hen pass the structure to a function that displays a report indication the
amount over or under in each category, as well as the amount over or under for the
entire monthly budget.
*/

#include <iostream>
#include <iomanip>

using namespace std;

struct Expenses
{
	double housing;
	double utilities;
	double householdExpenses;
	double transportation;
	double food;
	double medical;
	double insurance;
	double entertainment;
	double clothing;
	double miscellaneous;
};

void EnterExpenses(Expenses& expenses);
void ShowExpenses(const Expenses& expenses, const Expenses& budget);

int main()
{
	const Expenses BUDGET =
	{
		500.00,
		150.00,
		65.00,
		50.00,
		250.00,
		30.00,
		100.00,
		150.00,
		75.00,
		50.00
	};

	Expenses studentExpenses;

	EnterExpenses(studentExpenses);
	ShowExpenses(studentExpenses, BUDGET);

	return 0;
}

void EnterExpenses(Expenses& expenses)
{
	cout << "Enter housing: $";
	cin >> expenses.housing;

	cout << "Enter utilities: $";
	cin >> expenses.utilities;

	cout << "Enter household expenses: $";
	cin >> expenses.householdExpenses;

	cout << "Enter transportation: $";
	cin >> expenses.transportation;

	cout << "Enter food: $";
	cin >> expenses.food;

	cout << "Enter medical: $";
	cin >> expenses.medical;

	cout << "Enter insurance: $";
	cin >> expenses.insurance;

	cout << "Enter entertainment: $";
	cin >> expenses.entertainment;

	cout << "Enter clothing: $";
	cin >> expenses.clothing;

	cout << "Enter miscellaneous: $";
	cin >> expenses.miscellaneous;
}

void ShowExpenses(const Expenses& expenses, const Expenses& budget)
{
	cout << fixed << setprecision(2);
	cout << "-------------- Expenses ------ Budget ------ Over/Under\n";

	cout << "Housing        $" << setw(6) << expenses.housing;
	cout << "        $" << setw(6) << budget.housing;
	cout << "         " << showpos << budget.housing - expenses.housing << noshowpos << endl;

	cout << "utilities      $" << setw(6) << expenses.utilities;
	cout << "        $" << setw(6) << budget.utilities;
	cout << "         " << showpos << budget.utilities - expenses.utilities << noshowpos << endl;

	cout << "transportation $" << setw(6) << expenses.transportation;
	cout << "        $" << setw(6) << budget.transportation;
	cout << "         " << showpos << budget.transportation - expenses.transportation << noshowpos << endl;

	cout << "food           $" << setw(6) << expenses.food;
	cout << "        $" << setw(6) << budget.food;
	cout << "         " << showpos << budget.food - expenses.food << noshowpos << endl;

	cout << "medical        $" << setw(6) << expenses.medical;
	cout << "        $" << setw(6) << budget.medical;
	cout << "         " << showpos << budget.medical - expenses.medical << noshowpos << endl;

	cout << "insurance      $" << setw(6) << expenses.insurance;
	cout << "        $" << setw(6) << budget.insurance;
	cout << "         " << showpos << budget.insurance - expenses.insurance << noshowpos << endl;

	cout << "entertainment  $" << setw(6) << expenses.entertainment;
	cout << "        $" << setw(6) << budget.entertainment;
	cout << "         " << showpos << budget.entertainment - expenses.entertainment << noshowpos << endl;

	cout << "clothing       $" << setw(6) << expenses.clothing;
	cout << "        $" << setw(6) << budget.clothing;
	cout << "         " << showpos << budget.clothing - expenses.clothing << noshowpos << endl;

	cout << "miscellaneous  $" << setw(6) << expenses.miscellaneous;
	cout << "        $" << setw(6) << budget.miscellaneous;
	cout << "         " << showpos << budget.miscellaneous - expenses.miscellaneous << noshowpos << endl;

	double totalExpenses = expenses.housing + expenses.utilities + expenses.transportation +
		expenses.food + expenses.medical + expenses.insurance + expenses.entertainment +
		expenses.clothing + expenses.miscellaneous;

	double totalBudget = budget.housing + budget.utilities + budget.transportation +
		budget.food + budget.medical + budget.insurance + budget.entertainment +
		budget.clothing + budget.miscellaneous;

	double totalOverUnder = totalBudget - totalExpenses;

	cout << "Total          $" << setw(6) << totalExpenses;
	cout << "        $" << setw(6) << totalBudget;
	cout << "         " << showpos << totalOverUnder << endl;
}