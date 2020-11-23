#pragma once

#include "PersonData.h"

class CustomerData : public PersonData
{
private:
	int customerNumber;
	bool mailingList;

public:
	CustomerData(
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

	void SetCustomerNumber(int customerNumber);
	void SetMailingList(bool mailingList);

	int GetCustomerNumber() const;
	bool GetMailingList() const;
};