/*
6. Ingredient Adjuster
A cookie recipe calls for the following ingredients:
- l.5 cups of sugar
- 1 cup of butter
- 2. 75 cups of flour
The recipe produces 48 cookies with this amount of the ingredients. Write a program
that asks the user how many cookies he or she wants to make, then displays the number
of cups of each ingredient needed for the specified number of cookies.
*/

#include <iostream>
#include <iomanip>

int main()
{
	using namespace std;

	const double SUGAR_FOR_1_COOKIE = 1.5 / 48;
	const double BUTTER_FOR_1_COOKIE = 1.0 / 48;
	const double FLOUR_FOR_1_COOKIE = 2.75 / 48;

	cout << "How many cookies you want to make?: ";
	int cookies;
	cin >> cookies;

	double sugarNeeded = SUGAR_FOR_1_COOKIE * cookies;
	double butterNeeded = BUTTER_FOR_1_COOKIE * cookies;
	double flourNeeded = FLOUR_FOR_1_COOKIE * cookies;

	cout << "You need:\n";
	cout << fixed << setprecision(2);
	cout << " - " << sugarNeeded << " cups of sugar\n";
	cout << " - " << butterNeeded << " cups of butter\n";
	cout << " - " << flourNeeded << " cups of flour\n";

	return 0;
}