#ifndef NEWBLOCK_H
#define NEWBLOCK_H
#include <cstdlib>

class newBlock {
	int level;
	bool random;
	char type;
	int ran(int min, int max);
public:
	void rando(bool random);
	void replace(char type);
	void setLvl(int lvl);
	char generatenew();
	newBlock();
};

#endif
