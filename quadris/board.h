#ifndef BOARD_H
#define BOARD_H
#include <iostream>
#include <vector>
#include "cell.h"
#include "block.h"
using std::vector;
class Board { 
	vector<vector<Cell>> board;
	Block *current;
	NewBlock *nb;
	int score;
	Score *s;
	int level;
	public:
	Board();
	void setnextBlock(NewBlock *nb);
	



	//User current block transformations/moves
	void right(Block *current);
	void left(Block *current);
	void drop(Block *current);
	void down(Block *current);
	void clockwise(Block *current);
	void cclockwise(Block *current);
	//

	//User interactions
	void changeNextBlk(char type);
	void random(bool random);


	//Observer accessor functions
	int getScore();
	bool getLost();
	Block getNewBlock();
	Block getCurrent();
	int getLevel();
	char getType(int x, int y);
	//

	int setLevel(int level);	
	

	//void draw();
	//void print();
	void clearNew();

};
#endif
