#include "iblock.h"
#include "block.h"
IBlock::IBlock(): Block{4, 2} {
	r = 3;
	c = 0;
	for (int i = 0; i < 4; ++i) {
		possibilities[0][3][i] = 'I';
		possibilities[1][i][0] = 'I';
	}
	current = possibilities[pos];
}
		
