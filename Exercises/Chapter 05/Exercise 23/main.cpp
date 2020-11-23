/*
23. Pattern Displays
Write a program that uses a loop to display Pattern A below, followed by another loop
that display Pattern B.

----------------------------------
Pattern A             Pattern B
----------------------------------
+                     ++++++++++++
++                    +++++++++++
+++                   ++++++++++
++++                  +++++++++
+++++                 ++++++++
++++++                +++++++
+++++++               ++++++
++++++++              +++++
+++++++++             ++++
++++++++++            +++
+++++++++++           ++
++++++++++++          +
*/

#include <iostream>

int main()
{
	using namespace std;

	int height = 10;

	// Pattern A
	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j <= i; j++)
			cout << '+';
		cout << endl;
	}

	cout << endl;

	// Pattern B
	for (int i = 0; i < height; i++)
	{
		for (int j = height; j > i; j--)
			cout << '+';
		cout << endl;
	}
	return 0;
}