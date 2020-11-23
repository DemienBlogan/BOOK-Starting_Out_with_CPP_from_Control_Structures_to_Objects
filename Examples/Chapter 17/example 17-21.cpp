#include <iostream>
#include <string>
#include <map>
using namespace std;

int main()
{
	// Define a phonebook multimap.
	multimap<string, string> phonebook =
	{ { "Will", "555-1212" }, { "Will", "555-0123" },
	  { "Faye", "555-07-07" }, { "Faye", "555-1234" },
	  { "Sarah", "555-8787" }, { "Sarah", "555-5678" } };

	// Defaine a pair variable to receive the object that
	// is returned from the equal_range member function.
	pair<multimap<string, string>::iterator,
		 multimap<string, string>::iterator> range;

	// Define an iterator for the multimap.
	multimap<string, string>::iterator iter;

	// Get the range of elements that match "Faye".
	range = phonebook.equal_range("Faye");

	// Display all of the elements that match "Faye".
	for (iter = range.first; iter != range.second; iter++)
	{
		cout << iter->first << "\t" << iter->second << endl;
	}

	return 0;
}