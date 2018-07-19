#include "oblock.h"
#include "block.h"

OBlock::OBlock(): Block{2,1} {
	r = 4;
	c = 0;
	possibilities[0][0][0] = 'O';
	possibilities[0][0][1] = 'O';
	possibilities[0][1][0] = 'O';
	possibilities[0][1][1] = 'O';
	current = possibilities[pos];
}

