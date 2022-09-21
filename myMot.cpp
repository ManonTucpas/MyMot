#include "myMot.hpp"
#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <iomanip>
#include <vector>
#include <utility>
#include <list>
#include <algorithm>
#include <cstring>
#include <stdio.h>
#include <ctype.h>


using namespace std;

myMot::myMot(void) : _word(generateWord()), _winner(false), _tries(0)
{
	//std::cout << "random Word is " << _word << std::endl;
	_tab = {0,0,0,0,0};
}

myMot::~myMot(void) {}

/*line count + copy dictionary to vector + return word*/
std::string myMot::generateWord(void)
{
	ifstream in;
	int count = 0;
	int random = 0;

	std::string to_add;
	in.open("dict");
	if (!in.good())
		std::cout << "ERROR" << std::endl;
	while(!in.eof())
	{
		getline(in, to_add);
		_copyDict.push_back(to_add);
		count++;
	}
	count--;
	srand(time(NULL));
	random = rand() % count;
	return (_copyDict[random]);
}


//function ifExists
bool myMot::ifExists(std::string input) const
{
	std::vector<std::string>::const_iterator ptr = find(_copyDict.begin(), _copyDict.end(), input);
	if (ptr == _copyDict.end())
	{
		std::cout << "This word doesn't exist" << input << std::endl;
		return false;
	}
	return true;
}

/* get user input and compare to the random word generated */
std::string myMot::getInput(void)
{
	std::string input;
	while (std::cin.eof() != 1)
	{
		std::cout << "Enter a word with 5 letters : " << std::endl;
		std::getline(std::cin, input);
		if (std::cin.eof() == 1)
		{
			std::cout << "bye..." << std::endl;
			exit(1);
		}
		else if (input.size() != 5)
			std::cout << "Not enough or too many letters" << std::endl;
		else if (this->ifExists(input))
		{
			for (unsigned long x=0; x< input.size(); x++)
        		_userInput[x] = (toupper(input[x]));
			break;
		}
	}
	return (input);
}

/*CURRENTLY THIS CREATES A NEW WORD EVERYTIME YOU PLAY: DO WE WANT TO DO THAT OR HAVE A DAILY WORD: IN WHICH CASE SPLIT INTO TWO CLASSES*/
bool myMot::compareWords(std::string userInput)
{
	if (strcmp(_word.c_str(), userInput.c_str()) == 0)
	{
		_winner = true;
		std::cout << "---- Congratulations :) ----" << std::endl;
		return true;
	}
	return false;
}

void myMot::letterInword(void)
{
	unsigned long search;

	for (unsigned long i = 0; i < _word.size(); i++)
	{
		search = _word.find(_userInput[i]);
		if (search !=std::string::npos)
			_tab[i] = 1;
		if (_userInput[i] == _word[i])
			_tab[i] = 2;
	}
	printTable();
}

void myMot::printTable(void) const
{
	int i = 0;
    std::vector<int>::const_iterator ptr;
    for (ptr = _tab.begin() ;ptr != _tab.end(); ptr++)
    {
		char c = '|';

		if (*ptr == 0)
			std::cout << _userInput[i] << " " << c << " " ;
		else if (*ptr == 1)
			std::cout << "\033[1;33m" << _userInput[i] << "\033[0m" << " " << c << " " ;
		else
			std::cout << "\033[1;32m"  << _userInput[i] << "\033[0m" << " " << c << " " ;
		i++;
    }
    std::cout << std::endl;
}
