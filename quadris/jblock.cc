#include "jblock.h"
#include "block.h"

JBlock::JBlock(): Block{3,4} {
	
	// j
	// j j j
	possibilities[0][1][0] = *(new Cell('J',1,0));
	possibilities[1][0][1] = *(new Cell('J',0,1));
	possibilities[2][2][2] = *(new Cell('J',2,2));
	possibilities[3][2][0] = *(new Cell('J',2, 0));
	for (int i = 0; i < 3; ++i) {
		possibilities[0][2][i] = *(new Cell('J',2 i));
		possibilities[1][i][0] = *(new Cell('J',i, 0));
		possibilities[2][1][i] = *(new Cell('J',1,i));
		possibilities[3][i][1] = *(new Cell('J',i, 1));
	}
	current = possibilities[pos];
		 // 0 , 1 0
		// 0 ,1  , 1
		// 0 , 1 , 2
	// j j 
	// j
	// j
	
	//
	// j j j
	//     j

	//   j
	//   j
	// j j

		
}


