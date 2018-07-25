#include "graphicsdisplay.h"
#include "window.h"
#include <string>
using namespace std;

GraphicsDisplay::GraphicsDisplay(){
	xw.fillRectangle(0,0,330,900,1);

	xw.fillRectangle(0,820,330,80,0);
	xw.drawBigString(0,850,"QUADRIS", 1);
        xw.drawBigString(0,875,"By: Peter, Gursirat, and Ayman",1);
}

void GraphicsDisplay::restart(){
	xw.fillRectangle(0,0,330,900,1);

	xw.fillRectangle(0,820,330,80,0);
	xw.drawBigString(0,850,"QUADRIS", 1);
        xw.drawBigString(0,875,"By: Peter, Gursirat, and Ayman",1);
}
void GraphicsDisplay::notify(Cell &whoNotified){
        int r = whoNotified.getR();
        int c = whoNotified.getC();
        char type = whoNotified.getType();
	int cSize = 30;
	/*
	enum { // Available colours
                Black=0, White, Red,
                Green, Blue, Cyan,
                Yellow, Magenta, Orange,
                Brown, PapayaWhip, Tomato,
        DarkOrange, LightSalmon, YellowGreen,
        PowderBlue, CadetBlue, DarkSlateGray,
        Grey19
        };
	*/	
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
	xw.fillRectangle(0,640,330,180,0);
	level = whoNotified.getLevel();
        score = whoNotified.getScore();
        hiscore = whoNotified.getHscore();
	string s = "Level: ";
	xw.drawBigString(15,20,s,1);
	string slevel = to_string(level);
	xw.drawBigString(110,20,slevel,1);
	
	string s1 = "Score: ";
	xw.drawBigString(15,40,s1,1);
	string sscore = to_string(score);
	xw.drawBigString(110,40, sscore, 1);

	string s2 = "Hi Score: ";
	xw.drawBigString(15,60,s2,1);
	string shiscore = to_string(hiscore);
	xw.drawBigString(110,60,shiscore,1);

	xw.drawBigString(0,660,"Next:", 1);	
        newblockdim = whoNotified.getnewBlockDim();
	int start = 680;//start at 680
	int cSize = 30;
        for(int i =0; i< 4; ++i){ //read in new block
                for(int j = 0; j<4; ++j){
                        if(i>= newblockdim || j>=newblockdim){
				xw.fillRectangle(cSize*j,start+cSize*i,cSize,cSize,0);
                        }
                        else{
                                char type = whoNotified.getnewBlock(i,j);
                        	if(type == 'S'){
                			xw.fillRectangle(j*(cSize), i*(cSize)+start, cSize, cSize, 8);
        			}
        			else if (type == 'I'){
                			xw.fillRectangle(j*(cSize), i*(cSize)+start-60, cSize, cSize,5);
        			}
        			else if (type == 'Z'){
                			xw.fillRectangle(j*(cSize), i*(cSize)+start, cSize, cSize,4);
        			}
        			else if (type == 'T'){
                			xw.fillRectangle(j*(cSize), i*(cSize)+start, cSize, cSize,3);
       				 }
        			else if (type == 'L'){
                			xw.fillRectangle(j*(cSize), i*(cSize)+start, cSize, cSize,2);
        			}
        			else if (type == 'O'){
                			xw.fillRectangle(j*(cSize), i*(cSize)+start, cSize, cSize,6);
        			}
        			else if (type == 'J'){
                			xw.fillRectangle(j*(cSize), i*(cSize)+start, cSize, cSize,7);
        			}
				else{
					xw.fillRectangle(j*(cSize), i*(cSize) +start, cSize, cSize, 0);
				}

			}
                }
        }
}


