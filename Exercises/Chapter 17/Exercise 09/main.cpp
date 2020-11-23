/*
09. Gas Prices
In the student sample program files for this chapter, you will find a text file named
GasPrices.txt. The file contains the weekly average prices for a gallon of gas in the U.S.,
beginning on April 5, 1993, and ending on August 26, 2013. Figure 17-10 shows an
example of the first few lines of the file's contents.

Each line in the file contains the average price for a gallon of gas on a specific date.
Each line is formatted in the following way:

MM-DD-YYYY: Price

MM is the two-digit month, DD is the two-digit day, and YYYY is the four-digit year.
Price is the average prrice per gallon of gas on the specified date.

For this assignment, you are to write one or more programs that read the contents of
the file and perform the following calculations:

Average Price Per Year: Calculate the average price of gas per year, for each year in the
file. (The file's data starts in April of 1993, and it ends in August 2013. Use the data
that is present for the years 1993 and 2013).

Average Price Per Month: Calculate the average price for each month in the file.

Highest and Lowest Prices Per Year: For each year in the file, determine the date and
amount for the lowest price, and the highest price.

List of Prices, Lowest to Highest: Generate a text file that lists the dates and prices,
sorted from the lowest price to the highest.

List of Prices, Highest to lowest: Generate a text file that lists the dates and prices,
sorted from the highest price to the lowest.

You can write one program to perform all of these calculations, or you can write different
programs, one for each calculation. Regardless of the approach that you take,
you should read the contents of the GasPrices.txt file, and extract its date into one or
more STL containers appropriate for your algorithm.

Hint: See Chapter 10 for a discussion of string tokenizing.
*/

#include <iostream>
#include <string>
#include <vector>
#include <tuple>
#include "Functions.h"
#include "GasPrice.h"

int main()
{
	std::string filename{ "GasPrices.txt" };
	std::string text = ReadFromFile(filename);
	std::vector<GasPrice> gasPrices = GetGasPrices(text);
	
#pragma region Average Price Per Year
	std::vector<std::pair<int, double>> averagePricesPerYear = GetAveragePricesPerYear(gasPrices);
	std::cout << "-------- Average Prices Per Year --------\n";
	for (const auto& yearPrice : averagePricesPerYear)
		std::cout << "Year " << yearPrice.first << ", Average price = $" << yearPrice.second << std::endl;
	system("pause");
	system("cls");
#pragma endregion
	
#pragma region Average Price Per Month
	std::vector<std::tuple<int, int, double>> averagePricesPerMonth = GetAveragePricesPerMonth(gasPrices);
	std::cout << "-------- Average Prices Per Month --------\n";
	for (const auto& yearMonthPrice : averagePricesPerMonth)
	{
		std::cout << "Year " << std::get<0>(yearMonthPrice);
		std::cout << ", Month " << std::get<1>(yearMonthPrice);
		std::cout << ", Average price = $" << std::get<2>(yearMonthPrice) << std::endl;
	}
	system("pause");
	system("cls");
#pragma endregion

#pragma region Highest And Lowest Prices Per Year
	std::vector<std::pair<int, double>> highestPricesPerYear = GetHighestPricesPerYear(gasPrices);
	std::cout << "-------- Highest Prices Per Year --------\n";
	for (const auto& yearPrice : highestPricesPerYear)
		std::cout << "Year " << yearPrice.first << ", Highest price = $" << yearPrice.second << std::endl;
	system("pause");
	system("cls");

	std::vector<std::pair<int, double>> lowestPricesPerYear = GetLowestPricesPerYear(gasPrices);
	std::cout << "-------- Lowest Prices Per Year --------\n";
	for (const auto& yearPrice : lowestPricesPerYear)
		std::cout << "Year " << yearPrice.first << ", Lowest price = $" << yearPrice.second << std::endl;
	system("pause");
	system("cls");
#pragma endregion

#pragma region List of Prices, Lowest to Highest
	auto predicate1 = [](const GasPrice& price1, const GasPrice& price2) { return price1.GetPrice() < price2.GetPrice(); };
	Sort(gasPrices, predicate1);
	std::string filename1{ "ListOfPricesFromLowestToHighest.txt" };
	WriteToFile(filename1, gasPrices);
#pragma endregion

#pragma region List of Prices, Highest to Lowest
	auto predicate2 = [](const GasPrice& price1, const GasPrice& price2) { return price1.GetPrice() > price2.GetPrice(); };
	Sort(gasPrices, predicate2);
	std::string filename2{ "ListOfPricesFromHighestToLowest.txt" };
	WriteToFile(filename2, gasPrices);
#pragma endregion

	return 0;
}