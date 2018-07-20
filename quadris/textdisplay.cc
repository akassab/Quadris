#include "textdisplay.h"
#include "board.h"
#include "subject.h"
#include <iostream>
#include <string>
using namespace std;

void TextDisplay::notify(Board &whoNotified){
	level = whoNotified.getLevel();
	score = whoNotified.getScore();
}

void TextDisplay::notify(Cell &whoNotified){
	int r = whoNotified.getR();
	int c = whoNotified.getC();
	char type = whoNotified.getType();
	theDisplay[r][c] = type;
}

void TextDisplay::notify(Subject &whoNotified){
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
			out << td.theDisplay[i][j];
		}
		out << endl;
	}	
	out << "-----------" << endl;
	
	return out;

}

TextDisplay::TextDisplay(){
	for(int i =0; i< 18; ++i){
		vector<char> row; //Create empty row
		for(int j =0 ; j< 11; ++j){
			row.push_back(' '); //add empty cells to display
		}
		theDisplay.push_back(row); //add row to theDisplay
	}
}
