/*
8. PreferredCustomer Class
A retail store has a preferred customer plan where customers may earn discounts on all
their purchases. The amount of a customer's discount is determined by the amount of
the customer's cumulative purchases in the store.

- When a preferred customer spends $500, he or she gets a 5 percent discount on all
  future purchases.
- When a preferred customer spends $1,000, he or she gets a 6 percent discount on all
  future purchases.
- When a preferred customer spends $1,500, he or she gets a 7 percent discount on all
  future purchases.
- When a preferred customer spends $2,000 or more, he or she gets a 10 percent discount
  on all future purchases.

Design a class named PreferredCustomer, which is derived from the CustomerData
class you created in Programming Challenge 7. The PreferredCustomer class should
have the following member variables:

- purchasesAmount(a double)
- discountLevel (a double)

The purchasesAmount variable holds the total of a customer's purchases to date. The
discountLevel variable should be set to the correct discount percentage, according to
the store's preferred customer plan. Write appropriate member functions for this class
and demonstrate it in a simple program.

Input Validation: Do not accept negative values for any sales figures.
*/

#include <iostream>
#include "PreferredCustomer.h"

using std::cout;
using std::endl;

int main()
{
	PreferredCustomer customer{
		1700,
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


	cout << "Purchases Amount = " << customer.GetPurchasesAmount() << endl;
	cout << "Discount Level = " << customer.GetDiscountLevel() << endl;
	cout << "First Name = " << customer.GetFirstName() << endl;
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