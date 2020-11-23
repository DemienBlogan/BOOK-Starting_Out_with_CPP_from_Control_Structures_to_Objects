#include <sstream>
#include <fstream>
#include <iostream>
#include <iomanip>
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

void ShowWords(const std::set<std::string>& words)
{
    int wordsInLine = 0;
    for (const auto& word : words)
    {
        if (wordsInLine == 7)
        {
            wordsInLine = 0;
            std::cout << std::endl;
        }

        std::cout << std::setw(15) << word << " ";

        wordsInLine++;
    }

    std::cout << std::endl;
    system("pause");
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

std::set<std::string> GetSameWords(const std::set<std::string>& wordsList1, const std::set<std::string>& wordsList2)
{
    std::set<std::string> sameWords;
    bool list1HasWord, list2HasWord;

    for (const auto& word1 : wordsList1)
    {
        list2HasWord = false;

        for (const auto& word2 : wordsList2)
        {
            if (word1 == word2)
            {
                list2HasWord = true;
                break;
            }
        }

        if (list2HasWord)
            sameWords.insert(word1);
    }

    for (const auto& word2 : wordsList2)
    {
        list1HasWord = false;

        for (const auto& word1 : wordsList1)
        {
            if (word2 == word1)
            {
                list1HasWord = true;
                break;
            }
        }

        if (list1HasWord)
            sameWords.insert(word2);
    }

    return sameWords;
}

std::set<std::string> GetNotAppearedWords(const std::set<std::string>& wordsList1, const std::set<std::string>& wordsList2)
{
    std::set<std::string> notAppearedWords;
    bool list2HasWord;

    for (const auto& word1 : wordsList1)
    {
        list2HasWord = false;

        for (const auto& word2 : wordsList2)
        {
            if (word1 == word2)
            {
                list2HasWord = true;
                break;
            }
        }

        if (!list2HasWord)
            notAppearedWords.insert(word1);
    }

    return notAppearedWords;
}
