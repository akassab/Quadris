#ifndef CELL_H
#define CELL_H
class Cell {
	char type;
	int r,c;
	public:
	explicit Cell(int r, int c);

	~Cell();
	explicit Cell(char t);
	char getType();
	void setType(char type);
	void setR(int r);
	void setC(int c);
	int getR();
	int getC();

	
};
#endif
