#include "cell.h"

Cell::Cell() {
	type = ' ';
}



Cell::~Cell() {
}

Cell::Cell(char t) {
	type = t;
}

bool Cell::isL() {
	if (type == 'L') {
		return true;
	}
	return false;
}

bool Cell::isI() {
	if (type == 'I') {
		return true;
	}
	return false;
}

char Cell::getType() {
	return type;
}







