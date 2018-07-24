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
	std::vector<int> blockids;
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
	int starcounter;
	Observer *ob = nullptr;
	
	public:
	void init();//initialized board
	void restart(); //restart board
	bool checkFit();//checks if piece fits in board
	//User current block transformations/moves
	void right(int mult = 1);
	void left(int mult = 1);
	bool drop(int mult = 1);
	void down(bool flag = true,int mult = 1); //if flag is true then should still check for isHeavy
	void clockwise(int mult = 1);
	void cclockwise(int mult = 1);
	//
	void dropstar();
	void removeBlock(int r, int c); //removes previous position of current block from board
	void putonBoard(bool flag= false, bool flag2 = false); //places current piece on board for display
	//first field is for if it should be firmly put on board, second field for if blank cells should be put on board as well(rotations)
	//User interactions
	void replace(char type);
	void random(bool random);
	
	void setObserver(Observer *ob);
	//Observer accessor functions
	int getHscore();
	int getScore();
	bool getLost();
	int getnewBlockHeight();
	int getnewBlockDim();
	char getnewBlock(int r, int c);
	Block getCurrent();
	void levelup(int mult = 1);
	void leveldown(int mult = 1);
	int getLevel();
	char getType(int x, int y);
	//

	int setLevel(int level);	

	void clearNew();

	//print
	void print();

};
#endif
