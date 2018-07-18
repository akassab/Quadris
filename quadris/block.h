#ifndef BLOCK_H
#define BLOCK_H
#include <vector>
#include <iostream>
#include "cell.h"
<<<<<<< HEAD
#include "board.h"
=======
// hi
>>>>>>> 2c5d2c194558f9003c67e6516ca064aa69444eb2
class Block {
	protected:
	// dimension of every orientation 
	int dim;
	// position in possibilities vector
	int pos;
	// num of orientations in possibilities vector
	int numPos;
	// current block orientation
	std::vector<std::vector<Cell>> current;
	// vector of orientations
	std::vector<std::vector<std::vector<Cell>>> possibilities;
	public: 
		Block(int gridDim, int numPossibilities);
		//static Block *Create(std::string type);
		void rotateClockwise();
		void rotateCounterClockwise();
		void left();
		void right();
		void down();
		void drop();
		// print the current orientation
		//void printCurrent();
};
#endif
