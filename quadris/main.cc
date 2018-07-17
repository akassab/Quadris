#include "board.h"
#include "iblock.h"
#include "jblock.h"
#include "lblock.h"
#include "zblock.h"
#include "tblock.h"
#include "oblock.h"
#include "sblock.h"
using namespace std;
int main() {
	Board *board = new Board();	
	
	//		b->newBlock('L');
	//		b->print();
	Block *b = new LBlock();
	board->newBlock(b);
	string input;
	while (cin >> input) {
		if (input == "r") {
			b->rotateClockwise();
		}
		else if (input == "c") {
			b->rotateCounterClockwise();
		}
		else if (b = Block::Create(input)) {
			board->newBlock(b);

		}
		board->print();
		
	}

	

}
	



