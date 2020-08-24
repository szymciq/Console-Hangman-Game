#include <random>
#include <algorithm>
#include <cstdlib>
#include <iterator>
#include "game.h"
#include "fun.h"

Game::Game(const WordList& wordList)
{
    this->wordList = wordList;
}

void Game::play()
{
    newGame();
}

void Game::newGame()
{
    usedLetters.clear();
    gameDifficulty = askAboutDifficultyLevel();
    remainingChances = START_CHANCES;
    std::string secretWord = getRandomWord();
    word = Word(secretWord);
    if (gameDifficulty == GameDifficulty::MEDIUM || gameDifficulty == GameDifficulty::EASY)
    {
        word.showLetter(secretWord[0]);
    }
    while (isGameInProgress())
    {
        clearScreen();
        showGameBoard();
        char c = getLetterFromUser();
        usedLetters.insert(c);        
        if (word.contains(c))
        {
            word.showLetter(c);
        }
        else
        {
            remainingChances--;
        }
    }
    showMessageWhenGameIsOver();
    if (askToPlayAgain())
    {
        newGame();
    } 
    else
    {
        std::cout << "Ok, good bye.\n";
    }
    
}

bool Game::isGameInProgress() const 
{
    return (!isGameLost() && !isGameWon());   
}

GameDifficulty Game::askAboutDifficultyLevel() const 
{
    char mode;
    std::cout 
        << "Choose difficulty level:\n"
        << "1. Hard\n"
        << "2. Medium [First letter will be shown]\n"
        << "3. Easy [As above + there is some information about letters]\n"
        << "ENTER VALUE:";
    while (1)
    {
        mode = getChar();
        if (mode == '1')
        {
            return GameDifficulty::HARD;
        }
        else if (mode == '2')
        {
            return GameDifficulty::MEDIUM;
        }
        else if (mode == '3')
        {
            return GameDifficulty::EASY;
        }
        else
        {
            std::cout << "Incorrect value, try again: ";
        }
    }
}

std::string Game::getRandomWord() const
{
    std::random_device rd;
	std::mt19937 rng(rd());
	std::uniform_int_distribution<unsigned> dist(0, wordList.size() - 1);
    return wordList.getWord(dist(rng));
}

char Game::getLetterFromUser() const 
{
    std::cout << "Guess next letter: ";
    char c;
    while (1)
    {
        c = getChar();
        if (std::isalpha(c))
        {
            c = std::toupper(c);
            if (std::find(usedLetters.begin(), usedLetters.end(), c) == usedLetters.end())
            {
                return c;
            }
            else 
            {
                std::cout << "This letter was used, try again: ";
            }
        }
        else
        {
            std::cout << "Incorrect input, try again: ";
        }
    }
}

bool Game::askToPlayAgain() const
{
    char c;
    std::cout << "Do you want to play again? (y/n): ";
    c = getChar();
    if (std::tolower(c) == 'y')
    {
        return true;
    } 
    else
    {
        return false;
    }   
}

void Game::clearScreen() const
{
    CLEAR_SCREEN;
}

void Game::showGameBoard() const
{
    std::cout << "Used letters: ";
    std::copy(usedLetters.begin(), usedLetters.end(), std::ostream_iterator<char>(std::cout, " "));
    std::cout << "\nRemaining chances: " << remainingChances << std::endl;
    if (gameDifficulty == GameDifficulty::EASY)
    {
        std::cout << "There are " << word.getNumberOfUniqueLetters(LetterState::HIDDEN) << " unique letters to show..\n";
    }
    std::cout << word.getWord() << std::endl;
}

void Game::gameWon()
{
    std::cout 
        << "Congratulations!\n"
        << "The secret word is " << word.getWord() << "!\n"
        << "Your remaining chances: " << remainingChances << "\n"
        << std::string(20, '-') << std::endl;
}

void Game::gameLost()
{
    word.showAllLetters();
    std::cout 
        << "Unlucky!\n"
        << "The secret word is " << word.getWord() << "!\n"
        << std::string(20, '-') << std::endl;
}

bool Game::isGameLost() const
{
    return (remainingChances == 0);
}

bool Game::isGameWon() const
{
    return 
        word.getNumberOfLetetrs(LetterState::ALL) == word.getNumberOfLetetrs(LetterState::KNOWN);
}

void Game::showMessageWhenGameIsOver()
{
    clearScreen();
    showGameBoard();
    std::cout << std::endl << std::string(20, '-') << std::endl;
    if (isGameWon())
    {
        gameWon();
    }
    else if (isGameLost())
    {
        gameLost();
    }   
}