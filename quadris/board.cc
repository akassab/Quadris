#include "block.h"
#include "board.h"
#include "textdisplay.h"
#include "newblock.h"
#include "score.h"
#include "subject.h"
#include "observer.h"
#include "cell.h"
using namespace std;


void Board::init(bool newseed,  int seed, int level, string scriptfile){
	starcounter = 0;
	id = 0;
	blockids.clear();
	score = 0;
	this->level = level;
	delete td;
	(*this).detach(td);
	td = new TextDisplay();
	(*this).attach(td);
	if(ob){
		(*this).attach(ob);
	}
	if(s){
		s->restart(); //to preserve the high score functionality
	}
	else{
		s = new Score();
	}
	delete nb;
	nb = new newBlock();
	if(newseed == true){
		nb->changeSeed(seed);
	}
	nb->newseqn(scriptfile);
	newBlk = nb->generatenew();
	current = Block::Create(newBlk);
	current -> setLevel(level);
	board.clear();	
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
			if(ob){
				board[i][j].attach(ob);
			}
		}
	}
	putonBoard();
	newBlk = nb->generatenew();
	newblock = Block::Create(newBlk);
	newblock -> setLevel(level);
	notifyObservers(); //so that textdisplay knows new block
}

void Board::setObserver(Observer *ob){
	this->ob = ob;
}

void Board::print(){
	cout << (*td);
}

void Board::right(int mult){
	int r = current->getR();
	int c = current->getC();
	int counter = 0;
	for(int i = 0; i< mult ;++i){
		current->right();
		c = current->getC();
		if(checkFit()){
			if(i == 0){
				removeBlock(r,c-1);
			}
			counter ++;
		}
		else{
			//cout << "left" << endl;
			current->left();
		}
		if(i == mult-1 && current->isHeavy() && (counter>0)){
			//cout << "heavy" << endl;
			down(false);
		}
		else if (i==mult-1 && (counter>0)){
			//cout << "place on board" << endl;
			putonBoard();
		}
	}
		
}




void Board::left(int mult){
	int r = current->getR();
        int c = current->getC();
        int counter = 0;
        for(int i = 0; i< mult ;++i){
                current->left();
                c = current->getC();
                if(checkFit()){
                        if(i == 0){
                                removeBlock(r,c+1);
                        }
                        counter ++;
                }
                else{
                        //cout << "left" << endl;
                        current->right();
                }
                if(i == mult-1 && current->isHeavy() && (counter>0)){
                        //cout << "heavy" << endl;
                        down(false);
                }
                else if (i==mult-1 && (counter>0)){
                        //cout << "place on board" << endl;
                        putonBoard();
                }
        }
}
void Board::down(bool flag, int mult){
	int r = current->getR();
        int c = current->getC();
        int counter = 0;
	cout << "mult: " << mult << endl;
        for(int i = 0; i< mult ;++i){
                current->down();
                r = current->getR();
                if(checkFit()){
                        if(i == 0){
                                removeBlock(r-1,c);
                        }
                        counter ++;
                }
                else{
                        current->up();
                }
                if(i == mult-1 && current->isHeavy() && (counter>0) && flag){
                        down(false);
                }
                else if (i==mult-1 && (counter>0)){
                        putonBoard();
                }
        }
}

bool Board::drop(int mult){
	for(int i = 0; i< mult; i++){
	droponBoard();//set the current Block on the board
	blockids.push_back(4);
	id++;
	int rows = checkRows();//check for completed rows
	if(rows!=0){
		s->genScoreRows(rows);
		score = s->getScore();
		notifyObservers(); //only notify display observers if score changes
	}
	if(rows == 0 && level == 4){
		starcounter ++ ;
	}
	else{
		starcounter = 0;
	}		
	delete current; //get rid of current block
	if(starcounter == 5){
		starcounter = 0;
		dropstar();
	}
	current = newblock; //create the new current block
	if(!checkFit()){
		return false; //the game is over!
	}
	//checkRows();
	newBlk = nb->generatenew(); //generate new newblock
	newblock = Block::Create(newBlk);
	newblock -> setLevel(level);
	putonBoard(); //place new current on top left of board
	notifyObservers();
	}
	return true;
}

void Board::dropstar(){
	for(int r = 3; r< 19; ++r){
		if(isFull(r,5) == true){
			board[r-1][5].setType('*');
			board[r-1][5].setcell(true);
			board[r-1][5].setLevel(-1);
			board[r-1][5].setId(-1);
			break;
		}
	}
	int rows = checkRows();//check for completed rows
        if(rows!=0){
                s->genScoreRows(rows);
                score = s->getScore();
		notifyObservers();
        }

}
int Board::checkRows(){
	int counter = 0; //how many full rows there are
	int lastemptyrow = 0;
	bool flag = false;
	for(int i = 0; i< 18; i++){
		int counter2 = 0; //how many items in row are full
		for(int j = 0; j<11; j++){
			if(isFull(i,j)){
				counter2 ++;
			}
		}
		if(counter2==0 && flag == false){lastemptyrow = i;}
		else{
			flag = true;
		}
		if(counter2 == 11){ //if all cells in row are full
			for(int c = 0; c<11; ++c){ //delete the row from board
				if(board[i][c].getSet() && board[i][c].getType() != '*'){		//only for ones set concretely on board
					blockids.at(board[i][c].getId()) --;
					if(blockids.at(board[i][c].getId()) == 0){
						s->genScoreBlock(board[i][c].getLevel());
					}
				}
				board[i][c].setType(' ',false);
				board[i][c].setcell(false);
			}
			for(int k = i-1; k>=0; k--){ 				//push everything down one
				for(int c = 0; c<11; ++c){
					if(board[k][c].getSet()){
						board[k+1][c].setType(board[k][c].getType(),false);//copy row down one
						board[k+1][c].setcell(true);
						board[k+1][c].setLevel(board[k][c].getLevel());
						board[k+1][c].setId(board[k][c].getId());
					}
					board[k][c].setType(' ',false);//delete from original position
					board[k][c].setcell(false);
					board[k][c].setId(-1);
					board[k][c].setLevel(-1);
				}
				
			}
			counter ++;	
		}
	}
	cout << "lastemptyrow" << lastemptyrow << endl;
	if(counter>0){
		for(int i = lastemptyrow+1; i<18; ++i){
			for(int j = 0; j<11; ++j){
				board[i][j].notifyObservers();
			}

		}
	}
		
	return counter;
}
				

