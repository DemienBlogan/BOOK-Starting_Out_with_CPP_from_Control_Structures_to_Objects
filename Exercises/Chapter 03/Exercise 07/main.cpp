/*
7. Box Office
A movie theater only keeps a percentage of the revenue earned from ticket sales. The
remainder goes co the movie distributor. Write a program that calculates a theater's
gross and net box office profit for a night. The program should ask for the name of the
movie, and how many adult and child tickets were sold. (The price of an adult ticket is
$10.00 and a child's ticket is $6 .00). It should display a report similar to:

Movie Name:                  "Wheels of Fury"
Adult Tickers Sold:          382
Child Tickets Sold:          127
Gross Box Office Profit:     $ 4,582.00
Net Box Office Profit:       $ 916.40
Amount Paid co Distributor:  $ 3,665.60

NOTE : Assume the theater keeps 20 percent of the gross box office profit.
*/

#include <iostream>
#include <string>
#include <iomanip>

int main()
{
	using namespace std;

	const double PRICE_ADULT_TICKET = 10.00;  // $
	const double PRICE_CHILD_TICKET = 6.00;   // $
	const double NET_BOX_KEEP_PERCENT = 0.2;  // 20%

	cout << "Enter the name of the film: ";
	string movieName;
	getline(cin, movieName);

	cout << "Enter amount of sold adult tickets: ";
	int soldAdultTickets;
	cin >> soldAdultTickets;

	cout << "Enter amount of sold child tickets: ";
	int soldChildTickets;
	cin >> soldChildTickets;

	cout << endl;

	double adultProfit = soldAdultTickets * PRICE_ADULT_TICKET;
	double childProfit = soldChildTickets * PRICE_CHILD_TICKET;
	double grossBoxOfficeProfit = adultProfit + childProfit;
	double netBoxOfficeProfit = grossBoxOfficeProfit * NET_BOX_KEEP_PERCENT;
	double amountPaidtoDistributor = grossBoxOfficeProfit - netBoxOfficeProfit;

	cout << "Movie Name:                \"" << movieName << "\"\n";
	cout << "Adult Tickets Sold:         " << soldAdultTickets << endl;
	cout << "Child Tickets Sold:         " << soldChildTickets << endl;
	cout << fixed << setprecision(2);
	cout << "Gross Box Office Profit:   $" << grossBoxOfficeProfit << endl;
	cout << "Net Box Office Profit:     $" << netBoxOfficeProfit << endl;
	cout << "Amount Paid to Distrubutor $" << amountPaidtoDistributor << endl;

	return 0;
}