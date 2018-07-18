#include "tblock.h"
#include "block.h"
TBlock::TBlock(): Block{3,4} {
	r = 4;
	c = 0;

	//   // t//   //t
	//ttt//tt// t //tt
	// t // t//ttt//t
	possibilities[0][2][1]='T';
	possibilities[1][1][0]='T';
	possibilities[2][1][1]='T';
	possibilities[3][1][1] ='T';
	for (int i = 0; i < 3; ++i) {
		possibilities[0][1][i] ='T';
	}
	for (int i = 0; i < 3; ++i) {
		possibilities[1][i][1] ='T';
	}
	for (int i = 0; i < 3; ++i) {
		possibilities[2][2][i] ='T';
	}
	for (int i = 0; i < 3; ++i) {
		possibilities[3][i][0] ='T';
	}
	current = possibilities[pos];
}
