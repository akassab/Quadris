#include "cell.h"

Cell::Cell(int x, int y): x{x}, y{x},type{' '} {

}



Cell::~Cell() {
}

Cell::Cell(char t) {
	type = t;
}

char Cell::getType() {
	return type;
}

void Cell::setX(int x){
	x = x;
}

void Cell::setY(int y){
	y = y;
}

int Cell::getX(){
	return x;
}

int Cell::getY(){
	return y;
}

void Cell::setType(char type){
	this->type = type;
}

