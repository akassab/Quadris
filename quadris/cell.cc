#include "cell.h"

Cell::Cell(int x, int y): r{x}, c{x},type{' '} {

}



Cell::~Cell() {
}

Cell::Cell(char t) {
	type = t;
}

char Cell::getType() {
	return type;
}

void Cell::setR(int x){
	r = x;
}

void Cell::setC(int y){
	c = y;
}

int Cell::getR(){
	return r;
}

int Cell::getC(){
	return c;
}

void Cell::setType(char type){
	this->type = type;
}

