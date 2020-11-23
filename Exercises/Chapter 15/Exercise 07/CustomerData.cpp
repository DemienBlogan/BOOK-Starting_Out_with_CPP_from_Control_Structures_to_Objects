#include "CustomerData.h"

CustomerData::CustomerData(
    const string& lastName, 
    const string& firstName,
    const string& address,
    const string& city, 
    const string& state, 
    const string& zip,
    const string& phone, 
    int customerNumber, 
    bool mailingList)
    : PersonData(lastName, firstName, address, city, state, zip, phone),
    customerNumber(customerNumber),
    mailingList(mailingList)
{ }

void CustomerData::SetCustomerNumber(int customerNumber)
{
    this->customerNumber = customerNumber;
}

void CustomerData::SetMailingList(bool mailingList)
{
    this->mailingList = mailingList;
}

int CustomerData::GetCustomerNumber() const
{
    return customerNumber;
}

bool CustomerData::GetMailingList() const
{
    return mailingList;
}