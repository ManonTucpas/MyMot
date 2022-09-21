#include "myMot.hpp"

int main(void)
{
	int i = -1;
	myMot test;
	while (++i < 6)
	{
		test.setzero();
		std::string input= test.getInput();
		test.letterInword();
		if (test.compareWords(input) == true)
			return 0;
	}
	std::cout << "---- TRY AGAIN :) ----" << std::endl;
	return 0;
}
