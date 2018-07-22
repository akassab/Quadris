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
}

void Board::print(){
	cout << (*td);
}

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

bool Board::drop(){
	droponBoard();//set the current Block on the board
	int rows = checkRows();//check for completed rows
	s->genScoreRows(rows);
	score = s->getScore();	
	if(rows!=0){
		notifyObservers();
	}
	delete current;
	current = Block::Create(newBlk); //create the new current block
	if(!checkFit()){
		return false; //the game is over!
	}
	checkRows();
	newBlk = nb->generatenew(); //generate new newblock
	putonBoard(); //place new current on top left of board
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
				

void Board::clockwise(){
	current->rotateClockwise();
	if (checkFit()) {
		putonBoard(false, true);
	}
	else {
		current->rotateCounterClockwise();
	}
}

void Board::cclockwise(){
	current->rotateCounterClockwise();
	if (checkFit()) {
		putonBoard(false, true);
	}
	else {
		current->rotateCounterClockwise();
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
	if(r>17 || r<0 || c>10 || c<0){
		return true;
	}
	if(!(board[r][c].getSet())){
		
		return false;
	}
	else if (board[r][c].getId() == id) {
		return false;
	}
	else{
		cout << "i fuckedu " << endl;
		return true;
	}
		





}

void Board::levelup(){
	level ++;
	s->setLvl(level);
	nb->setLvl(level);
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
					if(chr != ' '){
						board[r+i][c+j].setType(chr);
						if(flag){
							board[r+i][c+j].setcell(true);
						}
					}
				}
				else{
					board[r+i][c+j].setType(chr);

				}
				board[r+i][c+j].setId(id);
			
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
	int c = current->getC();
	cout << "hi" << endl;
	while(true){
		int r = current->getR();
		down();
		int r2 = current->getR();
		if(r == r2 || r == 0){
			cout << "r is: " << r<< " r2 is: " << r2 << endl;
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
	notifyObservers();
}	
