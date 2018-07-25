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

void Block::setLevel(int levelgen){
	level = levelgen;
}





int Block::getDim(){
	return dim;
}

Block *Block::Create(char type) {
	if (type == 'I') {
		return new IBlock();
	}
	else if (type == 'O') {
		return new OBlock();
	}
	else if (type == 'T') {
		return new TBlock();
	}
	else if (type == 'S') {
		return new SBlock();
	}
	else if (type == 'Z') {
		return new ZBlock();
	}
	else if (type == 'L') {
		return new LBlock();
	}
	else if (type == 'J') {
		return new JBlock();
	}
	else return NULL;
}

void Block::rotateClockwise() {
	int bound = numPos - 1;
	pos == bound ? pos = 0 : pos+= 1;
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
	r = r+1;
}

void Block::up(){
	r = r-1;
}

int Block::getR(){
	return r;
}

int Block::getC(){
	return c;
}

char Block::getChar(int r, int c){
	return current[r][c];
}


int Block::getHeight(){
	int retval = 0;
	for(int i = 0; i<dim; ++i){
		for(int j = 0; j<dim; ++j){
			if(current[i][j] != ' '){
				return retval;
			}
		}
		retval ++;
	}
	return retval;
}

int Block::getLevel(){
	return level;
}

bool Block::isHeavy(){
	if(level == 3 || level == 4){
		return true;
	}
	else{
		return false;
	}
}

void Block::setR(int r){
	this->r = r;
}

void Block::setC(int c){
	this->c = c;
}
			
