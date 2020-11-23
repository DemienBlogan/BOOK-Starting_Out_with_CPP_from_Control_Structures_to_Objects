#pragma once
#include <string>
#include <vector>
#include <tuple>
#include "GasPrice.h"

std::string ReadFromFile(const std::string& filename);
std::vector<std::string> GetLines(const std::string& text);
std::vector<GasPrice> GetGasPrices(const std::string& text);
std::vector<std::pair<int, double>> GetAveragePricesPerYear(const std::vector<GasPrice>& gasPrices);
std::vector<std::tuple<int, int, double>> GetAveragePricesPerMonth(const std::vector<GasPrice>& gasPrices);
std::vector<std::pair<int, double>> GetHighestPricesPerYear(const std::vector<GasPrice>& gasPrices);
std::vector<std::pair<int, double>> GetLowestPricesPerYear(const std::vector<GasPrice>& gasPrices);
void Sort(std::vector<GasPrice>& gasPrices, bool (*predicate)(const GasPrice& element1, const GasPrice& element2));
void WriteToFile(const std::string& filename, const std::vector<GasPrice>& gasPrices);