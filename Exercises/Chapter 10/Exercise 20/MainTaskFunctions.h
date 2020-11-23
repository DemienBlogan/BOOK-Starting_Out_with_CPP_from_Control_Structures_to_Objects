#pragma once

#include <fstream>
#include <vector>
#include <array>

using namespace std;

void SetRandom();
void OpenFile(ifstream& file, const string& fileName);
void ReadFromFile(ifstream& file, vector<array<int, 5>>& allWinCombinations, vector<int>& allPowerBallWinNumbers);
void SetTicket(array<int, 5>& userTicket);
void SetPowerBallNumber(int& userPowerBallNumber);
void ShowUserCombination(const array<int, 5>& userTicket, int userPowerBallNumber);
void ShowWinCombination(const array<int, 5>& winCombination, int winPowerBallNumber);
size_t SelectWin5NumbersIndex(size_t allWinCombinationsSize);
size_t SelectWinPowerBallIndex(size_t allPowerBallWinNumbersSize);
int CountSameNumbers(
	const array<int, 5>& winCombination, const array<int, 5>& userTicket,
	int winPowerBallNumber, int userPowerBallNumber);
void ShowResult(int sameNumbers);