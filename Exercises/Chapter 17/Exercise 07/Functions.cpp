#include <fstream>
#include <sstream>
#include <string>
#include "Functions.h"

std::string ReadFromFile(const std::string& filename)
{
	std::ifstream file{ filename };
	std::string textFromFile;

	std::string line;
	while (std::getline(file, line))
		textFromFile += line + '\n';

	file.close();

	return textFromFile;
}

std::set<std::string> GetUniqueWords(const std::string& text)
{
	std::stringstream strStream{ text };
	std::set<std::string> uniqueWords;
	std::string word;

	while (strStream >> word)
		uniqueWords.insert(word);

	return uniqueWords;
}

std::vector<std::string> GetLines(const std::string& text)
{
	std::vector<std::string> lines;

	std::stringstream strStream{ text };
	std::string line;

	while (std::getline(strStream, line))
		lines.push_back(line);

	return lines;
}

std::map<std::string, std::set<int>> GetWordsLines(const std::string& text)
{
	std::set<std::string> uniqueWords = GetUniqueWords(text);
	std::vector<std::string> lines = GetLines(text);

	std::map<std::string, std::set<int>> wordsLines;

	for (const auto& word : uniqueWords)
	{
		int lineNumber = 0;

		for (const auto& line : lines)
		{
			lineNumber++;

			if (line.find(word) != std::string::npos)
				wordsLines[word].insert(lineNumber);
		}
	}

	return wordsLines;
}

void WriteToFile(const std::string& filename, const std::map<std::string, std::set<int>>& wordsLines)
{
	std::ofstream file{ filename };

	for (const auto& wordLine : wordsLines)
	{
		file << "Word [" << wordLine.first << "] appears in lines: ";
		for (const auto& lineNumber : wordLine.second)
			file << lineNumber << " ";
		file << std::endl;
	}

	file.close();
}