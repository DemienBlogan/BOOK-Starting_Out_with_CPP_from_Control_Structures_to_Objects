#include <iostream>

#include "CustomerAccount.h"

using std::cout;
using std::cin;
using std::cerr;
using std::endl;
using std::getline;

void ShowMenu()
{
	cout << "1 - Display list of accounts \n";
	cout << "2 - Add new account          \n";
	cout << "3 - Search account by name   \n";
	cout << "4 - Delete account by name   \n";
	cout << "5 - Change account by name   \n";
	cout << "0 - Quit                     \n";
}

char SelectMenuItem()
{
	char menuItem;

	cout << "Select menu item: ";
	cin >> menuItem;

	ClearBuffer();
	system("cls");

	return menuItem;
}

void ClearBuffer()
{
	while (cin.get() != '\n')
		continue;
}

void ShowErrorMessage(const string& message)
{
	system("cls");
	cout << message << endl;
	system("pause");
	system("cls");
}

void OpenFileForRead(ifstream& fin, const string& filename)
{
	fin.open(filename);

	if (!fin)
	{
		cerr << "File '" << filename << "' could not been opened.\n";
		exit(1);
	}
}

void OpenFileForWrite(ofstream& fout, const string& filename)
{
	fout.open(filename);

	if (!fout)
	{
		cerr << "File '" << filename << "' could not been opened.\n";
		exit(1);
	}
}

void ReadCustomersFromFile(ifstream& fin, CustomerAccount** accounts, size_t& customers)
{
	(fin >> customers).ignore();

	if (customers == 0)
	{
		*accounts = nullptr;
		return;
	}

	*accounts = new CustomerAccount[customers];

	for (size_t i = 0; i < customers; i++)
	{
		getline(fin, (*accounts)[i].name);
		getline(fin, (*accounts)[i].address);
		getline(fin, (*accounts)[i].cityStateZip);
		getline(fin, (*accounts)[i].telephoneNumber);
		(fin >> (*accounts)[i].balance).ignore();
		getline(fin, (*accounts)[i].lastPaymentDate);
	}
}

void WriteCustomersToFile(ofstream& fout, const CustomerAccount accounts[], size_t customers)
{
	fout << customers << endl;

	if (customers != 0)
	{
		for (size_t i = 0; i < customers; i++)
		{
			fout << accounts[i].name << endl;
			fout << accounts[i].address << endl;
			fout << accounts[i].cityStateZip << endl;
			fout << accounts[i].telephoneNumber << endl;
			fout << accounts[i].balance << endl;
			fout << accounts[i].lastPaymentDate << endl;
		}
	}
}

void ShowAccountsList(const CustomerAccount accounts[], size_t customers)
{
	if (accounts == nullptr || customers == 0)
		cout << "List is empty.\n";
	else
	{
		for (size_t i = 0; i < customers; i++)
		{
			cout << "Account #" << i + 1 << ":\n";
			ShowAccount(accounts[i]);
		}
	}

	system("pause");
	system("cls");
}

void ShowAccount(const CustomerAccount& account)
{
	cout << "\t Customer name: " << account.name << endl;
	cout << "\t Customer address: " << account.address << endl;
	cout << "\t Customer city, state, ZIP: " << account.cityStateZip << endl;
	cout << "\t Customer telephone number: " << account.telephoneNumber << endl;
	cout << "\t Account balance: $" << account.balance << endl;
	cout << "\t Date of last payment: " << account.lastPaymentDate << endl;
}

CustomerAccount CreateAccount()
{
	CustomerAccount account;

	cout << "Enter customer name: ";
	getline(cin, account.name);

	cout << "Enter customer address: ";
	getline(cin, account.address);

	cout << "Enter customer city, state, ZIP: ";
	getline(cin, account.cityStateZip);

	cout << "Enter customer telephone number: ";
	getline(cin, account.telephoneNumber);

	do
	{
		cout << "Enter account balance: $";
		(cin >> account.balance).ignore();

		if (account.balance < 0)
			cout << "Incorrect value. Try again.\n";

	} while (account.balance < 0);

	cout << "Enter date of last payment: ";
	getline(cin, account.lastPaymentDate);

	return account;
}

int GetFoundIndexByName(const CustomerAccount const accounts[], size_t customers, const string& name)
{
	if (accounts == nullptr || customers == 0)
		return -1;

	for (size_t i = 0; i < customers; i++)
		if (accounts[i].name == name)
			return i;

	return -1;
}

void AddNewAccountToList(CustomerAccount** accounts, size_t& customers, const CustomerAccount& account)
{
	if (customers == 0)
	{
		customers = 1;
		*accounts = new CustomerAccount[customers];
		(*accounts)[0] = account;
	}
	else
	{
		customers++;
		CustomerAccount* newAccounts = new CustomerAccount[customers];

		for (size_t i = 0; i < customers - 1; i++)
		{
			newAccounts[i] = (*accounts)[i];
		}

		newAccounts[customers - 1] = account;
		delete[] * accounts;

		*accounts = newAccounts;
	}

	cout << "New Account was added.\n";
	system("pause");
	system("cls");
}

void FindAccountByName(const CustomerAccount const accounts[], size_t customers, const string& name)
{
	if (accounts == nullptr || customers == 0)
		cout << "List is empty.\n";
	else
	{
		int findIndex = GetFoundIndexByName(accounts, customers, name);

		if (findIndex == -1)
			cout << "This account was not found.\n";
		else
		{
			cout << "Here is your searching account:\n";
			ShowAccount(accounts[findIndex]);
		}

		system("pause");
		system("cls");
	}
}

string EnterName()
{
	cout << "Enter a name: ";
	string name;
	getline(cin, name);
	return name;
}

void ChangeAccountByName(CustomerAccount** accounts, size_t customers, const string& name)
{
	if (accounts == nullptr || customers == 0)
		cout << "List is empty.\n";
	else
	{
		int findIndex = GetFoundIndexByName(*accounts, customers, name);

		if (findIndex == -1)
			cout << "This account was not found.\n";
		else
		{
			(*accounts)[findIndex] = CreateAccount();
			cout << "Account was changed.\n";
		}

		system("pause");
		system("cls");
	}
}

void OpenAndWrite(ofstream& fout, const string& filename, const CustomerAccount accounts[], size_t customers)
{
	OpenFileForWrite(fout, filename);
	WriteCustomersToFile(fout, accounts, customers);
	fout.close();
}

void DeleteAccountByName(CustomerAccount** accounts, size_t& customers, const string& name)
{
	if (accounts == nullptr || customers == 0)
		cout << "List is empty.\n";
	else
	{
		int findIndex = GetFoundIndexByName(*accounts, customers, name);

		if (findIndex == -1)
			cout << "This account was not found.\n";
		else if (customers == 1)
		{
			delete[] * accounts;
			*accounts = nullptr;
			customers = 0;
		}
		else
		{
			customers--;
			CustomerAccount* newAccounts = new CustomerAccount[customers];

			size_t index = 0;
			for (size_t i = 0; i < findIndex; i++)
				newAccounts[index++] = (*accounts)[i];

			for (size_t i = findIndex + 1; i < customers + 1; i++)
				newAccounts[index++] = (*accounts)[i];

			delete[] * accounts;
			*accounts = newAccounts;
			cout << "This account was deleted.\n";
		}

		system("pause");
		system("cls");
	}
}