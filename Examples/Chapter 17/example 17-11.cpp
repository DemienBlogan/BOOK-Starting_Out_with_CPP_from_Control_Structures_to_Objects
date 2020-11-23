// This program demonstrates an iterator with a map.
#include <iostream>
#include <string>
#include <map>
using namespace std;

int main()
{
	// Create a map containing employee IDs and names.
	map<int, string> employees =
	{ { 101, "Chris Jones" },   { 102, "Jessica Smith" },
	  { 103, "Amanda Stevens"}, { 104, "Will Osborn" } };

	// Create an iterator.
	map<int, string>::iterator iter;

	// Use the iterator to display each element in the map.
	for (iter = employees.begin(); iter != employees.end(); iter++)
	{
		cout << "ID: " << iter->first
			<< "\tName: " << iter->second << endl;
	}

	return 0;
}