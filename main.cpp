#include <iostream>
#include "game.h"

int main() 
{
	WordList wordList = WordList::loadFromFile(WORD_LIST_FILENAME);
	Game game(wordList);
	game.play();
}