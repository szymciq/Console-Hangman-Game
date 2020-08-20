#ifndef GAME_H
#define GAME_G

#include <iostream>
#include <string>
#include <vector>
#include <set>
#include "header.h"
#include "word.h"
#include "wordList.h"

enum GameDifficulty 
{
	EASY,
	MEDIUM, 
	HARD
};

class Game
{
private:
	Word word;
	int remainingChances;
	WordList wordList;
	std::set<std::string> givenLetters;
public:
	Game(const WordList& wordlist, int remainingChances = START_CHANCES);
private:
	void newGame();
	char getLetterFromUser();
	GameDifficulty askAboutDifficultyLevel();
	bool askToPlayAgain(); 
	void clearScreen();
	void showGameBoard();
	void gameWon();
	void gameLost();
	bool isGameLost();
	bool isGameWon();
};

#endif