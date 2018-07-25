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
	cin.exceptions(ios::eofbit);
	bool game = true;
	Board *b = new Board();	
	GraphicsDisplay *grd = new GraphicsDisplay();
	b->setObserver(grd);
	Interp *i = new Interp();
	i->init();
	b->init();
	string cmd;
	b->print();
//	bool game = true; //if game is not over
	try{
	while(true){
		int mult;
		if(!(cin>>mult)){
			cin.clear();
			mult = 1;
		}
		cin>>cmd;
		string val = i->interpret(cmd);
		if(val == "left"){
			b->left(mult);
		}
		else if (val == "right"){
			b->right(mult);
		}
		else if (val == "down"){
			b->down(mult);
		}
		else if (val == "clockwise"){
			b->clockwise(mult);
		}
		else if (val == "counterclockwise"){
			b->cclockwise(mult);
		}
		else if (val == "drop"){
			game = b->drop(mult);
		}
		else if (val == "levelup"){
			b->levelup(mult);
		}
		else if (val == "leveldown"){
			b->leveldown(mult);
		}
		else if (val == "restart"){
			grd->restart();
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
		else if (val == "random"){
			b->random();
		}
		else if (val == "norandom"){
			string s;
			cin >> s;
		}
		if(game){
			b->print();
		}
		else{
			grd->restart();
			b->init();
			b->print();
		}
	}
	}
	catch (ios::failure &) {}
}
