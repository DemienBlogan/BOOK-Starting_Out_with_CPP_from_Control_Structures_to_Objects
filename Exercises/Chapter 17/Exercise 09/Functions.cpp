#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include "GasPrice.h"
#include "Functions.h"

std::string ReadFromFile(const std::string& filename)
{
	std::ifstream file{ filename };
	std::string text;
	char ch;

	while (file.get(ch))
		text.push_back(ch);

	file.close();

	return text;
}

std::vector<std::string> GetLines(const std::string& text)
{
	std::stringstream stringStream{ text };
	std::vector<std::string> lines;
	std::string line;

	while (std::getline(stringStream, line))
		lines.push_back(line);

	return lines;
}

std::vector<GasPrice> GetGasPrices(const std::string& text)
{
	std::vector<std::string> lines = GetLines(text);
	std::vector<GasPrice> gasPrices;
	std::string nextNumberInString;
	std::stringstream converter;

	for (const auto& line : lines)
	{
		Date date;
		double price;

		// Read month
		nextNumberInString.clear();
		nextNumberInString.push_back(line[0]);
		nextNumberInString.push_back(line[1]);
		converter.clear();
		converter.str(nextNumberInString);
		converter >> date.month;

		// Read day
		nextNumberInString.clear();
		nextNumberInString.push_back(line[3]);
		nextNumberInString.push_back(line[4]);
		converter.clear();
		converter.str(nextNumberInString);
		converter >> date.day;

		// Read year
		nextNumberInString.clear();
		nextNumberInString.push_back(line[6]);
		nextNumberInString.push_back(line[7]);
		nextNumberInString.push_back(line[8]);
		nextNumberInString.push_back(line[9]);
		converter.clear();
		converter.str(nextNumberInString);
		converter >> date.year;

		// Read Price
		converter.clear();
		converter.str(line);
		converter.seekg(11);
		converter >> price;

		// Create GasPrice object and put into vector
		GasPrice gasPrice{ date, price };
		gasPrices.push_back(gasPrice);
	}

	return gasPrices;
}

std::vector<std::pair<int, double>> GetAveragePricesPerYear(const std::vector<GasPrice>& gasPrices)
{
	std::vector<std::pair<int, double>> averagePrices;

	int year = gasPrices[0].GetDateYear();
	double sumYearPrices = 0.00;
	int pricesPerYearAmount = 0;
	double averageYearPrice;

	for (const auto& gasPrice : gasPrices)
	{
		if (gasPrice.GetDateYear() != year)
		{
			if (pricesPerYearAmount == 0)
				averageYearPrice = 0.00;
			else
				averageYearPrice = sumYearPrices / pricesPerYearAmount;

			averagePrices.push_back(std::make_pair(year, averageYearPrice));

			year = gasPrice.GetDateYear();
			sumYearPrices = pricesPerYearAmount = 0;
		}
		else
		{
			sumYearPrices += gasPrice.GetPrice();
			pricesPerYearAmount++;
		}
	}

	return averagePrices;
}

std::vector<std::tuple<int, int, double>> GetAveragePricesPerMonth(const std::vector<GasPrice>& gasPrices)
{
	std::vector<std::tuple<int, int, double>> averagePrices;

	int year = gasPrices[0].GetDateYear();
	int month = gasPrices[0].GetDateMonth();
	double sumMonthPrices = 0.00;
	int pricesPerMonthAmount = 0;
	double averageMonthPrice;

	for (const auto& gasPrice : gasPrices)
	{
		if (gasPrice.GetDateYear() != year)
			year = gasPrice.GetDateYear();

		if (gasPrice.GetDateMonth() != month)
		{
			if (pricesPerMonthAmount == 0)
				averageMonthPrice = 0.00;
			else
				averageMonthPrice = sumMonthPrices / pricesPerMonthAmount;

			averagePrices.push_back(std::make_tuple(year, month, averageMonthPrice));

			month = gasPrice.GetDateMonth();
			sumMonthPrices = pricesPerMonthAmount = 0;
		}
		else
		{
			sumMonthPrices += gasPrice.GetPrice();
			pricesPerMonthAmount++;
		}
	}

	return averagePrices;
}

std::vector<std::pair<int, double>> GetHighestPricesPerYear(const std::vector<GasPrice>& gasPrices)
{
	std::vector<std::pair<int, double>> averagePrices;

	int year = gasPrices[0].GetDateYear();
	double sumYearPrices = 0.00;
	double maxPrice = gasPrices[0].GetPrice();

	for (const auto& gasPrice : gasPrices)
	{
		if (gasPrice.GetDateYear() != year)
		{
			averagePrices.push_back(std::make_pair(year, maxPrice));

			year = gasPrice.GetDateYear();
			maxPrice = gasPrice.GetPrice();
		}
		else if (maxPrice < gasPrice.GetPrice())
			maxPrice = gasPrice.GetPrice();
	}

	return averagePrices;
}

std::vector<std::pair<int, double>> GetLowestPricesPerYear(const std::vector<GasPrice>& gasPrices)
{
	std::vector<std::pair<int, double>> averagePrices;

	int year = gasPrices[0].GetDateYear();
	double sumYearPrices = 0.00;
	double minPrice = gasPrices[0].GetPrice();

	for (const auto& gasPrice : gasPrices)
	{
		if (gasPrice.GetDateYear() != year)
		{
			averagePrices.push_back(std::make_pair(year, minPrice));

			year = gasPrice.GetDateYear();
			minPrice = gasPrice.GetPrice();
		}
		else if (minPrice > gasPrice.GetPrice())
			minPrice = gasPrice.GetPrice();
	}

	return averagePrices;
}

void Sort(std::vector<GasPrice>& gasPrices, bool(*predicate)(const GasPrice& element1, const GasPrice& element2))
{
	std::sort(gasPrices.begin(), gasPrices.end(), predicate);
}

void WriteToFile(const std::string& filename, const std::vector<GasPrice>& gasPrices)
{
	std::ofstream file{ filename };

	for (size_t i = 0; i < gasPrices.size(); i++)
	{
		std::string dateLine = std::to_string(gasPrices[i].GetDateDay()) + "/";
		dateLine += std::to_string(gasPrices[i].GetDateMonth()) + "/";
		dateLine += std::to_string(gasPrices[i].GetDateYear());

		file << "Date: " << std::setw(10) << dateLine << " - Price: $" << gasPrices[i].GetPrice() << std::endl;
	}

	file.close();
}