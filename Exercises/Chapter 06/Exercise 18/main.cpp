/*
18. Paint Job Estimator
A painting company has determined that for every 110 square feet of wall space,
1 gallon of paint and 8 hours of labor will be required. The company charges $25.00
per hour for labor. Write a dodular program that allows the user to enter the number
of rooms that are to be painted and the price of the paint per gallon. It should also
ask for the square feet of wall space in each room. It should then display the following data:
- The number of gallons of paint required
- The hours of labor required
- The cost of the paint
- The labor charges
- The total cost of the paint job

Input validation: Do not accept a value less than 1 for the number of rooms. Do not
accept a value less than $10.00 for the price of paint. Do not accept a negative value
for square footage of wall space.
*/

#include <iostream>
#include <iomanip>

int EnterNumberRooms();
double EnterPricePaintPerGallon();
double EnterSquareFeetWallSpace();

int main()
{
	using namespace std;

	// 110 sqr. feet = 1 gallon = 8 hours.
	// 1 hour = $25

	int numberRooms = EnterNumberRooms();
	double pricePaintPerGallon = EnterPricePaintPerGallon();
	double squareFeetWallSpace = EnterSquareFeetWallSpace();

	const double SQUARE_FEET_PER_GALLON = 110.0;
	const double HOURS_PER_GALLON = 8.0;
	const double COST_OF_LABOR_1_HOUR = 25.00;

	double requiredGallons = numberRooms * squareFeetWallSpace / SQUARE_FEET_PER_GALLON;
	double requiredHours = requiredGallons * HOURS_PER_GALLON;
	double costPaint = requiredHours * pricePaintPerGallon;
	double laborCharges = requiredHours * COST_OF_LABOR_1_HOUR;
	double totalCost = costPaint + laborCharges;

	cout << "The number of gallons of paint required: " << requiredGallons << endl;
	cout << "The hours of labor required: " << requiredHours << endl;

	cout << fixed << setprecision(2);
	cout << "The cost of the paint: $" << costPaint << endl;
	cout << "The labor charges: $" << laborCharges << endl;
	cout << "The total cost of the paint job: $" << totalCost << endl;

	return 0;
}

int EnterNumberRooms()
{
	using namespace std;

	int rooms;

	do
	{
		cout << "Enter the number of rooms (1 or more): ";
		cin >> rooms;

		if (rooms < 1)
			cout << "The number of rooms can't be less than 1. Try again.\n";

	} while (rooms < 1);

	return rooms;
}

double EnterPricePaintPerGallon()
{
	using namespace std;

	double price;

	do
	{
		cout << "Enter the price of the paint per gallon: ";
		cin >> price;

		if (price < 10.00)
			cout << "The price of the paint per gallon can't be less than $10.00. Try again.\n";

	} while (price < 10.00);

	return price;
}

double EnterSquareFeetWallSpace()
{
	using namespace std;

	double feet;

	do
	{
		cout << "Enter the square feet of wall space in each room: ";
		cin >> feet;

		if (feet < 0)
			cout << "The the square feet of wall space in each room can't be negative. Try again.\n";

	} while (feet < 0);

	return feet;
}