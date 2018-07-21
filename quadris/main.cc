#include "board.h"
#include "iblock.h"
#include "jblock.h"
#include "lblock.h"
#include "zblock.h"
#include "tblock.h"
#include "oblock.h"
#include "sblock.h"
#include <iostream>
#include <string>

using namespace std;
int main() {
	Board *b = new Board();	
	b->init();
	string cmd;
	b->print();
	bool game = true; //if game is not over
	while(true){
		cin>>cmd;
		if(cmd == "left" && game){
			b->left();
		}
		else if (cmd == "right"&& game){
			b->right();
		}
		else if (cmd == "down" && game){
			b->down();
		}
		else if (cmd == "clockwise" && game){
			b->clockwise();
		}
		else if (cmd == "counterclockwise" && game){
			b->cclockwise();
		}
		else if (cmd == "drop" && game){
			game = b->drop();
		}
		else if (cmd == "levelup" && game){
			b->levelup();
		}
		else if (cmd == "leveldown" && game){
			b->leveldown();
		}
		else if (cmd == "restart"){
			b->init();
		}
		if(game){
			b->print();
		}
	}
}
