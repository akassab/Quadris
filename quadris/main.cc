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
	
	while(true){
		cin>>cmd;
		if(cmd == "left"){
			b->left();
		}
		else if (cmd == "right"){
			b->right();
		}
		else if (cmd == "down"){
			b->down();
		}
		else if (cmd == "clockwise"){
			b->clockwise();
		}
		else if (cmd == "counterclockwise"){
			b->cclockwise();
		}
		else if (cmd == "drop"){
			b->drop();
		}
		else if (cmd == "levelup"){
			b->levelup();
		}
		else if (cmd == "leveldown"){
			b->leveldown();
		}
		else if (cmd == "restart"){
			b->init();
		}
		b->print();
	}
}
