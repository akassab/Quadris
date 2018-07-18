#ifndef NEWBLOCK_H
#define NEWBLOCK_H
#include bloch.h

class Score {
	int level;
	bool random;
	Block b;
public:
	void random(bool rand);
	void replace(char type);
	void setLvl(int lvl);
	void generatenew();
	Block getnewBlk();
}

#endif
