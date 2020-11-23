// Implementation file for the Account class.
#include "example 13-15-Account.h"

bool Account::withdraw(double amount)
{
	if (balance < amount)
		return false; // Not enough in the account
	else
	{
		balance -= amount;
		transactions++;
		return true;
	}
}