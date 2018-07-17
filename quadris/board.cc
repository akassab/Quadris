
#include "board.h"
#include "block.h"
using namespace std;
Board::Board() {
	board.resize(22);
	for (int i = 0; i < 22; ++i) {
		board[i].resize(13);
	}
}

void Board::print() {
	for (int i = 0; i < 4; ++i) {
		if (i == 1) {
			cout << "-Level:    " << 1 << "-" << endl;
		}
		else if (i == 2) {
			cout << "-Score:    " << 0 << "-" << endl;
		}
	else if (i == 3) {
			cout << "-Hi Score  " << 0 << "-" << endl;
		}	
		}
	cout << endl;
	current->printCurrent();
	}


void Board::newBlock(Block *b) {
	current = b;
}


void Board::clearNew() {
	for (int i = 0; i < 4; ++i) {
		for (int r = 0; r < 11; ++r) {
			board[i][r] = *(new Cell());
		}
	}
}
