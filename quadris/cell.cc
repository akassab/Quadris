#include "cell.h"
#include <string>
#include <iostream>
using namespace std;

Cell::Cell(int r, int c):  r{r}, c{c}, type{' '}, set{false} {}


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

void Cell::setcell(bool flag){
	cout << "row: " << r << "col: " << c << endl;
	set = flag;
}

bool Cell::getSet(){
	return set;
}

int Cell::getR(){
	return r;
}

int Cell::getC(){
	return c;
}

void Cell::setType(char type){
	this->type = type;
	notifyObservers();
}

void Cell::setId(int i) {
	id = i;
}

int Cell::getId() {
	return id;
}