void Board::clockwise(int mult){
	int counter = 0;
	for(int i = 0; i< mult; ++i){
		current->rotateClockwise();
		if (checkFit()) {
			counter ++;
		}
		else {
			current->rotateCounterClockwise();
		}
		if(current->isHeavy() && i == mult-1 && counter>0){
			int r = current->getR();
			int c = current->getC();
			current->down();
			if(checkFit()){
				for(int i =0; i<counter; ++i){
					current->rotateCounterClockwise();
				}
				removeBlock(r,c);
				for(int i =0; i<counter; ++i){
					current->rotateClockwise();
				}
				putonBoard();	
			}
			else{
				current->up();
				putonBoard(false,true);
			}
		}
		else if (i == mult-1 && counter>0){
			putonBoard(false,true);
		}
	}
}

void Board::cclockwise(int mult){
	int counter = 0;
        for(int i = 0; i< mult; ++i){
                current->rotateCounterClockwise();
                if (checkFit()) {
                        counter ++;
                }
                else {
                        current->rotateClockwise();
                }
                if(current->isHeavy() && i == mult-1 && counter>0){
                        int r = current->getR();
                        int c = current->getC();
                        current->down();
                        if(checkFit()){
                                for(int i =0; i<counter; ++i){
                                        current->rotateClockwise();
                                }
                                removeBlock(r,c);
                                for(int i =0; i<counter; ++i){
                                        current->rotateCounterClockwise();
                                }
                                putonBoard();
                        }
                        else{
                                current->up();
                                putonBoard(false,true);
                        }
                }
                else if (i == mult-1 && counter>0){
                        putonBoard(false,true);
                }
        }

	/*
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
	*/
}


void Board::random(){
	if(level == 3 || level == 4){
		nb->rando();
	}
}

void Board::norandom(string s){
	if(level == 3 || level == 4){
		nb->norandom(s);
		delete newblock;
		newBlk = nb->generatenew();
		newblock = Block::Create(newBlk);
		newblock -> setLevel(level);
		notifyObservers();
	}
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

void Board::levelup(int mult){
	for(int i = 0; i < mult; ++i){
		level ++;
	}
	s->setLvl(level);//notify score object
	nb->setLvl(level);//notify newblock object
	notifyObservers();	

}

void Board::leveldown(int mult){
	for(int i =0; i<mult; ++i){
		level --;
	}
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
        cout << "col: " << c << endl;
	int dim = current->getDim();
	r = r - dim + 1;
        for (int i = 0; i < dim; ++i) {
                for (int j = 0; j < dim; ++j) {
                        char chr = current->getChar(i,j);
                        if (chr != ' ') {
				//cout << "char" << chr << endl;
                                //cout << "row: " << r+i << "col: " << c+j << endl;
				board[r+i][c+j].setType(' ');
				//cout << "char" << chr << endl;
                                board[r+i][c+j].setId(id);
                        }
                }
        }
	


}




void Board::droponBoard(){
	int counter = 0;
	while(true){
		current->down();
        	int r = current->getR();
        	int c = current->getC();
        	if(checkFit()){
			if(counter == 0){
                		removeBlock(r-1,c);
        		}
		}
		else{
			current->up();
			break;
		}
		counter ++;
	}
	putonBoard(true,false);
	/*
	while(true){
		int r = current->getR();
		down();
		int r2 = current->getR();
		if(r == r2 || r == 0){
			break;
		}
	}
	putonBoard(true,false); //place on board concretely
	*/
}

int Board::getLevel(){
	return level;
}

int Board::getScore(){
	return s->getScore();
}

void Board::replace(char c){
	int row = current->getR();//original coordinates
	int col = current->getC();
	Block *tmp = Block::Create(c);
	Block *tmp1 = current;
	current = tmp;
	current->setR(row);
	current->setC(col);
	
	if(checkFit()){
		current = tmp1;
		removeBlock(row,col);
		current = tmp;
		current->setLevel(tmp1->getLevel());
		delete tmp1;
		putonBoard();
		notifyObservers();
	}
	else{
		current = tmp1;
		delete tmp;
	}
}

int Board::getHscore(){
	return s->getHscore();
}

char Board::getnewBlock(int r, int c){
	return newblock->getChar(r , c);
}

int Board::getnewBlockDim(){
	return newblock->getDim();
}

Board::~Board(){
	delete td;
	delete ob;
	delete current;
	delete newblock;
	delete nb;
	delete s;
}	
