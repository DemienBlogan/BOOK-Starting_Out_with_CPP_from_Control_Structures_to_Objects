/*
7. Name Arranger
Write a program that asks for the user's first, middle, and last names. The names
should be stored in three different character arrays. The program should then store,
in a fourth array, the name arranged in the following manner: the last name followed
by a comma and a space, followed by the first name and a space, followed by the
middle name. For example, if the user entered "Carol Lynn Smith", it should store
"Smith, Carol Lynn" in the fourth array. Display the contents of the fourth array
on the screen.
*/

#include <iostream>
#include <cstring>

int main()
{
	using namespace std;

	const size_t SIZE = 30;

	cout << "Enter first name: ";
	char firstName[SIZE];
	cin >> firstName;

	cout << "Enter middle name: ";
	char middleName[SIZE];
	cin >> middleName;

	cout << "Enter last name: ";
	char lastName[SIZE];
	cin >> lastName;

	char fullName[SIZE * 3];

	strcpy_s(fullName, SIZE * 3, lastName);
	strcat_s(fullName, SIZE * 3, ", ");
	strcat_s(fullName, SIZE * 3, firstName);
	strcat_s(fullName, SIZE * 3, " ");
	strcat_s(fullName, SIZE * 3, middleName);

	cout << "Result: " << fullName << endl;

	return 0;
}