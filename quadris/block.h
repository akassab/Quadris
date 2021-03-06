#ifndef BLOCK_H
#define BLOCK_H
#include <vector>
#include <iostream>
#include "board.h"
class Block {
	protected:
	int level; //the block the level is generated
	int r;//coordinates of lower left corner
	int c;
	// dimension of every orientation 
	int dim;
	// position in possibilities vector
	int pos;
	// num of orientations in possibilities vector
	int numPos;
	// current block orientation
	std::vector<std::vector<char>> current;
	// vector of orientations
	std::vector<std::vector<std::vector<char>>> possibilities;
	public: 
		Block(int gridDim, int numPossibilities);
		void setLevel(int level);
		int getLevel();
		char getChar(int r, int c);
		static Block *Create(char type);//create new subclass block of type
		void rotateClockwise();
		void rotateCounterClockwise();
		int getDim();
		void left();
		void right();
		void down();
		void up();
		void drop(); 
		int getR(); //return coordinates
		int getC();
		void setR(int r);
		void setC(int c);
		bool isHeavy(); //return true if block generated on level 3
		
};
#endif
