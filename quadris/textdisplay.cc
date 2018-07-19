#include "textdisplay.h"
#include "board.h"
#include "subject.h"

using namespace std;

void TextDisplay::notify(Subject &whoNotified){
	level = whoNotified.getLevel();
	score = whoNotified.getScore();
	vector<vector<char>> board;
	board = whoNotified.getCells();
	for(int i = 0; i< 18; ++i){
		for(int j = 0; j<11; j++){
			theDisplay[i][j] = board[i][j];	
		}
	}
	
	

}

ostream &operator<<(ostream &out, const TextDisplay &td){
	out << "Level:   " << lvl << endl;
	out << "Score:   " << score << endl;
	out << "Hi Score:    " << hiscore << endl;
	out << "-----------" << endl;

	for(int i = 0; i< 18; ++i){
		for(int j = 0; j< 11; ++j){
			out << theDisplay[i][j];
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
