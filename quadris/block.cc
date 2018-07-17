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
	pos = 0;
	numPos = numPossibilities;
	dim = gridDim;
	possibilities.resize(numPossibilities);
	for (int pos = 0; pos < numPossibilities; ++pos) {
		possibilities[pos].resize(dim);
		for (int row = 0; row < dim; ++row) {
			possibilities[pos][row].resize(dim);
			for (int col = 0; col < dim; ++col) {
				possibilities[pos][row][col] = *(new Cell());
			}
		}
	}
}

Block *Block::Create(string type) {
	if (type == "i") {
		return new IBlock();
	}
	else if (type == "o") {
		return new OBlock();
	}
	else if (type == "t") {
		return new TBlock();
	}
	else if (type == "s") {
		return new SBlock();
	}
	else if (type == "z") {
		return new ZBlock();
	}
	else if (type == "l") {
		return new LBlock();
	}
	else if (type == "j") {
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

void Block::printCurrent() {
	for (int r = 0; r < dim; ++r) {
		for (int c = 0; c < dim; ++c) {
			cout << current[r][c].getType();
		}
		cout << endl;
	}
}
		
