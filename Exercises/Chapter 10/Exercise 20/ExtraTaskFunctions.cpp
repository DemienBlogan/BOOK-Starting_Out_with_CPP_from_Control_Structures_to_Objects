#include <algorithm>
#include <iostream>
#include <map>
#include <set>

#include "ExtraTaskFunctions.h"

vector<int> ConvertToVectorNumbers(const vector<array<int, 5>>& allWinCombinations, const vector<int>& allPowerBallWinNumbers)
{
	vector<int> numbers;

	for (size_t i = 0; i < allWinCombinations.size(); i++)
		for (size_t j = 0; j < allWinCombinations[i].size(); j++)
			numbers.push_back(allWinCombinations[i][j]);

	for (size_t i = 0; i < allPowerBallWinNumbers.size(); i++)
		numbers.push_back(allPowerBallWinNumbers[i]);

	return numbers;
}

void Display10MostCommonNumbers(const vector<int>& numbers)
{
	// vector of number, but is sort order
	vector<int> sortNumbers(numbers);
	sort(sortNumbers.begin(), sortNumbers.end());

	// vector of pair of (number | amountOfAperreance)
	vector<pair<int, int>> numbersAperreance = CalculateAppereance(sortNumbers);

	// predicate for sorting numbers by their aperreance
	auto predicate = [](pair<int, int> pair1, pair<int, int> pair2) {return pair1.second < pair2.second; };

	sort(numbersAperreance.begin(), numbersAperreance.end(), predicate);

	// showing result
	cout << "10 the most common numbers: ";
	for (size_t i = numbersAperreance.size() - 1, j = 0; j < 10; j++, i--)
		cout << numbersAperreance[i].first << " ";
	cout << endl;
}

void Display10LeastCommonNumbers(const vector<int>& numbers)
{
	// vector of number, but is sort order
	vector<int> sortNumbers(numbers);
	sort(sortNumbers.begin(), sortNumbers.end());

	// vector of pair of (number | amountOfAperreance)
	vector<pair<int, int>> numbersAperreance = CalculateAppereance(sortNumbers);

	// predicate for sorting numbers by their aperreance
	auto predicate = [](pair<int, int> pair1, pair<int, int> pair2) { return pair1.second < pair2.second; };

	sort(numbersAperreance.begin(), numbersAperreance.end(), predicate);

	// showing result
	cout << "10 the least common numbers: ";
	for (size_t i = 0; i < 10 && i < numbersAperreance.size(); i++)
		cout << numbersAperreance[i].first << " ";
	cout << endl;
}

void Display10MostOverdueNumbers(const vector<int>& numbers)
{
	set<int> uniqueNumbers{ numbers.cbegin(), numbers.cend() };
	map<int, int> numbersAppereance;

	// Calculate period of time between two appereance of unique number:
	int firstApereance = -1, secondApereance = -1;
	int longestPeriod;
	int periodBetweenApereance;

	for (int uniqueNumber : uniqueNumbers)
	{
		longestPeriod = 0;
		periodBetweenApereance = 0;

		for (size_t j = 0; j < numbers.size(); j++)
		{
			if (numbers[j] == uniqueNumber)
			{
				if (firstApereance == -1)
					firstApereance = j;
				else if (secondApereance == -1)
					secondApereance = j;

				if (firstApereance != -1 && secondApereance != -1)
				{
					periodBetweenApereance = secondApereance - firstApereance;

					if (longestPeriod < periodBetweenApereance)
						longestPeriod = periodBetweenApereance;

					firstApereance = secondApereance;
					secondApereance = -1;
				}
			}
		}

		if (longestPeriod == 0)
			longestPeriod = numbers.size();

		numbersAppereance[uniqueNumber] = longestPeriod;
	}

	vector<pair<int, int>> numbersAppereanceVector{ numbersAppereance.cbegin(), numbersAppereance.cend() };

	sort(numbersAppereanceVector.begin(), numbersAppereanceVector.end(), 
		[](const pair<int, int>& pair1, const pair<int, int>& pair2) -> bool { return pair1.second > pair2.second; });

	numbersAppereanceVector.resize(10);

	cout << "10 most overdue numbers:\n";
	for (size_t i = 0; i < numbersAppereanceVector.size(); i++)
	{
		cout << "Number " << numbersAppereanceVector[i].first;
		cout << " ( period of time between two appereance = " << numbersAppereanceVector[i].second << ").\n";
	}
}

void DisplayNumbersFrequency(const vector<array<int, 5>>& allWinCombinations, const vector<int>& allPowerBallWinNumbers)
{
	// vector of win combinations, but is sort order
	vector<int> sortWinCombinations(allWinCombinations.size() * 5);
	vector<int> sortPowerBallWinNumbers(allPowerBallWinNumbers);

	// copy win combination numbers into sortWinCombinations
	size_t countCombinations = allWinCombinations.size();
	size_t numbersInCombination = allWinCombinations[0].size();
	int index = 0;
	for (size_t i = 0; i < countCombinations; i++)
		for (size_t j = 0; j < numbersInCombination; j++)
			sortWinCombinations[index++] = (allWinCombinations[i][j]);

	// sort both vectors
	sort(sortWinCombinations.begin(), sortWinCombinations.end());
	sort(sortPowerBallWinNumbers.begin(), sortPowerBallWinNumbers.end());

	// vectors of pair of (number | amountOfAperreance)
	vector<pair<int, int>> winCombinationAperreance = CalculateAppereance(sortWinCombinations);
	vector<pair<int, int>> powerBallNumbersAperreance = CalculateAppereance(sortPowerBallWinNumbers);

	// showing result
	cout << "Frequency of each number (1-69):\n";
	for (auto& combination : winCombinationAperreance)
		cout << "Number: " << combination.first << " | appereance: " << combination.second << endl;

	cout << "\nFrequency of each Powerball number (1-26):\n";
	for (auto& powerBall : powerBallNumbersAperreance)
		cout << "Number: " << powerBall.first << " | appereance: " << powerBall.second << endl;
}

vector<pair<int, int>> CalculateAppereance(const vector<int>& vec)
{
	// vector of pair of (number | amountOfAperreance)
	vector<pair<int, int>> numbersAperreance;
	int numberCount = 0;

	// Calculating appereance of every number
	for (size_t i = 0, j = 1; i < vec.size() - 1; i++, j++)
	{
		if (vec[i] == vec[j])
			numberCount++;
		else
		{
			numbersAperreance.push_back(make_pair(vec[i], numberCount));
			numberCount = 1;
		}

		// add last number
		if (j == vec.size() - 1)
			numbersAperreance.push_back(make_pair(vec[i], numberCount));
	}

	return numbersAperreance;
}