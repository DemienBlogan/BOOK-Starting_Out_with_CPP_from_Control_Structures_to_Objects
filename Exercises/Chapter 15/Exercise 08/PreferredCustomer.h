#pragma once
#include <string>
#include "CustomerData.h"

class PreferredCustomer : public CustomerData
{
private:
	double purchasesAmount;
	double discountLevel; 
	
	void SetDiscountLevel();

public:
	PreferredCustomer(
		double purchasesAmount,
		const string& lastName,
		const string& firstName,
		const string& address,
		const string& city,
		const string& state,
		const string& zip,
		const string& phone,
		int customerNumber,
		bool mailingList
	);

	void SetPurchasesAmount(double purchasesAmount);
	
	double GetPurchasesAmount() const;
	double GetDiscountLevel() const;
};