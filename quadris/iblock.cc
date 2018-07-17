#include "iblock.h"
#include "block.h"
IBlock::IBlock(): Block{4, 2} {
	for (int i = 0; i < 4; ++i) {
		possibilities[0][3][i] = *(new Cell('I'));
		possibilities[1][i][0] = *(new Cell('I'));
	}
	current = possibilities[pos];
}
		
