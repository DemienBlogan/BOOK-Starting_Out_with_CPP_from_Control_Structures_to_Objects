/*
8. Search Function for Customer Accounts Program
Add a function to Programming Challenge 7 (Customer Accounts) that allows the user
to search the structure array for a particular customer's account. It should accpet part
of the customer's name as an argument then search for an account with a name that
matches it. All accounts that match should be displayed. If no account matches, a message
saying so should be displayed.
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
void ShowAccount(const Account& account);
void ShowDate(const Date& date);
void InitializeAccounts(Account accounts[], size_t customers);
void InitializeAccount(Account& account);
double EnterBalance();
Date EnterLastPayment();
void ChangeAccount(Account accounts[], size_t customers, size_t customerIndex);
size_t EnterCustomerIndex(size_t customers);
string EnterName();
void FindCustomers(const Account accounts[], size_t customers, const string& name);

int main()
{
	const size_t CUSTOMERS = 10;
	Account accounts[CUSTOMERS];
	char menuItem;
	size_t customerIndex;
	string name;

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
		case '3':
			name = EnterName();
			FindCustomers(accounts, CUSTOMERS, name);
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
	cout << "3 - Find accounts by name   \n";
	cout << "0 - Quit                    \n";
}

char SelectMenuItem()
{
	char menuItem;

	do
	{
		cin >> menuItem;

		if (menuItem != '1' && menuItem != '2' && menuItem != '3' && menuItem != '0')
			cout << "Incorrect item. Try again.\n";

	} while (menuItem != '1' && menuItem != '2' && menuItem != '3' && menuItem != '0');

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
		ShowAccount(accounts[i]);
	}
}

void ShowAccount(const Account& account)
{
	cout << "\t Customer name: " << account.customerName << endl;
	cout << "\t Customer address: " << account.customerAddress << endl;
	cout << "\t City: " << account.city << endl;
	cout << "\t State: " << account.state << endl;
	cout << "\t ZIP: " << account.zip << endl;
	cout << "\t Telephone number: " << account.telephoneNumber << endl;
	cout << "\t Balance: $" << account.balance << endl;
	ShowDate(account.lastPayment);
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

string EnterName()
{
	cout << "Enter the name: ";
	string name;
	cin.ignore();
	getline(cin, name);

	return name;
}

void FindCustomers(const Account accounts[], size_t customers, const string& name)
{
	bool isFound = false;

	for (size_t i = 0; i < customers; i++)
	{
		size_t findIndex = accounts[i].customerName.find(name);

		if (findIndex != string::npos)
		{
			isFound = true;
			cout << "Match with account #" << i + 1 << ":\n";
			ShowAccount(accounts[i]);
			cout << endl;
		}
	}

	if (!isFound)
		cout << "There is no match.\n";
}