#include "cell.h"


Cell::Cell(int r, int c): r{r}, c{c}, type{' '} {}

Cell::~Cell() {
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

