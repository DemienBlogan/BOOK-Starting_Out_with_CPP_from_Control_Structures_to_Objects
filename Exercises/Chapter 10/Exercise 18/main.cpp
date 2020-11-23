/*
18. Phone Number List
Write a program that has an array of at least 10 string objects that hold people's
names and phone numbers. You may make up your own strings, or use the following:
"Alejandra Cruz, 555-1223"
"Joe Looney, 555-0097"
"Geri Palmer, 555-8787"
"Li Chen, 555-1212"
"Holly Gaddis, 555-8878"
"Sam Wiggins, 555-0998"
"Bob Kain, 555-8712"
"Tim Haynes, 555-7676"
"Warren Gaddis, 555-9037"
"Jean James, 555-4939"
"Ron Palmer, 555-2783"
The program should ask the user to enter a name or partial name to search for in the
array. Any entries in the array that match the string entered should be displayed. For
example, if the user enters "Palmer" the program should display the following names
from the list:
Geri Palmer, 555-8787
Ron Palmer, 555-2783
*/

#include <iostream>
#include <string>

using namespace std;

string EnterName();
void ShowAllContactsByName(const string list[], size_t size, const string& name);
bool DoesContain(const string& mainString, const string& subString);

int main()
{
	const size_t SIZE = 11;
	string contactList[SIZE] =
	{
		"Alejandra Cruz, 555-1223",
		"Joe Looney, 555-0097",
		"Geri Palmer, 555-8787",
		"Li Chen, 555-1212",
		"Holly Gaddis, 555-8878",
		"Sam Wiggins, 555-0998",
		"Bob Kain, 555-8712",
		"Tim Haynes, 555-7676",
		"Warren Gaddis, 555-9037",
		"Jean James, 555-4939",
		"Ron Palmer, 555-2783"
	};

	string userName = EnterName();
	ShowAllContactsByName(contactList, SIZE, userName);

	return 0;
}

string EnterName()
{
	cout << "Enter a name: ";
	string name;
	cin >> name;
	return name;
}
void ShowAllContactsByName(const string list[], size_t size, const string& name)
{
	bool isFound = false;
	for (size_t i = 0; i < size; i++)
	{
		if (DoesContain(list[i], name))
		{
			cout << "Contact #" << i + 1 << ": " << list[i] << endl;
			isFound = true;
		}
	}

	if (!isFound)
		cout << "There is no people with this name.\n";
}

bool DoesContain(const string& mainString, const string& subString)
{
	return strstr(mainString.c_str(), subString.c_str()) != nullptr ? true : false;
}