#include "zblock.h"
#include "block.h"

ZBlock::ZBlock(): Block{3,2} {
	//     // z
	//z z  //zz
	//  z z//z
	possibilities[0][1][0] = *(new Cell('Z',1,0));
	possibilities[0][1][1] = *(new Cell('Z',1,1));
	possibilities[0][2][1] = *(new Cell('Z',2,1));
	possibilities[0][2][2] = *(new Cell('Z',2,2));

	possibilities[1][0][1] = *(new Cell('Z',0,1));
	possibilities[1][1][0] = *(new Cell('Z',1,0));
	possibilities[1][1][1] =*(new Cell('Z',1,1));
	possibilities[1][2][0] = *(new Cell('Z',2,0));
	current = possibilities[pos];
}

