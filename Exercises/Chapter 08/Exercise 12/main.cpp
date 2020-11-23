/*
12. Sorted List of 1994 Gas Prices
In the student sample programs for this book, you will find a test file named
1994_Weekly_Gas_Averages.txt. The file contains the average gas price for each week in the
year 1994. (There are 52 lines in the file. Line 1 contains the average price for week 1;
line 2 contains the average price for week 2, and so forth). Write a program that reads
the gas prices from the file, and calculates the average gas price for each month. (To get
the average price for a given month, calculate the average of the average weekly prices
for that month). Then, the program should create another file that lists the names of
the months, along with each month's average gas price, sorted from lowest to highest.
*/

#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using std::ifstream;
using std::ofstream;
using std::vector;
using std::string;
using std::cerr;
using std::swap;
using std::endl;

int main()
{
	// Open file:
	string filename1{ "1994_Weekly_Gas_Averages.txt" };
	ifstream fin{ filename1 };

	if (!fin)
	{
		cerr << "File '" << filename1 << "' could not been opened.\n";
		return 1;
	}

	// Read month numbers and weekly averages from file:
	vector<double> weeklyAverages;
	vector<int> weeklyRelationsToMonths;

	double nextAverage;
	int nextWeeklyRelationToMonth;

	while (fin >> nextWeeklyRelationToMonth && fin >> nextAverage)
	{
		weeklyRelationsToMonths.push_back(nextWeeklyRelationToMonth);
		weeklyAverages.push_back(nextAverage);
	}

	fin.close();

	// Calculate month averages:
	const int MONTHS_IN_YEAR = 12;
	int week = 0;
	vector<double> monthAverages;

	for (int month = 1; month <= MONTHS_IN_YEAR; month++)
	{
		double sumMonthGasPrices = 0.0;
		int weeksInMonth = 0;

		for (int week = 0; week < weeklyRelationsToMonths.size(); week++)
		{
			if (weeklyRelationsToMonths[week] == month)
			{
				sumMonthGasPrices += weeklyAverages[week];
				weeksInMonth++;
			}
		}

		double monthAverage = sumMonthGasPrices / weeksInMonth;

		monthAverages.push_back(monthAverage);
	}
	
	// Sort month averages and month names using Selection Sort:
	vector<string> monthNames =
	{
		"January", "February", "March", "April",
		"May", "June", "July", "August",
		"September", "October", "November", "December"
	};

	for (size_t i = 0; i < monthAverages.size() - 1; i++)
	{
		for (size_t j = i + 1; j < monthAverages.size(); j++)
		{
			if (monthAverages[i] > monthAverages[j])
			{
				swap(monthAverages[i], monthAverages[j]);
				swap(monthNames[i], monthNames[j]);
			}
		}
	}

	// Write month averages and month names in file:
	string filename2{ "Month Averages.txt" };
	ofstream fout{ filename2 };

	if (!fout)
	{
		cerr << "File '" << filename2 << "' could not been created.\n";
		return 1;
	}

	fout << "--- Month Averages (sorted) --- \n";
	for (size_t i = 0; i < monthAverages.size(); i++)
		fout << monthNames[i] << ": " << monthAverages[i] << endl;

	fout.close();

	return 0;
}