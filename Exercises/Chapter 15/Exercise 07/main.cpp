/*
7. PersonData and CustomerData Classes
Design a class named PersonData with the following member variables:

- lastName
- firstName
- address
- city
- state
- zip
- phone

Write the appropriate accessor and mutator functions for these member variables.

Next, design a class named CustomerData, which is derived from the PersonData
class. The CustomerData class should have the following member variables:

- customerNumber
- mailingList

The customerNumber variable will be used to hold a unique integer for each customer.
The mailingList variable should be a bool. It will be set to true if the customer
wishes to be on a mailing list, or false if the customer does not wish to be on a mailing
list. Write appropriate accessor and mutator functions for these member variables.
Demonstrate an object of the CustomerData class in a simple program.
*/

#include <iostream>

#include "CustomerData.h"

using std::cout;
using std::endl;

int main()
{
	CustomerData customer
	{
		"Blogan", 
		"Demien",
		"Pirogova",
		"Rovno",
		"Ukraine",
		"33000",
		"+380987654321",
		21, 
		true
	};

	cout << "Last Name = " << customer.GetLastName() << endl;
	cout << "First Name = " << customer.GetFirstName() << endl;
	cout << "Address = " << customer.GetAddress() << endl;
	cout << "City = " << customer.GetCity() << endl;
	cout << "State = " << customer.GetState() << endl;
	cout << "Zip = " << customer.GetZip() << endl;
	cout << "Phone = " << customer.GetPhone() << endl;
	cout << "Customer Number = " << customer.GetCustomerNumber() << endl;
	cout << "Mailing List = " << std::boolalpha << customer.GetMailingList() << endl;

	return 0;
}