#include "lblock.h"
#include "block.h"

LBlock::LBlock(): Block{3,4} {
	r = 4;
	c = 0;

	// 	//L  //      //L L
	//     L//L  //L L L //  L
	// L L L//L L//L     //  L
	possibilities[0][1][2] = 'L'; 
	possibilities[1][2][1] = 'L';
	possibilities[2][2][0] = 'L';
	possibilities[3][0][0] = 'L';
	for (int i = 0; i < 3; ++i) {
		possibilities[0][2][i] = 'L';
		possibilities[1][i][0] = 'L';
		possibilities[2][1][i] = 'L';
		possibilities[3][i][1] = 'L';
	}
	current = possibilities[pos];
}


