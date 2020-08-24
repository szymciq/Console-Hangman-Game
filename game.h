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
	std::set<char> usedLetters;
	GameDifficulty gameDifficulty;
public:
	Game(const WordList& wordList);
	void play();
private:
	void newGame();
	GameDifficulty askAboutDifficultyLevel() const;
	std::string getRandomWord() const;
	bool isGameInProgress() const;
	char getLetterFromUser() const;
	bool askToPlayAgain() const;
	void clearScreen() const;
	void showGameBoard() const;
	void gameWon();
	void gameLost();
	bool isGameLost() const;
	bool isGameWon() const;
	void showMessageWhenGameIsOver();
};

#endif