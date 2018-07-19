#include "zblock.h"
#include "block.h"

ZBlock::ZBlock(): Block{3,2} {
	r = 4;
	c = 0;	
	possibilities[0][1][0] = 'Z';
	possibilities[0][1][1] = 'Z';
	possibilities[0][2][1] = 'Z';
	possibilities[0][2][2] = 'Z';

	possibilities[1][0][1] = 'Z';
	possibilities[1][1][0] = 'Z';
	possibilities[1][1][1] ='Z';
	possibilities[1][2][0] = 'Z';
	current = possibilities[pos];
}

