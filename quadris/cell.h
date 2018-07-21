#ifndef CELL_H
#define CELL_H
#include "subject.h"

class Cell : public Subject {
	int id;
	int r,c;
	char type;//the type of the cell, ' ' for empty, or a letter e.g. 'I'
	bool set; //if the piece is dropped on board yet or still being controlled by user
	public:
	explicit Cell(int r, int c);

	~Cell();
	bool getSet();
	explicit Cell(char t);
	char getType();
	void setType(char type);
	void setR(int r);
	void setC(int c);
	int getR();
	int getC();
	int getId();
	void setcell(bool flag);
	void setId(int i);	
};
#endif
