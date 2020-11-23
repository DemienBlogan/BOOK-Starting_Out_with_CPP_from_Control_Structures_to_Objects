/*
3. Capital Quiz
Write a program that creates a map containing the U.S. states as keys, and their capitals
as values. (Use the Internet to get a list of the states and their capitals). The program
should then randomly quiz the user by displaying the name of a state and ask the user
to enter that state's capital. The program should keep a count of the number of correct
and incorrect responses. (As an alternative to the U.S. states, the program can use the
names of countries and their capitals).
*/

#include <iostream>
#include <map>
#include <string>
#include <cstdlib>
#include <ctime>

int main()
{
	using std::map;
	using std::string;
	using std::make_pair;
	using std::getline;
	using std::endl;
	using std::cout;
	using std::cin;

	srand(static_cast<unsigned>(time(nullptr)));

	map<string, string> statesCapitals =
	{
		make_pair("Alabama", "Montgomery"),
		make_pair("Alaska", "Juneau"),
		make_pair("Arizona", "Phoenix"),
		make_pair("Arkansas", "Little Rock"),
		make_pair("California", "Sacramento"),
		make_pair("Colorado", "Denver"),
		make_pair("Connecticut", "Hartford"),
		make_pair("Delaware", "Dover"),
		make_pair("Florida", "Tallahassee"),
		make_pair("Georgia", "Atlanta"),

		make_pair("Hawaii", "Honolulu"),
		make_pair("Idaho", "Boise"),
		make_pair("Illinois", "Springfield"),
		make_pair("Indiana", "Indianapolis"),
		make_pair("Iowa", "Des Moines"),
		make_pair("Kansas", "Topeka"),
		make_pair("Kentucky", "Frankfort"),
		make_pair("Louisiana", "Baton Rouge"),
		make_pair("Maine", "Augusta"),
		make_pair("Maryland", "Annapolis"),

		make_pair("Massachusetts", "Boston"),
		make_pair("Michigan", "Lansing"),
		make_pair("Minnesota", "Saint Paul"),
		make_pair("Mississippi", "Jackson"),
		make_pair("Missouri", "Jefferson City"),
		make_pair("Montana", "Helena"),
		make_pair("Nebraska", "Lincoln"),
		make_pair("Nevada", "Carson City"),
		make_pair("New Hampshire", "Concord"),
		make_pair("New Jersey", "Trenton"),

		make_pair("New Mexico", "Santa Fe"),
		make_pair("New York", "Albany"),
		make_pair("North Carolina", "Raleigh"),
		make_pair("North Dakota", "Bismarck"),
		make_pair("Ohio", "Columbus"),
		make_pair("Oklahoma", "Oklahoma City"),
		make_pair("Oregon", "Salem"),
		make_pair("Pennsylvania", "Harrisburg"),
		make_pair("Rhode Island", "Providence"),
		make_pair("South Carolina", "Columbia"),

		make_pair("South Dakota", "Pierre"),
		make_pair("Tennessee", "Nashville"),
		make_pair("Texas", "Austin"),
		make_pair("Utah", "Salt Lake City"),
		make_pair("Vermont", "Montpelier"),
		make_pair("Virginia", "Richmond"),
		make_pair("Washington", "Olympia"),
		make_pair("West Virginia", "Charleston"),
		make_pair("Wisconsin", "Madison"),
		make_pair("Wyoming", "Cheyenne")
	};

	const int STATES_AMOUNT = 50;
	int stateNumber = rand() % STATES_AMOUNT;

	string state, capital;

	auto it = statesCapitals.cbegin();
	for (size_t i = 0; i < STATES_AMOUNT && it != statesCapitals.cend(); i++, ++it)
	{
		if (i == stateNumber)
		{
			state = it->first;
			capital = it->second;
			break;
		}
	}

	cout << "Your state is: " << state << ". Enter capital: ";
	string userCapital;
	getline(cin, userCapital);

	if (userCapital == capital)
		cout << "You guessed!\n";
	else
		cout << "You didn't guess. The capital is " << capital << endl;

	return 0;
}