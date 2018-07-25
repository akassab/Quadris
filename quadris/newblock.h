#ifndef NEWBLOCK_H
#define NEWBLOCK_H
#include <cstdlib>
#include <iostream>
#include <vector>
#include <string>

class newBlock {
	int level;
	bool random;
	char type;
	int ran(int min, int max);
	std::vector<char> seq;
      	unsigned int charpos;
	std::string seqfname;
	bool newseed;
	int seed;
public:
	void rando();
	void norandom(std::string s);
	void replace(char type);
	void setLvl(int lvl);
	void newseqn(std::string s);
	char generatenew();
	void changeSeed(int seed);
	bool isHeavy();
	newBlock();
};

#endif
