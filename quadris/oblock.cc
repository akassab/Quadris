#include "oblock.h"
#include "block.h"

OBlock::OBlock(): Block{2,1} {
	possibilities[0][0][0] = *(new Cell('O',0,0));
	possibilities[0][0][1] = *(new Cell('O',0,1));
	possibilities[0][1][0] = *(new Cell('O',1,0));
	possibilities[0][1][1] = *(new Cell('O',1,1));
	current = possibilities[pos];
}

