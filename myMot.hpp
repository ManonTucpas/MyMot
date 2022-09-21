#ifndef MOT_HPP
#define MOT_HPP

#include <iostream>
#include <vector>
#include <list>
using namespace std;
//create fichier 5 lettres

class myMot
{
	public :
		myMot(void);
		~myMot(void);
		vector<std::string> _copyDict;
		std::string getInput(void);
		bool compareWords(std::string userInput);
		void letterInword(void);
		void setzero(void) { _tab = {0,0,0,0,0}; }
		vector<int> _tab;

	//functions
	private:
		string _userInput;
		const string _word;
		bool _winner;
		bool isWord(string) const;
		//bool compareWords(string);
		void printTable() const;
		std::string generateWord(void);
		bool ifExists(std::string input) const;
		unsigned int _tries;
};

//main TODO: take work from STDIN, if not string of 5 error and wait for STDIN, invalid?
#endif
