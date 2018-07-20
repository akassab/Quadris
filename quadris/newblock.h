#ifndef NEWBLOCK_H
#define NEWBLOCK_H

class newBlock {
	int level;
	bool random;
	char type;
public:
	void rand(bool random);
	void replace(char type);
	void setLvl(int lvl);
	char generatenew();
	newBlock();
};

#endif
