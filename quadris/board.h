#ifndef BOARD_H
#define BOARD_H
#include <iostream>
#include <vector>
#include "cell.h"
#include "block.h"
#include "newblock.h"
#include "score.h"
#include "observer.h"
#include "subject.h"

class Observer;

class Board: public Subject { 
	std::vector<std::vector<Cell>> board;
	Block *current = nullptr;
	newBlock *nb = nullptr;
	char newBlk;
	int score;
	Score *s = nullptr;
	int level;
	bool isFull(int r, int c); //checks if cell is full
	void setonBoard(); //sets current onto the board (drop)
	public:
	void init();
	
	
	bool checkFit();

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
