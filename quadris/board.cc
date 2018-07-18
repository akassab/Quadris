#include "block.h"
#include "board.h"

using namespace std;
/*
Board::Board() {
	board.resize(22);
	for (int i = 0; i < 22; ++i) {
		board[i].resize(13);
	}
}
*/

Board::init(){
	score = 0;
	level = 0;
	delete s;
	s = new Score();
	delete nb;
	nb = new newBlock();
	newBlk = nb->getnewBlk;
	Block::create(newBlk);	
	for(unsigned int i =0; i<18; ++i){ //create new board
		vector<Cell> row;
		for(unsigned int j = 0; j<11; ++j){
			row.push_back(Cell(i,j));
		}
		board.push_back(row)
	}

}

/*
void Board::print() {
	for (int i = 0; i < 4; ++i) {
		if (i == 1) {
			cout << "-Level:    " << 1 << "-" << endl;
		}
		else if (i == 2) {
			cout << "-Score:    " << 0 << "-" << endl;
		}
	else if (i == 3) {
			cout << "-Hi Score  " << 0 << "-" << endl;
		}	
		}
	cout << endl;
	current->printCurrent();
	}


void Board::newBlock(Block *b) {
	current = b;
}


void Board::clearNew() {
	for (int i = 0; i < 4; ++i) {
		for (int r = 0; r < 11; ++r) {
			board[i][r] = *(new Cell());
		}
	}
}

*/

void Board::right(){
	current->right();
	if(current->checkFit(this)){
		notifyObservers();
	}
	else{
		current->left();
	}
}


void Board::left(){
	current->left();
	if(current->checkFit(this)){ //check if block movement fits in board
		notifyObservers();
	}
	else{
		current->right();
	}
}
void Board::down(){
	current->down();
	if(current->checkFit(this)){
		notifyObservers();
	}
	else{
		current->up();
	}
}

void Board::drop(){
	setonBoard();//set the current Block on the board
	delete current;
	current = Block::create(newBlk);
	checkLost(); //check if new current fits on top of board
	nb->generatenew();
	newBlk = nb->getnewBlk();
	
}

void changeNextBlk(char type){
	nb->replace(type);
	notifyObservers();
}

void random(bool random){
	s->random(random);
}
