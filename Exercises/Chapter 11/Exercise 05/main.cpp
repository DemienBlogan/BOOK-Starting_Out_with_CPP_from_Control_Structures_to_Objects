/*
5. Weather Statistics Modification
Modify the program that you wrote for Programming Challenge 4 (weather statistics)
so it defines an enumerated data type with enumerators for the months (JANUARY,
FEBRUARY, so on). The program should use the enumerated type to step through the
elements of the array.
*/

#include <iostream>

using namespace std;

enum Month
{
	JANUARY,
	FEBRUARY,
	MARCH,
	APRIL,
	MAY,
	JUNE,
	JULY,
	AUGUST,
	SEPTEMBER,
	OCTOBER,
	NOVEMBER,
	DECEMBER
};


struct MonthWeatherStatistic
{
	double totalRainfall;
	double highTemperature;
	double lowTemperature;
	double averageTemperature;
};

void EnterStatistics(MonthWeatherStatistic statistics[]);
void EnterStatistic(MonthWeatherStatistic& statistic);
double EnterTemperature();
double CalculateAverageMonthlyRainfall(double totalRainfall);
double CalculateTotalRainfall(const MonthWeatherStatistic statistics[]);
double FindHighestTemperature(const MonthWeatherStatistic statistics[]);
double FindLowestTemperature(const MonthWeatherStatistic statistics[]);
size_t FindMonthWithHighestTemperature(const MonthWeatherStatistic statistics[], double highestTemperature);
size_t FindMonthWithLowestTemperature(const MonthWeatherStatistic statistics[], double lowestTemperature);
double CalculateAverageOfMonthlyAverageTemperatures(const MonthWeatherStatistic statistics[]);
void ShowInformation(
	double totalRainfall,
	double averageMonthlyRainfall,
	double highestTemperature,
	double lowestTemperature,
	size_t monthWithHighestTemperature,
	size_t monthWithLowestTemperauture,
	double averageOfMonthlyAverageTemperatures);

int main()
{
	const size_t MONTHS = 12;
	MonthWeatherStatistic statistics[MONTHS];

	EnterStatistics(statistics);

	double totalRainfall = CalculateTotalRainfall(statistics);
	double averageMonthlyRainfall = CalculateAverageMonthlyRainfall(totalRainfall);
	double highestTemperature = FindHighestTemperature(statistics);
	double lowestTemperature = FindLowestTemperature(statistics);
	size_t monthWithHighestTemperature = FindMonthWithHighestTemperature(statistics, highestTemperature);
	size_t monthWithLowestTemperauture = FindMonthWithLowestTemperature(statistics, highestTemperature);
	double averageOfMonthlyAverageTemperatures = CalculateAverageOfMonthlyAverageTemperatures(statistics);

	ShowInformation(totalRainfall, averageMonthlyRainfall, highestTemperature, lowestTemperature, monthWithHighestTemperature,
		monthWithLowestTemperauture, averageOfMonthlyAverageTemperatures);

	return 0;
}

void EnterStatistics(MonthWeatherStatistic statistics[])
{
	for (Month month = JANUARY; month <= DECEMBER; month = static_cast<Month>(month + 1))
	{
		cout << "Month #" << month + 1 << ":\n";
		EnterStatistic(statistics[month]);
	}
}

void EnterStatistic(MonthWeatherStatistic& statistic)
{
	cout << "\tEnter total rainfall: ";
	cin >> statistic.totalRainfall;

	cout << "\tEnter high temperature: ";
	statistic.highTemperature = EnterTemperature();

	cout << "\tEnter low temperature: ";
	statistic.lowTemperature = EnterTemperature();

	statistic.averageTemperature = (statistic.highTemperature + statistic.lowTemperature) / 2.0;
}

double EnterTemperature()
{
	double minTemperatureF = -100, maxTemperatureF = +140;
	double temperature;

	do
	{
		cin >> temperature;

		if (temperature < minTemperatureF || temperature > maxTemperatureF)
		{
			cout << "Incorrect temperature. Enter in the range ";
			cout << minTemperatureF << " ... " << showpoint << maxTemperatureF << endl;
		}

	} while (temperature < minTemperatureF || temperature > maxTemperatureF);

	return temperature;
}

double CalculateAverageMonthlyRainfall(double totalRainfall)
{
	double averageMonthlyRainfall = totalRainfall / 12;
	return averageMonthlyRainfall;
}

double CalculateTotalRainfall(const MonthWeatherStatistic statistics[])
{
	double totalRainfall = 0.0;

	for (Month month = JANUARY; month <= DECEMBER; month = static_cast<Month>(month + 1))
		totalRainfall += statistics[month].totalRainfall;

	return totalRainfall;
}

double FindHighestTemperature(const MonthWeatherStatistic statistics[])
{
	double highestTemperature = statistics[0].highTemperature;

	for (Month month = JANUARY; month <= DECEMBER; month = static_cast<Month>(month + 1))
		if (highestTemperature < statistics[month].highTemperature)
			highestTemperature = statistics[month].highTemperature;

	return highestTemperature;
}

double FindLowestTemperature(const MonthWeatherStatistic statistics[])
{
	double lowestTemperature = statistics[0].lowTemperature;

	for (Month month = JANUARY; month <= DECEMBER; month = static_cast<Month>(month + 1))
		if (lowestTemperature > statistics[month].lowTemperature)
			lowestTemperature = statistics[month].lowTemperature;

	return lowestTemperature;
}

size_t FindMonthWithHighestTemperature(const MonthWeatherStatistic statistics[], double highestTemperature)
{
	for (Month month = JANUARY; month <= DECEMBER; month = static_cast<Month>(month + 1))
		if (statistics[month].highTemperature == highestTemperature)
			return month;

	return 0;
}

size_t FindMonthWithLowestTemperature(const MonthWeatherStatistic statistics[], double lowestTemperature)
{
	for (Month month = JANUARY; month <= DECEMBER; month = static_cast<Month>(month + 1))
		if (statistics[month].lowTemperature == lowestTemperature)
			return month;

	return JANUARY;
}

double CalculateAverageOfMonthlyAverageTemperatures(const MonthWeatherStatistic statistics[])
{
	double sumOfTotalAverageTemperatures = 0;

	for (Month month = JANUARY; month <= DECEMBER; month = static_cast<Month>(month + 1))
		sumOfTotalAverageTemperatures += (statistics[month].lowTemperature + statistics[month].highTemperature) / 2.0;

	double averageOfMonthlyAverageTemperatures = sumOfTotalAverageTemperatures / 12;
	return averageOfMonthlyAverageTemperatures;
}

void ShowInformation(
	double totalRainfall,
	double averageMonthlyRainfall,
	double highestTemperature,
	double lowestTemperature,
	size_t monthWithHighestTemperature,
	size_t monthWithLowestTemperauture,
	double averageOfMonthlyAverageTemperatures)
{
	cout << "--------- INFORMATION ABOUT WEATHER ---------\n";
	cout << "Total rainfall: " << totalRainfall << endl;
	cout << "Average monthly rainfall: " << averageMonthlyRainfall << endl;
	cout << "The highest temperature: " << highestTemperature << " (month #" << monthWithHighestTemperature + 1 << ")\n";
	cout << "The lowest temperature: " << lowestTemperature << " (month #" << monthWithLowestTemperauture + 1 << ")\n";
	cout << "Average of monthly average temperatures: " << averageOfMonthlyAverageTemperatures << endl;
}