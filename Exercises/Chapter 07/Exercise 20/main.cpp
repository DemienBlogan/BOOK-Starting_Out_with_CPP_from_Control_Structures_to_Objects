/*
20. 1994 Gas Prices
In the student sample programs for this book, you will find a text file named
1994_Weekly_Gas_Averages.txt. The file contains the average gas price for each week in the
year 1994 (There are 52 lines in the file. Line 1 contains the average price for week 1, line 2
contains the average price for week 2, and so forth). Write a program that reads the gas
prices from the file into an array or a vector. The program should do the following:

- Display the lowest average price of the year, along with the week number for that
  price, and the name of the month in which it occurred.
- Display the highest average price of the year, along with the week number for that
  price, and the name of the month in which it occurred.
- Display the average gas price for each month. (To get the average price for a given
  month, calculate the average of the average weekly prices for that month).
*/

#include <iostream>
#include <fstream>
#include <vector>

void OpenFile(std::ifstream& file, const std::string& fileName);
void CloseFile(std::ifstream& file);
void ReadGasPrices(std::vector<double>& prices, std::ifstream& file);
void FindMinValueAndWeek(const std::vector<double>& prices, double& min, int& week);
void FindMaxValueAndWeek(const std::vector<double>& prices, double& max, int& week);

int main()
{
	using namespace std;

	vector<double> prices;
	ifstream file;

	try
	{
		OpenFile(file, "1994_Weekly_Gas_Averages.txt");
		ReadGasPrices(prices, file);

		double maxPrice, minPrice;
		int maxWeek, minWeek;

		FindMinValueAndWeek(prices, minPrice, minWeek);
		FindMaxValueAndWeek(prices, maxPrice, maxWeek);

		cout << "Max price value: $" << maxPrice << " (week #" << maxWeek << ")\n";
		cout << "Min price value: $" << minPrice << " (week #" << minWeek << ")\n";

	}
	catch (const std::exception& ex)
	{
		cout << ex.what() << endl;
	}

	CloseFile(file);

	return 0;
}

void OpenFile(std::ifstream& file, const std::string& fileName)
{
	file.open(fileName);

	if (!file)
	{
		using namespace std;

		string errorMessage = "File '" + fileName + "' could not been opened.\n";
		throw std::exception(errorMessage.c_str());
	}
}

void CloseFile(std::ifstream& file)
{
	if (file.is_open())
		file.close();
}

void ReadGasPrices(std::vector<double>& answers, std::ifstream& file)
{
	if (!answers.empty())
		answers.clear();

	using namespace std;

	double price;

	while (file >> price)
		answers.push_back(price);
}

void FindMinValueAndWeek(const std::vector<double>& prices, double& min, int& week)
{
	min = prices[0];
	week = 1;

	for (size_t i = 1; i < prices.size(); i++)
	{
		if (min > prices[i])
		{
			min = prices[i];
			week = i + 1;
		}
	}
}

void FindMaxValueAndWeek(const std::vector<double>& prices, double& max, int& week)
{
	max = prices[0];
	week = 1;

	for (size_t i = 1; i < prices.size(); i++)
	{
		if (max < prices[i])
		{
			max = prices[i];
			week = i + 1;
		}
	}
}