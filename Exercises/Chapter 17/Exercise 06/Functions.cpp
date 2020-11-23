#include <string>
#include <fstream>
#include <iostream>
#include <sstream>
#include "Functions.h"

std::string ReadFromFile(const std::string& filename)
{
    std::ifstream file{ filename };
    std::string textFromFile;

    std::string line;
    while (std::getline(file, line))
        textFromFile += line;

    file.close();

    return textFromFile;
}

std::vector<std::string> GetWords(const std::string& text)
{
    std::stringstream strStream{ text };
    std::vector<std::string> words;
    std::string word;

    while (strStream >> word)
        words.push_back(word);

    return words;
}

std::map<std::string, unsigned> GetWordsCount(const std::vector<std::string>& words)
{
    std::map<std::string, unsigned> wordsCount;

    for (const auto& word : words)
    {
        if (wordsCount.count(word) == 0)
            wordsCount[word] = 1;
        else
            wordsCount[word]++;
    }

    return wordsCount;
}

void Show(const std::map<std::string, unsigned>& wordsCount)
{
    for (const auto& wordCount : wordsCount)
        std::cout << "Word " << wordCount.first << " appears " << wordCount.second << " times.\n";
}