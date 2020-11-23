#include "PersonData.h"

PersonData::PersonData(
	const string& lastName,
	const string& firstName,
	const string& address,
	const string& city,
	const string& state,
	const string& zip,
	const string& phone)
{
	SetLastName(lastName);
	SetFirstName(firstName);
	SetAddress(address);
	SetCity(city);
	SetState(state);
	SetZip(zip);
	SetPhone(phone);
}

void PersonData::SetLastName(const string& lastName)
{
	this->lastName = lastName;
}

void PersonData::SetFirstName(const string& firstName)
{
	this->firstName = firstName;
}

void PersonData::SetAddress(const string& address)
{
	this->address = address;
}

void PersonData::SetCity(const string& city)
{
	this->city = city;
}

void PersonData::SetState(const string& state)
{
	this->state = state;
}

void PersonData::SetZip(const string& zip)
{
	this->zip = zip;
}

void PersonData::SetPhone(const string& phone)
{
	this->phone = phone;
}

string PersonData::GetLastName() const
{
	return lastName;
}

string PersonData::GetFirstName() const
{
	return firstName;
}

string PersonData::GetAddress() const
{
	return address;
}

string PersonData::GetCity() const
{
	return city;
}

string PersonData::GetState() const
{
	return state;
}

string PersonData::GetZip() const
{
	return zip;
}

string PersonData::GetPhone() const
{
	return phone;
}
