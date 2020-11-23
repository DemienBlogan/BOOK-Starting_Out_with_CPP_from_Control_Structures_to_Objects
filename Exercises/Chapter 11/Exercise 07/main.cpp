/*
7. Customer Accounts
Write a program that uses a stucture to store the following data about a customer
account:
	Name
	Address
	City, State, and ZIP
	Telephone Number
	Account Balance
	Date of Last Payment
The program should use an array of at least 10 structures. It should let the user enter
data into the array, change the contents of any element, and display all the data stored
in the array. The program should have a menu-driven user interface.

Input Validation: When the data for a new account is entered, be sure the user enters
data for all the fields. No negative account balances should be entered.
*/

#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

struct Date
{
	int day;
	int month;
	int year;
};

struct Account
{
	string customerName;
	string customerAddress;
	string city;
	string state;
	string zip;
	string telephoneNumber;
	double balance;
	Date lastPayment;
};

void ShowMenu();
char SelectMenuItem();
void ErrorTerminate();
void ShowAccounts(const Account accounts[], size_t customers);
void ShowDate(const Date& date);
void InitializeAccounts(Account accounts[], size_t customers);
void InitializeAccount(Account& account);
double EnterBalance();
Date EnterLastPayment();
void ChangeAccount(Account accounts[], size_t customers, size_t customerIndex);
size_t EnterCustomerIndex(size_t customers);

int main()
{
	const size_t CUSTOMERS = 10;
	Account accounts[CUSTOMERS];
	char menuItem;
	size_t customerIndex;

	InitializeAccounts(accounts, CUSTOMERS);

	do
	{
		ShowMenu();
		menuItem = SelectMenuItem();

		switch (menuItem)
		{
		case '1':
			ShowAccounts(accounts, CUSTOMERS);
			break;
		case '2':
			customerIndex = EnterCustomerIndex(CUSTOMERS);
			ChangeAccount(accounts, CUSTOMERS, customerIndex);
			break;
		case '0':
			system("cls");
			break;
		default:
			ErrorTerminate();
			break;
		}

	} while (menuItem != '0');

	return 0;
}

void ShowMenu()
{
	cout << "1 - Show customer accounts  \n";
	cout << "2 - Change account info     \n";
	cout << "0 - Quit                    \n";
}

char SelectMenuItem()
{
	char menuItem;

	do
	{
		cin >> menuItem;

		if (menuItem != '1' && menuItem != '2' && menuItem != '0')
			cout << "Incorrect item. Try again.\n";

	} while (menuItem != '1' && menuItem != '2' && menuItem != '0');

	return menuItem;
}

void ErrorTerminate()
{
	cerr << "Error. Incorrect value of menuItem in default case.\n";
	exit(1);
}

void ShowAccounts(const Account accounts[], size_t customers)
{
	cout << fixed << setprecision(2);

	for (size_t i = 0; i < customers; i++)
	{
		cout << "Account #" << i + 1 << ":\n";
		cout << "\t Customer name: " << accounts[i].customerName << endl;
		cout << "\t Customer address: " << accounts[i].customerAddress << endl;
		cout << "\t City: " << accounts[i].city << endl;
		cout << "\t State: " << accounts[i].state << endl;
		cout << "\t ZIP: " << accounts[i].zip << endl;
		cout << "\t Telephone number: " << accounts[i].telephoneNumber << endl;
		cout << "\t Balance: $" << accounts[i].balance << endl;
		ShowDate(accounts[i].lastPayment);
	}
}

void ShowDate(const Date& date)
{
	cout << "\t Last Payment: " << date.day << "/" << date.month << "/" << date.year << endl;
}

void InitializeAccounts(Account accounts[], size_t customers)
{
	for (size_t i = 0; i < customers; i++)
	{
		cout << "Account #" << i + 1 << ":\n";
		InitializeAccount(accounts[i]);
	}
}

void InitializeAccount(Account& account)
{
	cout << "\t Enter name: ";
	getline(cin, account.customerName);

	cout << "\t Enter address: ";
	getline(cin, account.customerAddress);

	cout << "\t Enter city: ";
	getline(cin, account.city);

	cout << "\t Enter state: ";
	getline(cin, account.state);

	cout << "\t Enter ZIP: ";
	getline(cin, account.zip);

	cout << "\t Enter telephone number: ";
	getline(cin, account.telephoneNumber);

	account.balance = EnterBalance();

	account.lastPayment = EnterLastPayment();
}

double EnterBalance()
{
	double balance;

	do
	{
		cout << "\t Enter balance: ";
		cin >> balance;
		cin.ignore();

		if (balance < 0)
			cout << "Incorrect value. Try again.\n";

	} while (balance < 0);

	return balance;
}

Date EnterLastPayment()
{
	Date date;

	cout << "\t Enter last payment date:\n";

	do
	{
		cout << "\t\t Enter day: ";
		cin >> date.day;
		cin.ignore();

		if (date.day <= 0 || date.day > 30)
			cout << "Incorrect day. Try again.\n";

	} while (date.day <= 0 || date.day > 30);

	do
	{
		cout << "\t\t Enter month: ";
		cin >> date.month;
		cin.ignore();

		if (date.month <= 0 || date.month > 12)
			cout << "Incorrect month. Try again.\n";

	} while (date.month <= 0 || date.month > 12);

	do
	{
		cout << "\t\t Enter year: ";
		cin >> date.year;
		cin.ignore();

		if (date.year <= 0)
			cout << "Incorrect year. Try again.\n";

	} while (date.year <= 0);

	return date;
}

void ChangeAccount(Account accounts[], size_t customers, size_t customerIndex)
{
	if (customerIndex >= customers)
	{
		cout << "Incorrect index of customer.\n";
		return;
	}

	InitializeAccount(accounts[customerIndex]);
}

size_t EnterCustomerIndex(size_t customers)
{
	size_t customerIndex;

	do
	{
		cout << "Enter customer index (0 ... " << customers - 1 << "): ";
		cin >> customerIndex;
		cin.ignore();

		if (customerIndex >= customers)
			cout << "Your index is too large. Try again.\n";

	} while (customerIndex >= customers);

	return customerIndex;
}