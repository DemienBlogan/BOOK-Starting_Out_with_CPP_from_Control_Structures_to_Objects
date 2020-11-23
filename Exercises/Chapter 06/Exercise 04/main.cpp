/*
4. Safest Driving Area
Write a program that determines which of five geographic regions within a mojor city
(north, south, east, west, and central) had the fewest reported automobile accidents last
year. It should have the following two functions, which are called by main:

- int getNumAccidents() is passed the name of a region. It asks the user for the
  number of automobile accidents reported in that region during the last year, validates
  the input, then returns it. It should be called once for each city region.
- void findLowest() is passed the five accident totals. It determines which is the
  smallest and prints the name of the region, along with its accident figure.

Input Validation: Do not accept an accident number that is less than 0.
*/

#include <iostream>
#include <string>

int getNumAccidents(const std::string& regionName);
void findLowest(int accidents1, int accidents2, int accidents3, int accidents4, int accidents5);

int main()
{
	int accidents1, accidents2, accidents3, accidents4, accidents5;

	accidents1 = getNumAccidents("north");
	accidents2 = getNumAccidents("south");
	accidents3 = getNumAccidents("east");
	accidents4 = getNumAccidents("west");
	accidents5 = getNumAccidents("cental");

	findLowest(accidents1, accidents2, accidents3, accidents4, accidents5);

	return 0;
}

int getNumAccidents(const std::string& regionName)
{
	using namespace std;

	cout << "Enter the amount of accident of " << regionName << " region: ";
	int accidents;
	cin >> accidents;

	if (accidents < 0)
	{
		cout << "Incorrect number of accidents.\n";
		exit(0);
	}

	return accidents;
}

void findLowest(int accidents1, int accidents2, int accidents3, int accidents4, int accidents5)
{
	using namespace std;

	int lowestAccidents = accidents1 < accidents2 ? accidents1 : accidents2;
	lowestAccidents = lowestAccidents < accidents3 ? lowestAccidents : accidents3;
	lowestAccidents = lowestAccidents < accidents4 ? lowestAccidents : accidents4;
	lowestAccidents = lowestAccidents < accidents5 ? lowestAccidents : accidents5;

	if (lowestAccidents == accidents1)
		cout << "The lowest number of accidents in north region.\n";
	else if (lowestAccidents == accidents2)
		cout << "The lowest number of accidents in south region.\n";
	else if (lowestAccidents == accidents3)
		cout << "The lowest number of accidents in east region.\n";
	else if (lowestAccidents == accidents4)
		cout << "The lowest number of accidents in west region.\n";
	else
		cout << "The lowest number of accidents in central region.\n";
}