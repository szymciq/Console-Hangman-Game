#ifndef WORD_H
#define WORD_H

#include <utility>
#include <vector>
#include <string>
#include "header.h"

using LetterWithVisibility = std::pair<char, bool>;
class Word 
{
private:
	std::vector<LetterWithVisibility> word;
public:
	Word(const std::string& word);
	int getNumberOfLetetrs(const LetterState& letterState = LetterState::ALL) const;
	int getNumberOfUniqueLetters(const LetterState& letterState = LetterState::ALL) const;
	bool contains(const char letter) const;
	void showLetter(const char letter);
	void showAllLetters();
	std::string getWord() const;
};

#endif