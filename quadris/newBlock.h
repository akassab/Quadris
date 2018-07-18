#ifndef NEWBLOCK_H
#define NEWBLOCK_H
#include block.h

class newBlock {
	int level;
	bool random;
	char type;
public:
	void random(bool rand);
	void replace(char type);
	void setLvl(int lvl);
	void generatenew();
	char getnewBlk();
}

#endif
