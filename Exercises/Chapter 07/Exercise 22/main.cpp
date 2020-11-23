/*
22. Theater Seating
Write a program that can be used by a small theater to sell
tickets for performances. The theater's auditorium has 15 rows of seats, with 30 seats
in each row. The program should display a screen that shows which seats are available
and which are taken. For example, the following screen shows a chart depicting each
seat in the theater. Seats that are taken are represented by an * symbol, and seats that
are available are represented by a # symbol.

Here is a list of tasks this program must perform:

                   Seats
        123456789012345678901234567890
Row 1   *****###***********######*****
Row 2   *********####*****************
Row 3   ****************##************
Row 4   ***####################*******
Row 5   ***#####*****##******#####****
Row 6   ***********###############****
Row 7   **#########***********######**
Row 8   ************#####********##***
Row 9   *****####*************######**
Row 10  **************######**********
Row 11  ******************************
Row 12  ******************************
Row 13  ******************************
Row 14  ******************************
Row 15  ******************************

- When the program begins, it should ask the user to enter the seat prices for each
row. The prices can be stored in a separate array. (Alternatively, the prices may be
read from a file).
- Once the prices are entered, the program should display a seating chart similar to
the one shown above. The user may enter the row and seat numbers for tickets being
sold. Every time a ticket or group of tickets is purchased, the program should display
the total ticket prices and update the seating chart.
- The program should keep a total of all ticket sales. The user should be given an
option of viewing this amount.
- The program should also give the user an option to see a list of how many seats
have been sold, how many seat are available in each row, and how many seats are
available in the entire auditorium.

Input Validation: When tickets are being sold, do not accept row or seat numbers that
do not exist. When someone requests a particular seat, the program should make sure
that seat is available before it is sold.
*/

#include <iostream>
#include <iomanip>
#include <string>

enum class MenuItem
{
	SHOW_AUDITORIUM,
	BUY_TICKET,
	SHOW_REMAINING_TICKETS,
	SHOW_SEAT_INFORMATION,
	QUIT
};

constexpr size_t ROWS = 15, SEATS = 30;

void EnterPrices(double rowPrices[]);
void EnterPrice(double& price);
void SelectMenuItem(MenuItem& menuItem);
void SetAuditorium(char auditorium[ROWS][SEATS]);
void ShowAuditorium(const char auditorium[ROWS][SEATS]);
void ShowMenu();
void ShowRemainingTickets(const char auditorium[ROWS][SEATS]);
void ShowSeatInformation(const char auditorium[ROWS][SEATS]);
void BuyTicket(char auditorium[ROWS][SEATS], const double rowPrices[ROWS]);
int EnterRow();
int EnterSeat();

int main()
{
	using namespace std;

	char auditorium[ROWS][SEATS];
	double rowPrices[ROWS];
	MenuItem menuItem;

	try
	{
		EnterPrices(rowPrices);
		SetAuditorium(auditorium);

		do
		{
			ShowMenu();
			SelectMenuItem(menuItem);
			system("cls");

			switch (menuItem)
			{
			case MenuItem::SHOW_AUDITORIUM:
				ShowAuditorium(auditorium);
				break;

			case MenuItem::BUY_TICKET:
				BuyTicket(auditorium, rowPrices);
				break;

			case MenuItem::SHOW_REMAINING_TICKETS:
				ShowRemainingTickets(auditorium);
				break;

			case MenuItem::SHOW_SEAT_INFORMATION:
				ShowSeatInformation(auditorium);
				break;

			case MenuItem::QUIT:
				system("cls");
				break;

			default:
				throw exception("Error (function 'main'): menuItem has incorect value");
			}

			system("pause");
			system("cls");

		} while (menuItem != MenuItem::QUIT);

	}
	catch (const exception& ex)
	{
		system("cls");
		cout << ex.what() << endl;
	}

	return 0;
}

void EnterPrices(double rowPrices[])
{
	using namespace std;

	if (rowPrices == nullptr)
		throw exception("Error (function 'EnterPrices'): rowPrices = nullptr");

	for (size_t i = 0; i < ROWS; i++)
	{
		cout << "Enter the price of " << i + 1 << " row: $";
		EnterPrice(rowPrices[i]);
		system("cls");
	}
}

void EnterPrice(double& price)
{
	using namespace std;

	do
	{
		cin >> price;

		if (price <= 0)
			cout << "Incorrect value. Try again.\n";

	} while (price <= 0);
}

