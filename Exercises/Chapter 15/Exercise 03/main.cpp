/*
3. TeamLeader Class
In a particular factory, a team leader in an hourly paid production worker who leads
a small team. In addition to hourly pay, team leaders earn a fixed monthly bonus.
Team leaders are required to attend a minimum number of hours of training per year.
Design a TeamLeader class that extends the ProductionWorker class you designed in
Programming Challenge 1 (Employee and Production Worker Classes). The TeamLeader
class should have member variables for the monthly bonus amount, the required number
of training hours, and the number of training hours that the team leader has attended.
Write one or more constructors and the appropriate accessor and mutator functions for
the class. Demonstrate the class by writing a program that uses a TeamLeader object.
*/

#include <iostream>

#include "TeamLeader.h"

using std::cout;
using std::endl;

int main()
{
	TeamLeader leader{ "Demien", 18, "24/12/1996", 1, 50.30, 520.00, 420, 140 };

	cout << "Name: " << leader.GetName() << endl;
	cout << "Number: " << leader.GetNumber() << endl;
	cout << "Hire Date: " << leader.GetHireDate() << endl;
	cout << "Shift: " << (leader.GetShift() == 1 ? "Day" : "Night") << endl;
	cout << "Hourly Pay Rate: " << leader.GetHourlyPayRate() << endl;
	cout << "Monthly Bonus: " << leader.GetMonthlyBonus() << endl;
	cout << "Required Training Hours: " << leader.GetRequiredTrainingHours() << endl;
	cout << "Attended Training Hours: " << leader.GetAttendedTrainingHours() << endl;

	return 0;
}