#include "jblock.h"
#include "block.h"

JBlock::JBlock(): Block{3,4} {
	r = 4;
	c = 0;	
	// j
	// j j j
	possibilities[0][1][0] = 'J';
	possibilities[1][0][1] = 'J';
	possibilities[2][2][2] = 'J';
	possibilities[3][2][0] = 'J';
	for (int i = 0; i < 3; ++i) {
		possibilities[0][2][i] = 'J';
		possibilities[1][i][0] = 'J';
		possibilities[2][1][i] = 'J';
		possibilities[3][i][1] = 'J';
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


