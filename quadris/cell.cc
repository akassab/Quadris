#include "cell.h"

Cell::Cell(int nx, int ny): x{nx}, y{ny} {
	type = ' ';
}

Cell::~Cell() {
}

Cell::Cell(char t, int nx, int ny): x{nx}, y{ny} {
	type = t;
}

int Cell::getX() {
	return x;
}

int Cell::getY() {
	return y;
}

void Cell::setX(int n) {
	x = n;
}

void Cell::setY(int n) {
	y = n;
}

char Cell::getType() {
	return type;
}







