#pragma once

#include <string>
#include <fstream>

using std::string;
using std::ifstream;
using std::ofstream;

struct CustomerAccount
{
	string name;
	string address;
	string cityStateZip;
	string telephoneNumber;
	double balance;
	string lastPaymentDate;
};

// Menu/Input/Errors prototypes:
void ShowMenu();
char SelectMenuItem();
void ClearBuffer();
void ShowErrorMessage(const string& message);

// File input/output prototypes:
void OpenFileForRead(ifstream& fin, const string& filename);
void OpenFileForWrite(ofstream& fout, const string& filename);
void ReadCustomersFromFile(ifstream& fin, CustomerAccount** accounts, size_t& customers);
void WriteCustomersToFile(ofstream& fout, const CustomerAccount accounts[], size_t customers);
void OpenAndWrite(ofstream& fout, const string& filename, const CustomerAccount accounts[], size_t customers);

// Show propotypes:
void ShowAccountsList(const CustomerAccount accounts[], size_t customers);
void ShowAccount(const CustomerAccount& account);

// Search/Change/Deleting/Adding prototypes:
void FindAccountByName(const CustomerAccount const accounts[], size_t customers, const string& name);
void ChangeAccountByName(CustomerAccount** accounts, size_t customers, const string& name);
void DeleteAccountByName(CustomerAccount** accounts, size_t& customers, const string& name);
void AddNewAccountToList(CustomerAccount** accounts, size_t& customers, const CustomerAccount& account);
int GetFoundIndexByName(const CustomerAccount const accounts[], size_t customers, const string& name);

// Extra prototypes:
CustomerAccount CreateAccount();
string EnterName();