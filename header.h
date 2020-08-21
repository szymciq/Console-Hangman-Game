#ifndef HEADER_H
#define HEADER_H

enum LetterState
{
	ALL,
	HIDDEN,
	KNOWN
};

constexpr char HIDDEN_LETTER = '*';
constexpr int START_CHANCES = 8;
const std::string WORD_LIST_FILENAME = "exampleWords.txt";

#endif