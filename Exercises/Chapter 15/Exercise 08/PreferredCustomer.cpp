#include "PreferredCustomer.h"

void PreferredCustomer::SetDiscountLevel()
{
	if (purchasesAmount >= 2'000)
		discountLevel = purchasesAmount * 0.10;
	else if (purchasesAmount >= 1'500)
		discountLevel = purchasesAmount * 0.07;
	else if (purchasesAmount >= 1'000)
		discountLevel = purchasesAmount * 0.06;
	else if (purchasesAmount >= 500)
		discountLevel = purchasesAmount * 0.05;
	else
		discountLevel = 0.00;
}

PreferredCustomer::PreferredCustomer(
	double purchasesAmount, 
	const string& lastName,
	const string& firstName,
	const string& address,
	const string& city,
	const string& state,
	const string& zip,
	const string& phone,
	int customerNumber,
	bool mailingList)
	: purchasesAmount(0),
	discountLevel(0),
	CustomerData{ 
		lastName, 
		firstName, 
		address, 
		city, 
		state, 
		zip, 
		phone,
		customerNumber, 
		mailingList }	
{
	SetPurchasesAmount(purchasesAmount);
	SetDiscountLevel();
}

void PreferredCustomer::SetPurchasesAmount(double purchasesAmount)
{
	if (purchasesAmount >= 0)
	{
		this->purchasesAmount = purchasesAmount;

		SetDiscountLevel();
	}
}

double PreferredCustomer::GetPurchasesAmount() const
{
	return purchasesAmount;
}

double PreferredCustomer::GetDiscountLevel() const
{
	return discountLevel;
}