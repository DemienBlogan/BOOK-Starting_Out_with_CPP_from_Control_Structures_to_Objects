/*
4. Weather Statistics
Write a program that uses a stucture to store the following weather data for a
particular month:
	Total Rainfall
	High Temperature
	Low Temperature
	Average Temperature
The program should have an array of 12 structures to hold weather data for an entire
year. When the program runs, it should ask the user to enter data for each month.
(The average temperautre should be calculated). Once the data are entered for all the
months, the program should calculate and display the average monthly rainfall, the
total rainfall for the year, the highest and lowest temperatures for the year (and the
months they occurred in), and the average of all the monthly average temperatures.

Input Validation: Only accept temperatures within the range between -100 and +140
degrees Fahrenheit.
*/

#include <iostream>

using namespace std;

struct MonthWeatherStatistic
{
	double totalRainfall;
	double highTemperature;
	double lowTemperature;
	double averageTemperature;
};

void EnterStatistics(MonthWeatherStatistic statistics[], size_t months);
void EnterStatistic(MonthWeatherStatistic& statistic);
double EnterTemperature();
double CalculateAverageMonthlyRainfall(double totalRainfall, size_t months);
double CalculateTotalRainfall(const MonthWeatherStatistic statistics[], size_t months);
double FindHighestTemperature(const MonthWeatherStatistic statistics[], size_t months);
double FindLowestTemperature(const MonthWeatherStatistic statistics[], size_t months);
size_t FindMonthWithHighestTemperature(const MonthWeatherStatistic statistics[], size_t months, double highestTemperature);
size_t FindMonthWithLowestTemperature(const MonthWeatherStatistic statistics[], size_t months, double lowestTemperature);
double CalculateAverageOfMonthlyAverageTemperatures(const MonthWeatherStatistic statistics[], size_t months);
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

	EnterStatistics(statistics, MONTHS);

	double totalRainfall = CalculateTotalRainfall(statistics, MONTHS);
	double averageMonthlyRainfall = CalculateAverageMonthlyRainfall(totalRainfall, MONTHS);
	double highestTemperature = FindHighestTemperature(statistics, MONTHS);
	double lowestTemperature = FindLowestTemperature(statistics, MONTHS);
	size_t monthWithHighestTemperature = FindMonthWithHighestTemperature(statistics, MONTHS, highestTemperature);
	size_t monthWithLowestTemperauture = FindMonthWithLowestTemperature(statistics, MONTHS, highestTemperature);
	double averageOfMonthlyAverageTemperatures = CalculateAverageOfMonthlyAverageTemperatures(statistics, MONTHS);

	ShowInformation(totalRainfall, averageMonthlyRainfall, highestTemperature, lowestTemperature, monthWithHighestTemperature,
		monthWithLowestTemperauture, averageOfMonthlyAverageTemperatures);

	return 0;
}

void EnterStatistics(MonthWeatherStatistic statistics[], size_t months)
{
	for (size_t i = 0; i < months; i++)
	{
		cout << "Month #" << i + 1 << ":\n";
		EnterStatistic(statistics[i]);
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

double CalculateAverageMonthlyRainfall(double totalRainfall, size_t months)
{
	double averageMonthlyRainfall = totalRainfall / months;
	return averageMonthlyRainfall;
}

double CalculateTotalRainfall(const MonthWeatherStatistic statistics[], size_t months)
{
	double totalRainfall = 0.0;

	for (size_t i = 0; i < months; i++)
		totalRainfall += statistics[i].totalRainfall;

	return totalRainfall;
}

double FindHighestTemperature(const MonthWeatherStatistic statistics[], size_t months)
{
	double highestTemperature = statistics[0].highTemperature;

	for (size_t i = 1; i < months; i++)
		if (highestTemperature < statistics[i].highTemperature)
			highestTemperature = statistics[i].highTemperature;

	return highestTemperature;
}

double FindLowestTemperature(const MonthWeatherStatistic statistics[], size_t months)
{
	double lowestTemperature = statistics[0].lowTemperature;

	for (size_t i = 1; i < months; i++)
		if (lowestTemperature > statistics[i].lowTemperature)
			lowestTemperature = statistics[i].lowTemperature;

	return lowestTemperature;
}

size_t FindMonthWithHighestTemperature(const MonthWeatherStatistic statistics[], size_t months, double highestTemperature)
{
	for (size_t i = 0; i < months; i++)
		if (statistics[i].highTemperature == highestTemperature)
			return i;

	return 0;
}

size_t FindMonthWithLowestTemperature(const MonthWeatherStatistic statistics[], size_t months, double lowestTemperature)
{
	for (size_t i = 0; i < months; i++)
		if (statistics[i].lowTemperature == lowestTemperature)
			return i;

	return 0;
}

double CalculateAverageOfMonthlyAverageTemperatures(const MonthWeatherStatistic statistics[], size_t months)
{
	double sumOfTotalAverageTemperatures = 0;

	for (size_t i = 0; i < months; i++)
		sumOfTotalAverageTemperatures += (statistics[i].lowTemperature + statistics[i].highTemperature) / 2.0;

	double averageOfMonthlyAverageTemperatures = sumOfTotalAverageTemperatures / months;
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