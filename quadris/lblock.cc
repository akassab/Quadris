#include "lblock.h"
#include "block.h"

LBlock::LBlock(): Block{3,4} {
	// 	//L  //      //L L
	//     L//L  //L L L //  L
	// L L L//L L//L     //  L
	possibilities[0][1][2] = *(new Cell('L',1,2)); 
	possibilities[1][2][1] = *(new Cell('L',2,1));
	possibilities[2][2][0] = *(new Cell('L',2,0));
	possibilities[3][0][0] = *(new Cell('L',0,0));
	for (int i = 0; i < 3; ++i) {
		possibilities[0][2][i] =*(new Cell('L',2 i));
		possibilities[1][i][0] =*(new Cell('L', i 0));
		possibilities[2][1][i] =*(new Cell('L',1,i));
		possibilities[3][i][1] =*(new Cell('L',i 1));
	}
	current = possibilities[pos];
}


