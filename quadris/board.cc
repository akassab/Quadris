#include "block.h"
#include "board.h"
#include "textdisplay.h"
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
	id = 0;
	score = 0;
	level = 0;
	delete td;
	(*this).detach(td);
	td = new TextDisplay(); 
	(*this).attach(td);
	delete s;
	s = new Score();
	delete nb;
	nb = new newBlock();
	newBlk = nb->generatenew();
	// Ayman needs clarifcation here
	current = Block::Create(newBlk);
	for(unsigned int i =0; i<18; ++i){ //create new board
		vector<Cell> row;
		for(unsigned int j = 0; j<11; ++j){
			row.push_back(Cell(i,j));//push row onto board
			
		}
		board.push_back(row);
	}
	for(unsigned int i = 0; i<18; ++i){
		for(unsigned int j = 0; j<11; ++j){
			board[i][j].attach(td);
		}
	}
	putonBoard();
	newBlk = nb->generatenew();
}

void Board::print(){
	cout << (*td);
}


/*

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
	int r = current->getR();
	int c = current->getC();
	if(checkFit()){
		removeBlock(r,c-1);
		putonBoard();
		
	}
	else{
		current->left();
	}
}




void Board::left(){
	current->left();
	int r = current->getR();
	int c = current->getC();
	if(checkFit()){ //check if block movement fits in board
		removeBlock(r,c+1);
		putonBoard();
	}
	else{
		current->right();
	}
}
void Board::down(){
	current->down();
	int r = current->getR();
	int c = current->getC();
	if(checkFit()){
		removeBlock(r-1,c);
		putonBoard();
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
		newBlk = nb->generatenew();
	}
	else{
		//end game
	}
}

void Board::clockwise(){
	current->rotateClockwise();
	if (checkFit()) {
		putonBoard();
	}
	else {
		current->rotateCounterClockwise();
	}
}

void Board::cclockwise(){
	current->rotateCounterClockwise();
	if (checkFit()) {
		putonBoard();
	}
	else {
		current->rotateCounterClockwise();
	}
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
	//vector<vector<char>> coords;
	//coords = current->getCurrent();
	int r = current->getR();
	int c = current->getC();
	for(int i =0; i< dim; ++i){
		for(int j = 0; j<dim; ++j){
			if(isFull(i+r, j+c) && current->getChar(i,j) != ' '){
				return false;
	
			} 
		}
	}
	return true;
}

bool Board::isFull(int r, int c){
	//cout << "r is: " << r << "c is: " << c << endl;
	if(r>17 || r<0 || c>10 || c<0){
		return true;
	}
	if(board[r][c].getType() == ' '){
		return false;
	}
		
	if (board[r][c].getId() == id) {
		return false;
	}
	
	
	
	else{
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
	int r = current->getR();
	cout<<r<<endl;
	int c = current->getC();
	cout<<c<<endl;
	for (int i = 0; i < dim; ++i) {
		for (int j = 0; j < dim; ++j) {
			char chr = current->getChar(i,j);
			if(!((r+i)>17 || (c+j) >10 || (r+i) < 0 || (c+j) < 0)) {
				
				board[r+i][c+j].setType(chr);
				board[r+i][c+j].setId(id);
			
			}
		}
	}
}

void Board::removeBlock(int r, int c){
// ayman adding stuff here
        int dim = current->getDim();
        for (int i = 0; i < dim; ++i) {
                for (int j = 0; j < dim; ++j) {
                        char chr = current->getChar(i,j);
                        if (chr != ' ') {
                                board[r+i][c+j].setType(' ');
                                board[r+i][c+j].setId(id);
                        }
                }
        }
	


}




void Board::droponBoard(){
	while(true){
		int r = current->getR();
		down();
		int r2 = current->getR();
		if(r!=r2){
			break;
		}
	}

}

int Board::getLevel(){
	return level;
}

int Board::getScore(){
	return s->getScore();
}

	