void SelectMenuItem(MenuItem& menuItem)
{
	using namespace std;

	int minItem = static_cast<int>(MenuItem::SHOW_AUDITORIUM);
	int maxItem = static_cast<int>(MenuItem::QUIT);

	int itemNumber;

	do
	{
		cout << "Select item: ";
		cin >> itemNumber;

		if (itemNumber < minItem || itemNumber > maxItem)
			cout << "Incorrect value. Try again.\n";

	} while (itemNumber < minItem || itemNumber > maxItem);

	menuItem = static_cast<MenuItem>(itemNumber);
}

void SetAuditorium(char auditorium[ROWS][SEATS])
{
	using namespace std;

	if (auditorium == nullptr)
		throw exception("Error (function 'SetAuditorium'): auditorium = nullptr");

	for (size_t i = 0; i < ROWS; i++)
		for (size_t j = 0; j < SEATS; j++)
			auditorium[i][j] = '#';
}

void ShowAuditorium(const char auditorium[ROWS][SEATS])
{
	using namespace std;

	if (auditorium == nullptr)
		throw exception("Error (function 'ShowAuditorium'): auditorium = nullptr");

	cout << setw(10) << "" << "           Seats\n";
	cout << setw(10) << "" << "123456789012345678901234567890\n";
	
	for (size_t i = 0; i < ROWS; i++)
	{
		string row = "Row " + to_string(i + 1);
		cout << setw(10) << left << row;

		for (size_t j = 0; j < SEATS; j++)
			cout << auditorium[i][j];

		cout << endl;
	}
}

void ShowMenu()
{
	using namespace std;

	cout << "0 - Show auditorium                  \n";
	cout << "1 - Buy ticket(s)                    \n";
	cout << "2 - Show number of remaining tickets \n";
	cout << "3 - Show seat information            \n";
	cout << "4 - Quit                             \n";
}

void ShowRemainingTickets(const char auditorium[ROWS][SEATS])
{
	using namespace std;

	if (auditorium == nullptr)
		throw exception("Error (function 'ShowRemainingTickets'): auditorium = nullptr");

	int remainingTickets = 0;

	for (size_t i = 0; i < ROWS; i++)
		for (size_t j = 0; j < SEATS; j++)
			if (auditorium[i][j] == '#')
				remainingTickets++;

	cout << "Remaining tickets: " << remainingTickets << endl;
}

void ShowSeatInformation(const char auditorium[ROWS][SEATS])
{
	using namespace std;

	if (auditorium == nullptr)
		throw exception("Error (function 'ShowSeatInformation'): auditorium = nullptr");

	int availableSeats = 0, takenSeats = 0;
	int rowTakenSeats;

	for (size_t i = 0; i < ROWS; i++)
	{
		rowTakenSeats = 0;

		for (size_t j = 0; j < SEATS; j++)
		{
			if (auditorium[i][j] == '*')
			{
				rowTakenSeats++;
				takenSeats++;
			}
			else
				availableSeats++;
		}

		cout << "Row #" << i + 1 << " taken seats = " << rowTakenSeats << "/" << SEATS << endl;
	}

	cout << "All taken seats = " << takenSeats << endl;
	cout << "All available seats = " << availableSeats << endl;
}

void BuyTicket(char auditorium[ROWS][SEATS], const double rowPrices[ROWS])
{
	using namespace std;

	if (auditorium == nullptr)
		throw exception("Error (function 'BuyTicket'): auditorium = nullptr");

	if (rowPrices == nullptr)
		throw exception("Error (function 'BuyTicket'): rowPrices = nullptr");

	int userRow = EnterRow();
	int userSeat = EnterSeat();

	if (auditorium[userRow][userSeat] == '#')
	{
		auditorium[userRow][userSeat] = '*';

		cout << "You purchased a seat. Price: $" << rowPrices[userRow] << endl;
	}
	else
		cout << "This seat is already taken.\n";
}

int EnterRow()
{
	using namespace std;

	int row;

	do
	{
		cout << "Enter row number (1 ... " << ROWS << "): ";
		cin >> row;

		if (row <= 0 || row > ROWS)
			cout << "Incorrect value. Try again.\n";

	} while (row <= 0 || row > ROWS);

	return row - 1; // indexes start from 0
}

int EnterSeat()
{
	using namespace std;

	int seat;

	do
	{
		cout << "Enter seat number (1 ... " << SEATS << "): ";
		cin >> seat;

		if (seat <= 0 || seat > SEATS)
			cout << "Incorrect value. Try again.\n";

	} while (seat <= 0 || seat > SEATS);

	return seat - 1; // indexes start from 0
}