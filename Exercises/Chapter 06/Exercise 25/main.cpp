/*
25. Travel Expenses
Write a program that calculates and displays the total travel
expenses of a businessperson on a trip. The program should have function that ask
for and return the following:

- The total number of days spent on the trip
- The time of departure on the first day of the trip, and the time of arrival back home
  on the last day of the trip
- The amount of any round-trip airfare
- The amount of any car rentals
- Miles driven, if a private vehicle was used. Calculate the vehicle expense as $0.27
  per mile driven
- Parking fees (The company allows up to $6 per day. Anything in excess of the must
  by paid by the employee).
- Taxi fees, if a taxi was used anytime during the trip (The company allows up to $10
  per day, for each day a taxi was used. Anything in excess of this must be paid be the
  employee).
- Conference or seminar registration fees
- Hotel expenses (The company allows up to $90 per night for lodging. Anything in
  excess of this must be paid by the employee).
- The amount of each meal eaten. On the first day of the trip, breakfast is allowed
  as an expense if the time of departure is before 7 a.m. Lunch is allowed if the time
  of departure is before 12 noon. Dinner is allowed on the first day if the time of
  departure is before 6 p.m. On the last day of the trip, breakfast is allowed if the
  time of arrival is after 8 a.m. Lunch is allowed if the time of arrival is after 1 p.m.
  Dinner is allowed on the last day if the time of arrival is after 7 p.m. The program
  should only ask for the amounts of allowable meals. (The company allows up to $9
  for breakfast, $12 for lunch, and $16 for dinner. Anything in excess of this must be
  paid by the employee).

The program should calculate and display the total expenses incurred by the businessperson,
the total allowable expenses for the trip, the excess that must be reimbursed
by the businessperson, if any, and the amount saved by the businessperson if
the expenses were under the total allowed.

Input Validation: Do not accept negative numbers for any dollar amount or for miles
driven in a private vehicle. Do not accept numbers less than 1 for the number of days.
Only accept valid times for the time of departure and the time of arrival.
*/

#include <iostream>
#include <iomanip>

// Prototypes:
int EnterNumberDaysOnTrip();
int EnterTime();
int EnterDepartureTime();
int EnterArrivalTime();
double EnterAirfareCost();
double EnterCarRentalsCost();
double EnterMilesDriven();
double EnterPrivateVehicleCost();
double EnterParkingFees();
double CalculateParkingCost(double fees, int days);
double EnterTaxiFees();
double CalculateTaxiCost(double fees, int days);
double EnterRegistrationFees();
double EnterHotelExpenses();
double CalculateHotelCost(double expenses, int days);
double EnterBreakfastExpenses();
double EnterLunchExpenses();
double EnterDinnerExpenses();
double CalculateBreakfastCost(double expenses, int days, int departureHours, int arrivalHours);
double CalculateLunchCost(double expenses, int days, int departureHours, int arrivalHours);
double CalculateDinnerCost(double expenses, int days, int departureHours, int arrivalHours);

