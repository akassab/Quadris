#ifndef CELL_H
#define CELL_H
class Cell {
	char type;
	int x,y;
	public:
	explicit Cell(int x, int y);

	~Cell();
	explicit Cell(char t);
	char getType();
	void setType(char type);
	void setX(int x);
	void setY(int y);
	int getX();
	int getY();

	
};
#endif
