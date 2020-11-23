/*
16. Customer Accounts
This program should be designed and written by a team of students. Here are some
suggestions:
- One student should design function main, which will call other program functions.
  The remainder of the functions will be designed by other members of the team.
- The requirements of the program should be analyzed so that each student is given
  about the same workload.

Write a program that uses a structure to store the following data about a customer
account:
- Name
- Address
- City, State, and ZIP
- Telephone Number
- Account Balance
- Date of Last Payment

The structure should be used to store customer account records in a file. The program
should have a menu that lets the user perform the following operations:
- Enter new records into the file
- Search for a particular customer's record and display it
- Search for a particular customer's record and delete it
- Search for a particular customer's record and change it
- Display the contents of the entire file

Input Validation: When the data for a new account is entered, be sure the user enters
data for all the fields. No negative account balances should be entered.
*/

#include "CustomerAccount.h"

int main()
{
	// Data:
	CustomerAccount* accounts = nullptr;
	size_t customers = 3;

	string filename{ "Customers.txt" };
	ifstream fin;
	ofstream fout;

	char menuItem;

	// Initial data reading:
	OpenFileForRead(fin, filename);
	ReadCustomersFromFile(fin, &accounts, customers);
	fin.close();

	// Main cycle:
	do
	{
		ShowMenu();
		menuItem = SelectMenuItem();

		switch (menuItem)
		{
		case '0':
			system("cls");
			break;

		case '1':
			ShowAccountsList(accounts, customers);
			break;

		case '2':
			AddNewAccountToList(&accounts, customers, CreateAccount());
			OpenAndWrite(fout, filename, accounts, customers);
			break;

		case '3':
			FindAccountByName(accounts, customers, EnterName());
			break;

		case '4':
			DeleteAccountByName(&accounts, customers, EnterName());
			OpenAndWrite(fout, filename, accounts, customers);
			break;

		case '5':
			ChangeAccountByName(&accounts, customers, EnterName());
			OpenAndWrite(fout, filename, accounts, customers);
			break;

		default:
			ShowErrorMessage("Incorrect menu item. Try again.");
			break;
		}

	} while (menuItem != '0');

	delete[] accounts;

	return 0;
}