// The main function
int main()
{
	using namespace std;

	int numberDaysOnTrip     = EnterNumberDaysOnTrip();
	int departureTime        = EnterDepartureTime();
	int arrivalTime          = EnterArrivalTime();
	double airfareCost       = EnterAirfareCost();
	double rentalCost        = EnterCarRentalsCost();
	double hotelExpenses     = EnterHotelExpenses();
	double taxiFees          = EnterTaxiFees();
	double parkingFees       = EnterParkingFees();
	double vehicleCost       = EnterPrivateVehicleCost();
	double registrationFees  = EnterRegistrationFees();
	double breakfastExpenses = EnterBreakfastExpenses();
	double lunchExpenses     = EnterLunchExpenses();
	double dinnerExpenses    = EnterDinnerExpenses();
	double parkingCost       = CalculateParkingCost(parkingFees, numberDaysOnTrip);
	double taxiCost          = CalculateTaxiCost(taxiFees, numberDaysOnTrip);
	double hotelCost         = CalculateHotelCost(hotelExpenses, numberDaysOnTrip);
	double breakfastCost     = CalculateBreakfastCost(breakfastExpenses, numberDaysOnTrip, departureTime, arrivalTime);
	double lunchCost         = CalculateLunchCost(lunchExpenses, numberDaysOnTrip, departureTime, arrivalTime);
	double dinnerCost        = CalculateDinnerCost(dinnerExpenses, numberDaysOnTrip, departureTime, arrivalTime);

	double totalExpenses = airfareCost + rentalCost + hotelExpenses + taxiFees + parkingFees + vehicleCost +
		registrationFees + breakfastExpenses + lunchExpenses + dinnerExpenses;

	double totalAllowableExpenses = airfareCost + rentalCost + hotelCost + taxiCost + parkingCost + vehicleCost +
		registrationFees +	breakfastCost + lunchCost + dinnerCost;

	double savedMoney = totalExpenses - totalAllowableExpenses;

	cout << "The total numbe rof days spent of the trip: " << numberDaysOnTrip << endl;
	cout << "The time of departure on the first day of the trip (hours): " << departureTime << endl;
	cout << "The time of arrival back home on the last day of the trip (hours): " << arrivalTime << endl;
	cout << "The amount of any round-trip airfare: $" << airfareCost << endl;
	cout << "Vehicle expense: $" << vehicleCost << endl;
	cout << "Parking fees: $" << parkingFees << endl; 
	cout << "Parking cost: $" << parkingCost << endl;
	cout << "Taxi fees: $" << taxiFees << endl;
	cout << "Taxi cost: $" << taxiCost << endl;
	cout << "Ragistration fees: $" << registrationFees << endl;
	cout << "Hotel expenses: $" << hotelExpenses << endl;
	cout << "Hotel cost: $" << hotelCost << endl;
	cout << "Breakfast expenses: $" << breakfastExpenses << endl;
	cout << "Breakfast cost: $" << breakfastCost << endl;
	cout << "Lunch expenses: $" << lunchExpenses << endl;
	cout << "Lunch cost: $" << lunchCost << endl;
	cout << "Dinner expenses: $" << dinnerExpenses << endl;
	cout << "Dinner cost: $" << dinnerCost << "\n\n";
	cout << "Total expenses: $" << totalExpenses << endl;
	cout << "Total cost: $" << totalAllowableExpenses << endl;

	if (savedMoney >= 0)
		cout << "You saved $" << savedMoney << endl;
	else
		cout << "You lost $" << -savedMoney << endl;

	return 0;
}

// Functions definitions:
int EnterNumberDaysOnTrip()
{
	using namespace std;

	int days;

	do
	{
		cout << "Enter the number of days spent on the trip: ";
		cin >> days;

		if (days <= 0)
			cout << "Incorrect number of days.\n";

	} while (days <= 0);

	return days;
}

int EnterTime()
{
	using namespace std;

	int hours; 
	do
	{
		cout << "Enter hours (0-23): ";
		cin >> hours;

		if (hours < 0 || hours > 23)
			cout << "Incorrect value.\n";

	} while (hours < 0 || hours > 23);

	return hours;
}

int EnterDepartureTime()
{
	using namespace std;
	cout << "Enter the time of departure on the first day of the trip.\n";
	return EnterTime();
}

int EnterArrivalTime()
{
	using namespace std;
	cout << "The the time of arrival back home on the last day of the trip.\n";
	return EnterTime();
}

double EnterAirfareCost()
{
	using namespace std;

	double airfare;

	do
	{
		cout << "Enter the amount of the round-trip airfare: $";
		cin >> airfare;

		if (airfare <= 0)
			cout << "Incorrect amount.\n";

	} while (airfare <= 0);

	return airfare;
}

double EnterCarRentalsCost()
{
	using namespace std;

	double carRental;

	do
	{
		cout << "Enter the amount of any car rentals: $";
		cin >> carRental;

		if (carRental <= 0)
			cout << "Incorrect amount.\n";

	} while (carRental <= 0);

	return carRental;
}

double EnterMilesDriven()
{
	using namespace std;

	double miles;

	do
	{
		cout << "Enter the miles driven: ";
		cin >> miles;

		if (miles < 0)
			cout << "Incorrect value.\n";

	} while (miles < 0);

	return miles;
}

double EnterPrivateVehicleCost()
{
	using namespace std;

	cout << "Did you use private vehicle (Y - yes, N - no): ";
	char answer;
	cin >> answer;

	double vehicleCost;

	if (answer == 'Y' || answer == 'y')
		vehicleCost = 0;
	else
	{
		const double COST_1_MILE = 0.27;
		double miles = EnterMilesDriven();

		vehicleCost = miles * COST_1_MILE;
	}

	return vehicleCost;
}

