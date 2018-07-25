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
#include <sstream>

using namespace std;
int main(int argc, char *argv[]) {
	cin.exceptions(ios::eofbit);
	GraphicsDisplay *grd;
	bool graphics = true;
	bool newseed = false;
	string scriptf = "sequence.txt";
	int seed;
	int level = 0;
	if(argc>1){
		for(int i =1; i<argc; ++i){
		string str;
		istringstream ss(argv[i]);
		ss >> str;
		if(str == "-text"){
			graphics = false;
		}
		else if (str == "-seed"){
			istringstream ss2(argv[i+1]);
			ss2 >> seed;
			newseed = true;
		}
		else if (str == "-scriptfile"){
			istringstream ss3(argv[i+1]);
			ss3 >> scriptf;
		}
		else if (str == "-startlevel"){
			istringstream ss4(argv[i+1]);
			ss4 >> level;
		}
		}
	}
	bool game = true;
	Board *b = new Board();
	if(graphics){	
		grd = new GraphicsDisplay();
		b->setObserver(grd);
	}
	Interp *i = new Interp();
	i->init();
	b->init(newseed, seed, level, scriptf);
	string cmd;
	b->print();
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
			cout << "mult: " << mult << endl;
			b->down(true, mult);
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
			if(graphics){
				grd->restart();
			}
			b->init(newseed, seed, level, scriptf);
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
			b->norandom(s);
		}
		if(game){
			b->print();
		}
		else{
			if(graphics){
				grd->restart();
			}
			b->init(newseed, seed, level, scriptf);
			b->print();
		}
	}
	}
	catch (ios::failure &) {}
}
