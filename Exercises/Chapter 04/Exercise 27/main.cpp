/*
27. Wi-Fi Diagnostic Tree
Figure shows a simplified flowchart for troubleshooting a bad Wi-Fi connection.
Use the flowchart to create a program that leads a person through the steps of fixing a
bad Wi-Fi connection. 
*/

#include <iostream>
#include <string>

int main()
{
	using namespace std;

	string answer;

	cout << "Reboot the computer and try to connect.\n";
	cout << "Did that fix the problem? ";
	cin >> answer;

	if (answer == "yes")
		cout << "That's good, goodbye!\n";
	else
	{
		cout << "Reboot the router and try to connect.\n";
		cout << "Did that fix the problem? ";
		cin >> answer;

		if (answer == "yes")
			cout << "That's good, goodbye!\n";
		else
		{
			cout << "Make sure the cables between the router and modem are plugged in firmly.\n";
			cout << "Did that fix the problem? ";
			cin >> answer;

			if (answer == "yes")
				cout << "That's good, goodbye!\n";
			else
			{
				cout << "Move the router to a new location and try to connect.\n";
				cout << "Did that fix the problem? ";
				cin >> answer;

				if (answer == "yes")
					cout << "That's good, goodbye!\n";
				else
					cout << "Get a new router.\n";
			}
		}
	}

	return 0;
}