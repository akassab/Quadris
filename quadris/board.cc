#include "block.h"
#include "board.h"
#include "textdisplay.h"
#include "newblock.h"
#include "score.h"
#include "subject.h"
#include "observer.h"
#include "cell.h"
using namespace std;


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
	nb->newseqn("sequence.txt");
	newBlk = nb->generatenew();
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
			board[i][j].attach(td);//attach textdisplay object for every cell on board
		}
	}
	putonBoard();
	newBlk = nb->generatenew();
	newblock = Block::Create(newBlk);
	notifyObservers(); //so that textdisplay knows new block
}

void Board::restart(){
	delete td;
        (*this).detach(td);
        td = new TextDisplay();
        (*this).attach(td);
		
}
void Board::print(){
	cout << (*td);
}

void Board::right(int mult){
	current->right();
	int r = current->getR();
	int c = current->getC();
	if(checkFit()){ //checks if movement fits on board
		removeBlock(r,c-1);//removes previous block
		putonBoard();//place on board
	}
	else{
		current->left();
	}
	cout << "Checkone" << endl;
	if(current->isHeavy() && mult == 1){
		cout << "Checktwo" << endl;
		down(false);
	}
}




void Board::left(int mult){
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
	if(current->isHeavy() && mult == 1){
		down(false);
	}
}
void Board::down(bool flag, int mult){
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
	if(current->isHeavy() && flag && mult == 1){
		down(false);
	}
}

bool Board::drop(){
	droponBoard();//set the current Block on the board
	int rows = checkRows();//check for completed rows
	if(rows!=0){
		s->genScoreRows(rows);
		score = s->getScore();
		notifyObservers(); //only notify display observers if score changes
	}
	delete current; //get rid of current block
	current = newblock; //create the new current block
	current->setLevel(level); //set the level of the current block
	cout << "Check1" << endl;
	if(!checkFit()){
		return false; //the game is over!
	}
	cout << "Check2" << endl;
	checkRows();
	newBlk = nb->generatenew(); //generate new newblock
	newblock = Block::Create(newBlk);
	putonBoard(); //place new current on top left of board
	notifyObservers();
	return true;
}

int Board::checkRows(){
	int counter = 0; //how many full rows there are
	for(int i = 0; i< 18; i++){
		int counter2 = 0; //how many items in row are full
		for(int j = 0; j<11; j++){
			if(isFull(i,j)){
				counter2 ++;
			}
		}
		if(counter2 == 11){ //if all cells in row are full
			for(int c = 0; c<11; ++c){ //delete the row from board
				board[i][c].setType(' ');
				board[i][c].setcell(false);
			}
			for(int k = i-1; k>=0; k--){
				for(int c = 0; c<11; ++c){
					if(board[k][c].getSet()){
						board[k+1][c].setType(board[k][c].getType());//copy row down one
						board[k+1][c].setcell(true);
					}
					board[k][c].setType(' ');//delete current row
					board[k][c].setcell(false);
				}
				
			}
			counter ++;	
		}
	}
	return counter;
}
				

void Board::clockwise(int mult){
	current->rotateClockwise();
	if (checkFit()) {
		putonBoard(false, true);
	}
	else {
		current->rotateCounterClockwise();
	}
	if(current->isHeavy() && mult == 1){
		down(false);
	}
}

void Board::cclockwise(int mult){
	current->rotateCounterClockwise();
	if (checkFit()) {
		putonBoard(false, true);
	}
	else {
		current->rotateCounterClockwise();
	}
	if(current->isHeavy() && mult == 1){
		down(false);
	}
}


void Board::random(bool random){
	nb->rando(random);
}

bool Board::checkFit(){
	int dim = current->getDim();
	int r = current->getR();
	int c = current->getC();
	r = r - dim + 1;
	for(int i =0; i< dim; ++i){
		for(int j = 0; j<dim; ++j){
			if(isFull(i+r, j+c) && current->getChar(i,j) != ' '){
				return false;
	
			} 
		}
	}
	cout << "it fits" << endl;
	return true;
}

bool Board::isFull(int r, int c){
	//cout << "r is: " << r << "c is: " << c << endl;
	if(r>17 || r<0 || c>10 || c<0){ //if it is outside boundaries return true
		return true;
	}
	if(!(board[r][c].getSet())){ //if it is not set on board, return false		
		return false;
	}
	else{
		return true;
	}
	

}

void Board::levelup(){
	level ++;
	s->setLvl(level);//notify score object
	nb->setLvl(level);//notify newblock object
	notifyObservers();	

}

void Board::leveldown(){
	level --;
	s->setLvl(level);
	nb->setLvl(level);
	notifyObservers();

}


void Board::putonBoard(bool flag, bool flag2){
	int dim = current->getDim();
	int r = current->getR();
	int c = current->getC();
	r = r - dim +1; // start from top right
	for (int i = 0; i < dim; ++i) {
		for (int j = 0; j < dim; ++j) {
			char chr = current->getChar(i,j);
			if(!((r+i)>17 || (c+j) >10 || (r+i) < 0 || (c+j) < 0)) {
				if(!flag2){ 
					if(chr != ' '){ //check to only update cells on board that aren't empty in block
						board[r+i][c+j].setType(chr);
						if(flag){
							board[r+i][c+j].setcell(true); //actually place cells onto board
							board[r+i][c+j].setLevel(current->getLevel());
							board[r+i][c+j].setId(id);
						}
					}
				}
				else{
					board[r+i][c+j].setType(chr); //update cells on board even if they are empty in block(useful for rotate)
				}
			
			}
		}
	}
}

void Board::removeBlock(int r, int c){
        int dim = current->getDim();
	r = r - dim + 1;
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
		if(r == r2 || r == 0){
			break;
		}
	}
	putonBoard(true,false); //place on board concretely

}

int Board::getLevel(){
	return level;
}

int Board::getScore(){
	return s->getScore();
}

void Board::replace(char c){
	newBlk = c;
	delete newblock;
	newblock = Block::Create(newBlk);
	notifyObservers();
}

int Board::getHscore(){
	return s->getHscore();
}

char Board::getnewBlock(int r, int c){
	return newblock->getChar(r , c);
}

int Board::getnewBlockHeight(){
	return newblock->getHeight();
}

int Board::getnewBlockDim(){
	return newblock->getDim();
}	
