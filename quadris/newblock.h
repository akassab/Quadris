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
	int ran(int min, int max); //generate seed
	std::vector<char> seq; //the chars read in from the sequence file
      	unsigned int charpos; 
	std::string seqfname; //name of file where sequence of blocks fed in
	bool newseed;//if a user inputted seed should be used
	int seed;
	public:
	void rando();
	void norandom(std::string s);
	void setLvl(int lvl);
	void newseqn(std::string s); //change the sequence file
	char generatenew(); //generate new block(char) to be passed to board
	void changeSeed(int seed); //set random generation to this seed
	bool isHeavy();
	newBlock();
};

#endif
