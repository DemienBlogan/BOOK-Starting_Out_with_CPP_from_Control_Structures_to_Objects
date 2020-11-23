/*
5. Male and Female Percentages
Write a program that asks the user for the nunber of males and the number of females
registered in a class. The program should display the percentage of males and females
in the class.

Hint: Suppose there are 8 males and 12 females in a class. There are 20 students in the
class. The percentage of males can be calculated as 8 + 20 = 0.4, or 40 percent. The
percentage of females can be calculated as 12 + 20 = 0.6, or 60 percent.
*/

#include <iostream>

int main()
{
	using namespace std;

	cout << "Enter amount of males: ";
	int males;
	cin >> males;

	cout << "Enter amount of females: ";
	int females;
	cin >> females;

	int students = males + females;
	double malesPercent = static_cast<double>(males) / students * 100;
	double femalesPercent = static_cast<double>(females) / students * 100;

	cout << "Students = " << students << endl;
	cout << "Males = " << males << " (" << malesPercent << "%)\n";
	cout << "Females = " << females << " (" << femalesPercent << "%)\n";

	return 0;
}