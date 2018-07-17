#include "sblock.h"
#include "block.h"

SBlock::SBlock(): Block{3,2} {
	//      //s  //
	//  s s //s s//
	//s s   //  s//
	possibilities[0][2][0] = *(new Cell('S',2 0));
	possibilities[0][2][1] = *(new Cell('S',2,1));
	possibilities[0][1][1] = *(new Cell('S',1,1));
	possibilities[0][1][2] = *(new Cell('S',1,2));
	
	possibilities[1][0][0] = * (new Cell('S',0,0));
	possibilities[1][1][0] = *(new Cell('S',1,0));
	possibilities[1][1][1]= *(new Cell('S',1,1));
	possibilities[1][2][1] = *(new Cell('S',2,1));
	current = possibilities[pos];
}

