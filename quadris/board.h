#ifndef BOARD_H
#define BOARD_H
#include <iostream>
#include <vector>
#include "cell.h"
#include "newblock.h"
#include "score.h"
#include "subject.h"

class Block;
class Observer;
class TextDisplay;

class Board: public Subject { 
	int id; // id of current block
	TextDisplay *td = nullptr; //the textdisplay!
	std::vector<std::vector<Cell>> board; //vector cells representing the quadris board
	Block *current = nullptr; //the current block being moved
	Block *newblock = nullptr;
	newBlock *nb = nullptr; //the next block to be displayed
	char newBlk; //the char of the next block to be displayed
	int score; //the score
	Score *s = nullptr;//score class
	int level;//level
	bool isFull(int r, int c); //checks if cell is full
	void droponBoard(); //sets current onto the board (drop)
	int checkRows();
	public:
	void init();//initialized board
	bool checkFit();//checks if piece fits in board
	//User current block transformations/moves
	void right();
	void left();
	bool drop();
	void down();
	void clockwise();
	void cclockwise();
	//
	void removeBlock(int r, int c); //removes previous position of current block from board
	void putonBoard(bool flag= false, bool flag2 = false); //places current piece on board for display
	//first field is for if it should be firmly put on board, second field for if blank cells should be put on board as well(rotations)
	//User interactions
	void replace(char type);
	void random(bool random);
	

	//Observer accessor functions
	int getHscore();
	int getScore();
	bool getLost();
	int getnewBlockHeight();
	int getnewBlockDim();
	char getnewBlock(int r, int c);
	Block getCurrent();
	void levelup();
	void leveldown();
	int getLevel();
	char getType(int x, int y);
	//

	int setLevel(int level);	

	void clearNew();

	//print
	void print();

};
#endif
