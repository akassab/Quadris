#ifndef BOARD_H
#define BOARD_H
#include <iostream>
#include <vector>
#include "cell.h"
#include "block.h"
using std::vector;
class Board { 
	vector<vector<Cell>> board;
	Block *current = nullptr;
	newBlock *nb = nullptr;
	char newBlk;
	int score;
	Score *s = nullptr
	int level;
	bool isFull(int r, int c);
	public:
	Board();
	void setnextBlock(NewBlock *nb);
	



	//User current block transformations/moves
	void right();
	void left();
	void drop();
	void down();
	void clockwise();
	void cclockwise();
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
