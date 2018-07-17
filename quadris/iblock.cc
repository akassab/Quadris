#include "iblock.h"
#include "block.h"
IBlock::IBlock(): Block{4, 2} {
	for (int i = 0; i < 4; ++i) {
		possibilities[0][3][i] = *(new Cell('I',3,i));
		possibilities[1][i][0] = *(new Cell('I',i,0));
	}
	current = possibilities[pos];
}
		
