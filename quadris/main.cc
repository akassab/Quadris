#include "board.h"
#include "iblock.h"
#include "jblock.h"
#include "lblock.h"
#include "zblock.h"
#include "tblock.h"
#include "oblock.h"
#include "sblock.h"
#include "interp.h"
#include <iostream>
#include <string>

using namespace std;
int main() {
	Board *b = new Board();	
	Interp *i = new Interp();
	i->init();
	b->init();
	string cmd;
	b->print();
	bool game = true; //if game is not over
	while(true){
		int mult;
		if(!(cin>>mult)){
			cin.clear();
			mult = 1;
		}
		cin>>cmd;
		string val = i->interpret(cmd);
		for(int c = 0; c<mult; ++c){
		
		if(val == "left" && game){
			b->left();
		}
		else if (val == "right"&& game){
			b->right();
		}
		else if (val == "down" && game){
			b->down();
		}
		else if (val == "clockwise" && game){
			b->clockwise();
		}
		else if (val == "counterclockwise" && game){
			b->cclockwise();
		}
		else if (val == "drop" && game){
			game = b->drop();
		}
		else if (val == "levelup" && game){
			b->levelup();
		}
		else if (val == "leveldown" && game){
			b->leveldown();
		}
		else if (val == "restart"){
			b->restart();
		}
		else if (val == "I"){
			b->replace('I');
		}
		else if (val == "J"){
			b->replace ('J');
		}
		else if (val == "L"){
			b->replace('L');
		}
		else if (val == "O"){
			b->replace('O');
		}
		else if (val == "S"){
			b->replace('S');
		}
		else if (val == "Z"){
			b->replace('Z');
		}
		else if (val == "T"){
			b->replace('T');
		}
		
		}		
		if(game){
			b->print();
		}
	}
}
