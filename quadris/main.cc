#include "board.h"
#include "iblock.h"
#include "jblock.h"
#include "lblock.h"
#include "zblock.h"
#include "tblock.h"
#include "oblock.h"
#include "sblock.h"
#include "interp.h"
#include "graphicsdisplay.h"
#include <iostream>
#include <string>


using namespace std;
int main() {
	Board *b = new Board();	
	GraphicsDisplay *grd = new GraphicsDisplay();
	b->setObserver(grd);
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
		//for(int c = mult; c>0; --c){
		int c = 1;		
		if(val == "left" && game){
			b->left(mult);
		}
		else if (val == "right"&& game){
			b->right(mult);
		}
		else if (val == "down" && game){
			b->down(mult);
		}
		else if (val == "clockwise" && game){
			b->clockwise(mult);
		}
		else if (val == "counterclockwise" && game){
			b->cclockwise(mult);
		}
		else if (val == "drop" && game){
			game = b->drop();
		}
		else if (val == "levelup" && game){
			b->levelup(mult);
		}
		else if (val == "leveldown" && game){
			b->leveldown(mult);
		}
		else if (val == "restart"){
			b->init();
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
		
		//}		
		if(game){
			b->print();
		}
	}
}
