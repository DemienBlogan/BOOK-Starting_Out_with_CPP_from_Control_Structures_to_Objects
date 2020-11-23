#pragma once

#include <vector>
#include <array>

using namespace std;

vector<int> ConvertToVectorNumbers(
	const vector<array<int, 5>>& allWinCombinations,
	const vector<int>& allPowerBallWinNumbers);

void Display10MostCommonNumbers(const vector<int>& numbers);
void Display10LeastCommonNumbers(const vector<int>& numbers);
void Display10MostOverdueNumbers(const vector<int>& numbers);
void DisplayNumbersFrequency(const vector<array<int, 5>>& allWinCombinations, const vector<int>& allPowerBallWinNumbers);
vector<pair<int, int>> CalculateAppereance(const vector<int>& vec);