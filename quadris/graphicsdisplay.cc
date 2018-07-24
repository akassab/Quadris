#include "graphicsdisplay.h"
#include "window.h"
#include <string>
using namespace std;

GraphicsDisplay::GraphicsDisplay(){
	xw.fillRectangle(0,0,330,900,1);
}

void GraphicsDisplay::restart(){
	xw.fillRectangle(0,0,330,900,1);
}
void GraphicsDisplay::notify(Cell &whoNotified){
        int r = whoNotified.getR();
        int c = whoNotified.getC();
        char type = whoNotified.getType();
	int cSize = 30;
	//enum {White=0, Black, Red, Green, Blue, Cyan, Yellow, Magenta, Orange, Brown}
	if(type == 'S'){
		xw.fillRectangle(c*(cSize), r*(cSize)+100, cSize, cSize, 8);
	}
	else if (type == 'I'){
		xw.fillRectangle(c*(cSize), r*(cSize)+100, cSize, cSize,5);
	}
	else if (type == 'Z'){
		xw.fillRectangle(c*(cSize), r*(cSize)+100, cSize, cSize,4);
	}
	else if (type == 'T'){
		xw.fillRectangle(c*(cSize), r*(cSize)+100, cSize, cSize,3);
	}
	else if (type == 'L'){
		xw.fillRectangle(c*(cSize), r*(cSize)+100, cSize, cSize,2);
	}
	else if (type == 'O'){
		xw.fillRectangle(c*(cSize), r*(cSize)+100, cSize, cSize,6);
	}
	else if (type == 'J'){
		xw.fillRectangle(c*(cSize), r*(cSize)+100, cSize, cSize,7);
	}
	else if (type == '*'){
		xw.fillRectangle(c*(cSize), r*(cSize)+100, cSize, cSize,9);
	}
	else{
		xw.fillRectangle(c*(cSize), r*(cSize)+100, cSize, cSize,1);
	}
}

void GraphicsDisplay::notify(Subject &whoNotified){
                Subject* subptr = &whoNotified;
                if(Board* b = dynamic_cast<Board *>(subptr)){
                        notify(*b);
                }else if (Cell* c = dynamic_cast<Cell *>(subptr)){
                        notify(*c);
                }
}

void GraphicsDisplay::notify(Board &whoNotified){
	xw.fillRectangle(0,0,330,100,0);
	//cout<< "HI1" << endl;
	string s = "score: "; 
	xw.drawBigString(0,0,s);
        //cout << "HI2" << endl;
	level = whoNotified.getLevel();
        score = whoNotified.getScore();
        hiscore = whoNotified.getHscore();
        newblockheight = whoNotified.getnewBlockHeight();
        newblockdim = whoNotified.getnewBlockDim();
	/*
        for(int i =0; i< 4; ++i){
                for(int j = 0; j<4; ++j){
                        if(i>= newblockdim || j>=newblockdim){
                                nbDisplay[i][j] = ' ';
                        }
                        else{
                                nbDisplay[i][j] = whoNotified.getnewBlock(i,j);
                        }
                }
        }
	*/
}


