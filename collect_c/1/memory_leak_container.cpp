
/* This software was developed at the National Institute of Standards and
 * Technology by employees of the Federal Government in the course of their
 * official duties. Pursuant to title 17 Section 105 of the United States
 * Code this software is not subject to copyright protection and is in the
 * public domain. NIST assumes no responsibility whatsoever for its use by
 * other parties, and makes no guarantees, expressed or implied, about its
 * quality, reliability, or any other characteristic.

 * We would appreciate acknowledgement if the software is used.
 * The SAMATE project website is: http://samate.nist.gov
*/


#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Bot
{
	std::string name;
	std::string func;
public:
	Bot(const std::string& _name = "Nono", const std::string& _func = "_gentil_robot")
	  : name(_name), func(_func)
	{}
	Bot(const Bot& bot)
	: name(bot.name), func(bot.func)
	{}
	~Bot() {}

	Bot& operator=(const Bot& bot) {
		name = bot.name;
		func = bot.func;
		return *this;
	}

	void action() {
		std::cout << name << " \t" << func << ";" << std::endl;
	}
};

vector<Bot *> pBots;

string names[] = {"Botty","Fool","iRobot"};
string funcs[] = {"_friend", "_coffee","_plop"};

int main()
{
	Bot def;
	const unsigned short max_nf = 3;
	// Init the bots with functions
	for (unsigned short i=0;i<max_nf;++i) {
		pBots.push_back(new Bot(names[i], funcs[i]));
	}

	for (vector<Bot *>::const_iterator iter = pBots.begin(); iter != pBots.end(); ++iter)
		(*iter)->action();

	return 0;
}


