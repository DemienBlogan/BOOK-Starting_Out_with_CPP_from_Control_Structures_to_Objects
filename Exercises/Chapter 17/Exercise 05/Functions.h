#pragma once
#include <set>
#include <string>

std::string ReadFromFile(const std::string& filename);
void ShowWords(const std::set<std::string>& words);
std::set<std::string> GetUniqueWords(const std::string& text);
std::set<std::string> GetSameWords(const std::set<std::string>& wordsList1, const std::set<std::string>& wordsList2);
std::set<std::string> GetNotAppearedWords(const std::set<std::string>& wordsList1, const std::set<std::string>& wordsList2);