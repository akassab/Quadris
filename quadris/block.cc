#include "block.h"
#include "iblock.h"
#include "oblock.h"
#include "tblock.h"
#include "lblock.h"
#include "jblock.h"
#include "sblock.h"
#include "zblock.h"
#include <vector>

using namespace std;
Block::Block(int gridDim, int numPossibilities) {
	r = 0;
	c = 0;
	pos = 0;
	numPos = numPossibilities;
	dim = gridDim;
	possibilities.resize(numPossibilities);
	for (int pos = 0; pos < numPossibilities; ++pos) {
		possibilities[pos].resize(dim);
		for (int row = 0; row < dim; ++row) {
			possibilities[pos][row].resize(dim);
			for (int col = 0; col < dim; ++col) {
				possibilities[pos][row][col] = ' ';
			}
		}
	}
}

int Block::getDim(){
	return dim;
}

Block *Block::Create(char type) {
	if (type == 'i') {
		return new IBlock();
	}
	else if (type == 'o') {
		return new OBlock();
	}
	else if (type == 't') {
		return new TBlock();
	}
	else if (type == 's') {
		return new SBlock();
	}
	else if (type == 'z') {
		return new ZBlock();
	}
	else if (type == 'l') {
		return new LBlock();
	}
	else if (type == 'j') {
		return new JBlock();
	}
	else return NULL;
}
void Block::rotateClockwise() {
	if (pos == numPos - 1) {
		pos = 0;
	}
	else {
		pos += 1;
	}
	current = possibilities[pos];
}

void Block::rotateCounterClockwise() {
	if (pos == 0) {
		pos = numPos - 1;
	}
	else {
		pos -= 1;
	}
	current = possibilities[pos];
}
void Block::left(){
	c = c-1;	

}

void Block::right(){
	c = c+1;
}

void Block::down(){
	r = r-1;
}

void Block::up(){
	r = r+1;
}

int Block::getR(){
	return r;
}

int Block::getC(){
	return c;
}


std::vector<std::vector<char>> Block::getCurrent() {
	return current;
	/*
	for (int r = 0; r < dim; ++r) {
		for (int c = 0; c < dim; ++c) {
			cout << current[r][c].getType();
		}
		cout << endl;
	}
	*/
}

