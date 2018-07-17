#include "tblock.h"
#include "block.h"
TBlock::TBlock(): Block{3,4} {
	//   // t//   //t
	//ttt//tt// t //tt
	// t // t//ttt//t
	possibilities[0][2][1]=*(new Cell('T', 2, 1));
	possibilities[1][1][0]=*(new Cell('T', 1, 0));
	possibilities[2][1][1]=*(new Cell('T', 1,1));
	possibilities[3][1][1] = *(new Cell('T',1,1));
	for (int i = 0; i < 3; ++i) {
		possibilities[0][1][i] = *(new Cell('T',1,i));
	}
	for (int i = 0; i < 3; ++i) {
		possibilities[1][i][1] = *(new  Cell('T',i,1));
	}
	for (int i = 0; i < 3; ++i) {
		possibilities[2][2][i] = *(new Cell('T',2,i));
	}
	for (int i = 0; i < 3; ++i) {
		possibilities[3][i][0] = *(new Cell('T',i,0));
	}
	current = possibilities[pos];
}
