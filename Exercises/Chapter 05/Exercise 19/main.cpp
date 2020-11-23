/*
19. Budget Analysis
Write a program that asks the user to enter the amount that he or she has budgeted for
a month. A loop should then prompt the user to enter each of his or her expenses for
the month and keep a running total. When the loop finishes, the program should display
the amount that the user is over or under budget.
*/

#include <iostream>
#include <iomanip>

int main()
{
	using namespace std;

	cout << "Enter the amount that you have budgeted for a month: $";
	double budget;
	cin >> budget;

	cout << "Did you have any expenses (y - yes, n - no): ";
	char haveExpenses;
	cin >> haveExpenses;

	while (haveExpenses == 'y')
	{
		cout << "Enter the expense: $";
		double expense;
		cin >> expense;

		budget -= expense;

		cout << "Did you have anyother expenses (y - yes, n - no): ";
		char haveExpenses;
		cin >> haveExpenses;
	}

	cout << fixed << setprecision(2);
	cout << "Your budget: $" << budget << endl;

	return 0;
}