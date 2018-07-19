#include "sblock.h"
#include "block.h"

SBlock::SBlock(): Block{3,2} {
	r = 4;
	c = 0;

	possibilities[0][2][0] = 'S';
	possibilities[0][2][1] = 'S';
	possibilities[0][1][1] = 'S';
	possibilities[0][1][2] = 'S';
	
	possibilities[1][0][0] = 'S';
	possibilities[1][1][0] = 'S';
	possibilities[1][1][1]= 'S';
	possibilities[1][2][1] = 'S';

	current = possibilities[pos];
}

