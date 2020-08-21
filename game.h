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
	std::set<std::string> usedLetters;
	GameDifficulty gameDifficulty;
public:
	Game(const WordList& wordlist);
	void play();
private:
	void newGame();
	GameDifficulty askAboutDifficultyLevel() const;
	std::string getRandomWord() const;
	char getLetterFromUser() const;
	bool askToPlayAgain() const;
	void clearScreen() const;
	void showGameBoard() const;
	void gameWon();
	void gameLost();
	bool isGameLost() const;
	bool isGameWon() const;
};

#endif