/*
6. Rain or Shine
An amateur meteorologist wants to keep track of weather conditions during the past
year's three-month summer season, and has designated each day as either rainy ('R'),
cloudy ('C'), or sunny ('S'). Write a program that stores this information in a 3*30
array of characters, where the row indicates the month (0 = June, 1 = July, 2 = August)
and the column indicates the day of the month. Note data are not being collected for
the 31st of any month. The program should begin by reading the weather data in from
a file. Then it should create a report that displays, for each month and for the whole
three-month period, how many days were rainy, how many were cloudy, and how
many were sunny. It should also report which of the three months had the largest number
of rainy days. Data for the program can be found in the RainOrShine.txt file.
*/

#include <iostream>
#include <fstream>

int main()
{
	using namespace std;

	ifstream fin("RainOrShine.txt");
	ofstream fout("Report.txt");

	if (!fin)
	{
		cout << "File 'RainOrShine.txt' could not been found.\n";
		exit(0);
	}

	if (!fout)
	{
		cout << "File 'Report.txt' could not been created.\n";
		exit(0);
	}

	const size_t MONTHS = 3, DAYS = 30;
	char rainOrShine[MONTHS][DAYS];

	for (size_t i = 0; i < MONTHS; i++)
		for (size_t j = 0; j < DAYS; j++)
			fin >> rainOrShine[i][j];


	int rainy = 0, cloudy = 0, sunny = 0;
	int maxRainyMonthIndex = 0;
	int minRainyMonthIndex = 0;
	int monthRainy, monthCloudy, monthSunny;
	int maxMonthRainy = 0;
	int minMonthRainy = 1000;

	for (size_t i = 0; i < MONTHS; i++)
	{
		monthRainy = 0;
		monthCloudy = 0;
		monthSunny = 0;

		for (size_t j = 0; j < DAYS; j++)
		{
			if (rainOrShine[i][j] == 'R')
			{
				rainy++;
				monthRainy++;
			}

			if (rainOrShine[i][j] == 'C')
			{
				cloudy++;
				monthCloudy++;
			}

			if (rainOrShine[i][j] == 'S')
			{
				sunny++;
				monthSunny++;
			}
		}

		if (maxMonthRainy < monthRainy)
		{
			maxMonthRainy = monthRainy;
			maxRainyMonthIndex = i;
		}

		if (minMonthRainy > monthRainy)
		{
			minMonthRainy = monthRainy;
			minRainyMonthIndex = i;
		}

		switch (i)
		{
		case 0:
			fout << "June:\n";
			break;
		case 1:
			fout << "July:\n";
			break;
		case 2:
			fout << "August:\n";
			break;
		}

		fout << "\tRainy days:  " << monthRainy << endl;
		fout << "\tCloudy days: " << monthCloudy << endl;
		fout << "\tSunny days:  " << monthSunny << endl;
	}

	fout << "\nMonth with largest rainy days: ";
	switch (maxRainyMonthIndex)
	{
	case 0:
		fout << "June\n";
		break;
	case 1:
		fout << "July\n";
		break;
	case 2:
		fout << "August\n";
		break;
	}

	fout << "\nMonth with smallest rainy days: ";
	switch (minRainyMonthIndex)
	{
	case 0:
		fout << "June\n";
		break;
	case 1:
		fout << "July\n";
		break;
	case 2:
		fout << "August\n";
		break;
	}

	fout << "\nTotal rainy days:  " << rainy << endl;
	fout << "Total cloudy days: " << cloudy << endl;
	fout << "Total sunny days:  " << sunny << endl;

	fin.close();
	fout.close();

	return 0;
}