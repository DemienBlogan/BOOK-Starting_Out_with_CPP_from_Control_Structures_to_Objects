#pragma once
#include <string>
#include <map>
#include <vector>

std::string ReadFromFile(const std::string& filename);
std::vector<std::string> GetWords(const std::string& text);
std::map<std::string, unsigned> GetWordsCount(const std::vector<std::string>& text);
void Show(const std::map<std::string, unsigned>& wordsCount);