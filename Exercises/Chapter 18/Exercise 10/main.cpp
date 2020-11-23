/*
10. Payroll Modification
Modify Programming Challenge 9 in Chapter 7 (Payroll) to use three linked lists
instread of three arrays to hold the employee IDs, hours worked, and wages. When the
program starts, it should ask the user to enter the employee IDs. There should be no
limit on the number of IDs the user can enter.
*/

#include <iostream>
#include <iomanip>
#include <list>

int main()
{
	using namespace std;

	const size_t SIZE = 7;

	list<int> empId;
	list<int> hours;
	list<double> payRates;
	list<double> wages;

	for (size_t i = 0; i < SIZE; i++)
	{
		cout << "Enter ID #" << i + 1 << ": ";
		int id;
		cin >> id;
		empId.push_back(id);

		cout << "Enter the number of hours for employee id" << id << ": ";
		int hour;
		cin >> hour;
		hours.push_back(hour);

		cout << "Enter the payRate for employee id" << id << ": $";
		double payRate;
		cin >> payRate;
		payRates.push_back(payRate);

		wages.push_back(hour * payRate);
	}

	cout << fixed << setprecision(2);

	auto empIdIter = empId.cbegin();
	auto wagesIter = wages.cbegin();

	for (; empIdIter != empId.cend() && wagesIter != wages.cend(); ++empIdIter, ++wagesIter)
		cout << "Employee id" << *empIdIter << " wages $" << *wagesIter << endl;

	return 0;
}