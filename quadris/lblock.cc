#include "lblock.h"
#include "block.h"

LBlock::LBlock(): Block{3,4} {
	// 	//L  //      //L L
	//     L//L  //L L L //  L
	// L L L//L L//L     //  L
	possibilities[0][1][2] = *(new Cell('L')); 
	possibilities[1][2][1] = *(new Cell('L'));
	possibilities[2][2][0] = *(new Cell('L'));
	possibilities[3][0][0] = *(new Cell('L'));
	for (int i = 0; i < 3; ++i) {
		possibilities[0][2][i] =*(new Cell('L'));
		possibilities[1][i][0] =*(new Cell('L'));
		possibilities[2][1][i] =*(new Cell('L'));
		possibilities[3][i][1] =*(new Cell('L'));
	}
	current = possibilities[pos];
}


