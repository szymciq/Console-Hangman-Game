#include "wordList.h"
#include <fstream>
WordList::WordList(const std::vector<std::string>& wordList)
: wordList(wordList) { }

WordList::WordList(const std::string& word)
{
    wordList.push_back(word);
}

int WordList::size() const
{
    return wordList.size();
}

std::string WordList::getWord(int index) const
{
    if (index < size())
    {
        return wordList[index];
    }
    else 
    {
        return "";
    }
}

void WordList::addWord(const std::string& word)
{
    wordList.push_back(word);
}

WordList WordList::loadFromFile(const std::string& filename) 
{
    std::ifstream file(filename);
    if (!file.is_open())
    {
        return WordList();
    }
    else
    {
        std::vector<std::string> wordsFromFile;
        while (!file.eof())
        {
            std::string line;
            std::getline(file, line);
            if (line.length() < 3)
                continue;
            wordsFromFile.push_back(line);
        }
        return WordList(wordsFromFile);
    }
}

WordList WordList::operator=(const WordList& wordList)
{
    this->wordList = wordList.wordList;
    return *this;
}