double EnterParkingFees()
{
	using namespace std;

	double fees;

	do
	{
		cout << "Enter parking fees: ";
		cin >> fees;

		if (fees < 0)
			cout << "Incorrect value.\n";

	} while (fees < 0);

	return fees;
}

double CalculateParkingCost(double fees, int days)
{
	const double COMPANY_SPENT_PER_DAY = 6.00;
	double companyHelp = days * COMPANY_SPENT_PER_DAY;
	double cost = fees - companyHelp;

	return cost > 0 ? cost : 0;
}

double EnterTaxiFees()
{
	using namespace std;

	double fees;

	do
	{
		cout << "Enter taxi fees: ";
		cin >> fees;

		if (fees < 0)
			cout << "Incorrect value.\n";

	} while (fees < 0);

	return fees;
}

double CalculateTaxiCost(double fees, int days)
{
	const double COMPANY_SPENT_PER_DAY = 10.00;
	double companyHelp = days * COMPANY_SPENT_PER_DAY;
	double cost = fees - companyHelp;

	return cost > 0 ? cost : 0;
}

double EnterRegistrationFees()
{
	using namespace std;

	double fees;

	do
	{
		cout << "Enter conference registration fees: ";
		cin >> fees;

		if (fees < 0)
			cout << "Incorrect value.\n";

	} while (fees < 0);

	return fees;
}

double EnterHotelExpenses()
{
	using namespace std;

	double expenses;

	do
	{
		cout << "Enter the hotel expenses: ";
		cin >> expenses;

		if (expenses < 0)
			cout << "Incorrect value.\n";

	} while (expenses < 0);

	return expenses;
}

double CalculateHotelCost(double expenses, int days)
{
	const double COMPANY_SPENT_PER_DAY = 90.00;
	double companyHelp = days * COMPANY_SPENT_PER_DAY;
	double cost = expenses - companyHelp;

	return cost > 0 ? cost : 0;
}

double EnterBreakfastExpenses()
{
	using namespace std;

	double expenses;

	do
	{
		cout << "Enter the total amount spent on breakfast during the trip: $";
		cin >> expenses;

		if (expenses < 0)
			cout << "Incorrect value.\n";

	} while (expenses < 0);

	return expenses;
}

double EnterLunchExpenses()
{
	using namespace std;

	double expenses;

	do
	{
		cout << "Enter the total amount spent on lunch during the trip: $";
		cin >> expenses;

		if (expenses < 0)
			cout << "Incorrect value.\n";

	} while (expenses < 0);

	return expenses;
}

double EnterDinnerExpenses()
{
	using namespace std;

	double expenses;

	do
	{
		cout << "Enter the total amount spent on dinner during the trip: $";
		cin >> expenses;

		if (expenses < 0)
			cout << "Incorrect value.\n";

	} while (expenses < 0);

	return expenses;
}

double CalculateBreakfastCost(double expenses, int days, int departureHours, int arrivalHours)
{
	if (departureHours < 7)
		days--;

	if (arrivalHours > 20)
		days--;

	if (days <= 0)
		return 0;

	const double COMPANY_SPENT_PER_BREAKFAST = 9.00;
	double cost = expenses - COMPANY_SPENT_PER_BREAKFAST * days;
	return cost > 0 ? cost : 0;
}

double CalculateLunchCost(double expenses, int days, int departureHours, int arrivalHours)
{
	if (departureHours < 12)
		days--;

	if (arrivalHours > 13)
		days--;

	if (days <= 0)
		return 0;

	const double COMPANY_SPENT_PER_LUNCH = 12.00;
	double cost = expenses - COMPANY_SPENT_PER_LUNCH * days;
	return cost > 0 ? cost : 0;
}

double CalculateDinnerCost(double expenses, int days, int departureHours, int arrivalHours)
{
	if (departureHours < 18)
		days--;

	if (arrivalHours > 19)
		days--;

	if (days <= 0)
		return 0;

	const double COMPANY_SPENT_PER_DINNER = 16.00;
	double cost = expenses - COMPANY_SPENT_PER_DINNER * days;
	return cost > 0 ? cost : 0;
}