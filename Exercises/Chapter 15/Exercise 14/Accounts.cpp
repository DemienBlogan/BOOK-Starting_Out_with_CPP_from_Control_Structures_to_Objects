#include <iostream>
#include "Accounts.h"

using std::cerr;
using std::cout;

BankAccount::BankAccount(double balance, double interestRate)
	: balance(balance), interestRate(interestRate),
	depositsNumber(0), withdrawalsNumber(0), serviceCharges(0)
{ }

void BankAccount::deposit(double money)
{
	if (money <= 0)
	{
		cerr << "Incorrect value of money in 'BankAccount::deposit' function.\n";
		exit(EXIT_FAILURE);
	}

	balance += money;
	depositsNumber++;
}

void BankAccount::withdraw(double money)
{
	if (money <= 0)
	{
		cerr << "Incorrect value of money in 'BankAccount::deposit' function.\n";
		exit(EXIT_FAILURE);
	}

	if (balance - money < 0)
	{
		cout << "You can't withdraw this value of money.\n";
		return;
	}

	balance -= money;
	withdrawalsNumber++;
}

void BankAccount::calcInt()
{
	double monthlyInterestRate = (interestRate / 12);
	double monthlyInterest = balance * monthlyInterestRate;

	balance += monthlyInterest;
}

void BankAccount::monthlyProc()
{
	balance -= serviceCharges;

	if (balance < 0)
		balance = 0;

	calcInt();

	withdrawalsNumber = depositsNumber = serviceCharges = 0;
}

double BankAccount::GetBalance() const
{
	return balance;
}

int BankAccount::GetDepositsNumber() const
{
	return depositsNumber;
}

int BankAccount::GetWithdrawalsNumber() const
{
	return withdrawalsNumber;
}

double BankAccount::GetInterestRate() const
{
	return interestRate;
}

double BankAccount::GetServiceCharges() const
{
	return serviceCharges;
}

SavingsAccount::SavingsAccount(double balance, double annualInterestRate)
	: BankAccount(balance, annualInterestRate), status(false)
{ }

void SavingsAccount::deposit(double money)
{
	BankAccount::deposit(money);

	if (balance > 25)
		status = true;
}

void SavingsAccount::withdraw(double money)
{
	if (status)
	{
		BankAccount::withdraw(money);

		if (balance < 25.0)
			status = false;
	}
	else
		cout << "Account is inactive.\n";

	withdrawalsNumber++;
}

void SavingsAccount::monthlyProc()
{
	if (status && withdrawalsNumber > 4)
		serviceCharges += 1.00 * (withdrawalsNumber - 4);
}


CheckingAccount::CheckingAccount(double balance, double annualInterestRate)
	: BankAccount(balance, annualInterestRate)
{ }

void CheckingAccount::withdraw(double money)
{
	balance -= money;
	
	if (balance < 0)
		serviceCharges += 15;

	withdrawalsNumber++;
}

void CheckingAccount::monthlyProc()
{
	double monthlyFee = 5.00 + 0.10 * withdrawalsNumber;
	balance -= monthlyFee;

	BankAccount::monthlyProc();
}