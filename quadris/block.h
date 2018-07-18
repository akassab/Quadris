#ifndef BLOCK_H
#define BLOCK_H
#include <vector>
#include <iostream>
#include "cell.h"
// hi
class Block {
	protected:
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
		static Block *Create(char type);
		void rotateClockwise();
		void rotateCounterClockwise();
		int getDim();
		void left();
		void right();
		void down();
		void up();
		void drop(); 
		int getX(); //return coordinates
		int getY();
		std::vector<std::vector<char>> getCurrent(); //returns vector of positions
		// print the current orientation
		//void printCurrent();
};
#endif
