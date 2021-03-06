#include "textdisplay.h"
#include "board.h"
#include "subject.h"
#include <iostream>
#include <string>
using namespace std;

void TextDisplay::notify(Board &whoNotified){
	level = whoNotified.getLevel();
	score = whoNotified.getScore();
	hiscore = whoNotified.getHscore();
	newblockdim = whoNotified.getnewBlockDim();
	for(int i =0; i< 4; ++i){ //get newBlock
		for(int j = 0; j<4; ++j){
			if(i>= newblockdim || j>=newblockdim){
				nbDisplay[i][j] = ' ';
			}
			else{
				nbDisplay[i][j] = whoNotified.getnewBlock(i,j);
			} 
		}
	}
}

void TextDisplay::notify(Cell &whoNotified){
	int r = whoNotified.getR();
	int c = whoNotified.getC();
	char type = whoNotified.getType();
	theDisplay[r][c] = type;
}

void TextDisplay::notify(Subject &whoNotified){ //dynamic casting to determine which subclass
		Subject* subptr = &whoNotified;
                if(Board* b = dynamic_cast<Board *>(subptr)){
                        notify(*b);
                }else if (Cell* c = dynamic_cast<Cell *>(subptr)){
                        notify(*c);
                }
}


ostream &operator<<(ostream &out, const TextDisplay &td){
	out << "Level:   " << td.level << endl;
	out << "Score:   " << td.score << endl;
	out << "Hi Score: " << td.hiscore << endl;
	out << "-----------" << endl;

	for(int i = 0; i< 18; ++i){
		for(int j = 0; j< 11; ++j){
			out << td.theDisplay[i][j]; //parse through board, adding to out stream
		}
		out << endl;
	}	
	out << "-----------" << endl;
	out << "Next:" << endl;
	for (int c = 0; c<4; ++c){ //add new block to out stream
		bool flag = true;
		for(int a = 0; a<4; ++a){
			if(td.nbDisplay[c][a] != ' '){
				flag = false;
			}
		}
		if(!flag){ //if the row is empty, then ignore it
		for(int d = 0; d<4; ++d){
			out << td.nbDisplay[c][d];
		}
		out << endl;
		}
	}
	return out;

}

TextDisplay::TextDisplay(){
	level = 0;
	score = 0;
	hiscore = 0;
	for(int i =0; i< 18; ++i){
		vector<char> row; //Create empty row
		for(int j =0 ; j< 11; ++j){
			row.push_back(' '); //add empty cells to display
		}
		theDisplay.push_back(row); //add row to theDisplay
	}
	for(int c = 0; c< 4; ++c){ //initializing the newblock 
		vector<char> row;
		for(int d = 0; d< 4; ++d){
			row.push_back(' ');
		}
		nbDisplay.push_back(row);
	}
	
}
