/*
18. Population Bar Chart
Write a program that produces a bar chart showing the population growth of Prairieville,
a small town in the Midwest, at 20-year intervals during the past 100 years. The program
should read in the population figures (rounded to the nearest 1,000 people) for 1900,
1920, 1940, 1960, 1980, and 200 from a file. For each year, it should display the date 
and a bar consisting of one asterisk for each 1,000 people. The data can be found in the
People.txt file.
*/

#include <iostream>
#include <fstream>

int main()
{
	using namespace std;

	ifstream file("People.txt");

	if (!file)
	{
		cout << "File 'People.txt' could not been found.\n";
		return 1;
	}

	int population;

	cout << "PRAIRIVILLE POPULATION GROTH\n";
	cout << "(each * represents 1,000 people)\n";

	for (int year = 1900; file >> population && year <= 2000; year += 20)
	{
		cout << year << " ";
		int asterisks = population / 1000;
		for (int i = 0; i < asterisks; i++)
			cout << '*';
		cout << endl;
	}

	file.close();

	return 0;
}