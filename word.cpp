#include <cctype>
#include <algorithm>
#include <numeric>
#include <set>
#include "word.h"

Word::Word(const std::string& word)
{
	for (auto letter : word) 
	{
		if (std::isalpha(letter))
		{
			this->word.push_back(
				LetterWithVisibility(std::toupper(letter), false)
			);
		}
		else
		{
			this->word.push_back(
				LetterWithVisibility(letter, true)
			);
		}
	}
}

int Word::getNumberOfLetetrs(const LetterState& letterState) const
{
	int result = 0;
	if (letterState == LetterState::ALL) 
	{
		result = std::accumulate(
			word.begin(), word.end(),
			0, [&](int acc, const LetterWithVisibility& LWV) -> int
			{
				if (std::isalpha(LWV.first))
				{
					return acc + 1;
				}
				else
				{
					return acc + 0;
				}
			});
	}
	else if (letterState == LetterState::HIDDEN)
	{
		result = std::accumulate(
			word.begin(), word.end(),
			0, [&](int acc, const LetterWithVisibility& LWV) -> int
			{
				if (std::isalpha(LWV.first))
				{
					return acc + (LWV.second ? 0 : 1);
				}
				else
				{
					return acc + 0;
				}
			});
	}
	else if (letterState == LetterState::KNOWN)
	{
		result = std::accumulate(
			word.begin(), word.end(),
			0, [&](int acc, const LetterWithVisibility& LWV) -> int
			{
				if(std::isalpha(LWV.first))
				{
					return acc + (LWV.second ? 1 : 0);
				}
				else
				{
					return acc + 0;
				}
			});
	}
	return result;
}

int Word::getNumberOfUniqueLetters(const LetterState& letterState) const 
{
	int result = 0;
	std::set<char> uniqueLetters;
	if (letterState == LetterState::ALL)
	{
		for (auto letter : word)
		{
			if (std::isalpha(letter.first))
			{
				uniqueLetters.insert(letter.first);
			}
		}
	}
	else if (letterState == LetterState::HIDDEN)
	{
		for (auto letter : word)
		{
			if (letter.second == false)
			{
				if (std::isalpha(letter.first)) 
				{
					uniqueLetters.insert(letter.first);
				}
			}
		}
	}
	else if (letterState == LetterState::KNOWN)
	{
		for (auto letter : word)
		{
			if (letter.second)
			{
				if (std::isalpha(letter.first))
				{
					uniqueLetters.insert(letter.first);
				}
			}
		}
	}
	result = uniqueLetters.size();
	return result;
}

bool Word::contains(const char letter) const
{
	auto it = std::find_if(
		word.begin(), word.end(), 
		[&](const LetterWithVisibility& LWV) -> bool
		{
			return LWV.first == std::toupper(letter);
		});
	return it != word.end();
}

void Word::showLetter(const char letter)
{
	auto pred = [&](LetterWithVisibility LWV) -> bool 
	{
		return LWV.first == std::toupper(letter);
	};
	for (auto it = std::find_if(word.begin(), word.end(), pred); it != word.end(); it = std::find_if((it + 1), word.end(), pred))
	{
		it->second = true;
	}
}

void Word::showAllLetters()
{
	for (auto letter : word)
	{
		letter.second = true;
	}
}

std::string Word::getWord() const
{
	std::string word = "";
	for (auto letter : this->word)
	{
		word += letter.second ? letter.first : HIDDEN_LETTER;
	}
	return word;
}
