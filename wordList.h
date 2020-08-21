#ifndef WORDLIST_H
#define WORDLIST_H

#include <string>
#include <vector>

class WordList
{
friend class Game;
private:
    std::vector<std::string> wordList;
public:
    WordList(const std::vector<std::string>& wordList);
    WordList(const std::string& word);
    int size() const;
    std::string getWord(int index) const;
    void addWord(const std::string& word);
    static WordList loadFromFile(const std::string& filename);
    WordList operator=(const WordList& wordList);
private:
    WordList() { };
};

#endif
