#pragma once

#include <string>

using std::string;

class PersonData
{
private:
	string lastName;
	string firstName;
	string address;
	string city;
	string state;
	string zip;
	string phone;

public:
	PersonData(
		const string& lastName,
		const string& firstName,
		const string& address,
		const string& city,
		const string& state,
		const string& zip,
		const string& phone);

	void SetLastName(const string& lastName);
	void SetFirstName(const string& firstName);
	void SetAddress(const string& address);
	void SetCity(const string& city);
	void SetState(const string& state);
	void SetZip(const string& zip);
	void SetPhone(const string& phone);

	string GetLastName() const;
	string GetFirstName() const;
	string GetAddress() const;
	string GetCity() const;
	string GetState() const;
	string GetZip() const;
	string GetPhone() const;
};