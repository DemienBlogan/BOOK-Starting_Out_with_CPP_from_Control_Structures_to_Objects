/*
12. Password Verifier
Imagine you are developing a software package that requires users to enter their own
passwords. Your software requires that users' passwords meet the following criteria:

- The password should be at least six characters long.
- The password should contain at least one uppercase and at least one lowercase letter.
- The password should have at least one digit.

Write a program that asks  for a password then verifies that it meets the stated criteria.
If it doesn't, the program should display a message telling the user why.
*/

#include <iostream>
#include <cstring>

void EnterPassword(char* password, size_t size);
bool IsLeastSixCharsLong(const char* password);
bool IsLeastOneUpper(const char* password);
bool IsLeastOneLower(const char* password);
bool IsLeastOneDigit(const char* password);

int main()
{
	using namespace std;

	const size_t SIZE = 20;
	char password[SIZE];

	EnterPassword(password, SIZE);

	if (!IsLeastSixCharsLong(password))
		cout << "Your password doesn't have six at least six charactes long.\n";
	else if (!IsLeastOneDigit(password))
		cout << "Your password must have at least one digit.\n";
	else if (!IsLeastOneLower(password))
		cout << "Your password must have at least one lowercase digit.\n";
	else if (!IsLeastOneUpper(password))
		cout << "Your password must have at least one uppercase digit.\n";
	else
		cout << "Valid password.\n";

	return 0;
}

void EnterPassword(char* password, size_t size)
{
	using namespace std;

	cout << "Enter a password: ";
	cin.getline(password, size);
}

bool IsLeastSixCharsLong(const char* password)
{
	return strlen(password) >= 6 ? true : false;
}

bool IsLeastOneUpper(const char* password)
{
	size_t size = strlen(password);
	for (size_t i = 0; i < size; i++)
		if (isupper(password[i]))
			return true;

	return false;
}

bool IsLeastOneLower(const char* password)
{
	size_t size = strlen(password);
	for (size_t i = 0; i < size; i++)
		if (islower(password[i]))
			return true;

	return false;
}

bool IsLeastOneDigit(const char* password)
{
	size_t size = strlen(password);
	for (size_t i = 0; i < size; i++)
		if (isdigit(password[i]))
			return true;

	return false;
}