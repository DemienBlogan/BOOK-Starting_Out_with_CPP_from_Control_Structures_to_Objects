/*
14. Student Line Up
A teacher has asked all her students to line up according to their first name. For example,
in one class Amy will be at the front of the line, and Yolanda will be at the end.
Write a program that prompts the user to enter the number of students in the class,
then loops to read that many names. Once all the names have been read, it reports
which student would be at the front of the line and which one would be at the end of
the line. You may assume that no two students have the same name.

Input Validation: Do not accept a number less than 1 or greater than 25 fro the number
of students.
*/

#include <iostream>
#include <string>

int main()
{
	using namespace std;

	cout << "Enter the number of students in the class (1...25): ";
	int students;
	cin >> students;

	if (students < 1 || students > 25)
	{
		cout << "Incorrect number of students.\n";
		return 0;
	}

	string name, frontName, endName;

	for (int student = 1; student <= students; student++)
	{
		cout << "Student #" << student << ", enter your name: ";
		cin >> name;

		if (student == 1)
			frontName = endName = name;
		else
		{
			if (frontName > name)
				frontName = name;
			if (endName < name)
				endName = name;
		}
	}

	cout << "Front student is " << frontName << endl;
	cout << "End student is " << endName << endl;

	return 0;
}