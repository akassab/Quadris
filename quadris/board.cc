#include "block.h"
#include "board.h"
#include "newblock.h"
#include "score.h"
#include "subject.h"
#include "observer.h"
#include "cell.h"
using namespace std;
/*
Board::Board() {
	board.resize(22);
	for (int i = 0; i < 22; ++i) {
		board[i].resize(13);
	}
}
*/

void Board::init(){
	score = 0;
	level = 0;
	delete s;
	s = new Score();
	delete nb;
	nb = new newBlock();
	newBlk = nb->getnewBlk();
	// Ayman needs clarifcation here
	current = Block::Create(newBlk);	
	for(unsigned int i =0; i<18; ++i){ //create new board
		vector<Cell> row;
		for(unsigned int j = 0; j<11; ++j){
			row.push_back(Cell(i,j));//push row onto board
		}
		board.push_back(row);
	}

}

/*
void Board::print() {
	for (int i = 0; i < 18; ++i) {
		for (int j = 0; j < 11; ++j) {
			cout << board[i][j];
		}
		cout << endl;
	}
}



void Board::clearNew() {
	for (int i = 0; i < 4; ++i) {
		for (int r = 0; r < 11; ++r) {
			board[i][r] = ' ';
		}
	}
}
*/


void Board::right(){
	current->right();
	if(checkFit()){
		notifyObservers();
	}
	else{
		current->left();
	}
}


void Board::left(){
	current->left();
	if(checkFit()){ //check if block movement fits in board
		notifyObservers();
	}
	else{
		current->right();
	}
}
void Board::down(){
	current->down();
	if(checkFit()){
		notifyObservers();
	}
	else{
		current->up();
	}
}

void Board::drop(){
	droponBoard();//set the current Block on the board
	delete current;
	current = Block::Create(newBlk);
	if(checkFit()){
		nb->generatenew();
		newBlk = nb->getnewBlk();
	}
	else{
		//end game
	}
}

void Board::clockwise(){

}

void Board::cclockwise(){

}

void Board::changeNextBlk(char type){
	nb->replace(type);
	notifyObservers();
}

void Board::random(bool random){
	nb->rand(random);
}

bool Board::checkFit(){
	int dim = current->getDim();
	vector<vector<char>> coords;
	coords = current->getCurrent();
	int r = current->getR();
	int c = current->getC();
	for(int i =0; i< dim; ++i){
		for(int j = 0; j<dim; ++j){
			if(isFull(i+r, j+c) && coords[i][j] != ' '){
				return false;
			} 
		}
	}
	return true;
}

bool Board::isFull(int r, int c){
	// ayman adding stuff here
	if(r>17 || r<0 || c>10 || c<0){
		return false;
	}
	if(board[r][c].getType() == ' '){
		return false;
	}else{
		return true;
	}
}

void Board::levelup(){
	level ++;
	

}

void Board::leveldown(){
	level --;

}


	
//Ayman setonBoard was supposed to drop on board not just set it on
void Board::putonBoard(){
	// ayman adding stuff here
	int dim = current->getDim();
	vector<vector<char>> coords;
	coords = current->getCurrent();
	int r = current->getR();
	int c = current->getC();
	for (int i = 0; i < dim; ++i) {
		for (int j = 0; j < dim; ++j) {
			if (coords[i][j] != ' ') {
				board[r+i][c+j].setType(coords[i][j]);
			}
		}
	}
}

void Board::droponBoard(){
	int c = current->getC();
	int r = current->getR();
	while(true){
		c --;
		if(!checkFit() || c<0){
			break;
		}
	}
	c++;

}

int Board::getLevel(){
	return level;
}

int Board::getScore(){
	return s->getScore();
}	
