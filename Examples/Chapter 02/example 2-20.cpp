// This program can't fine its variable.
#include <iostream>
using namespace std;

int main()
{
	cout << value; // ERROR! value not defined yet!

	int value = 100;
	return 0;
}