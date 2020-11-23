#pragma once
#include <string>
#include <map>
#include <set>
#include <vector>

std::string ReadFromFile(const std::string& filename);
std::set<std::string> GetUniqueWords(const std::string& text);
std::vector<std::string> GetLines(const std::string& text);
std::map<std::string, std::set<int>> GetWordsLines(const std::string& text);
void WriteToFile(const std::string& filename, const std::map<std::string, std::set<int>>& wordsLines);