#ifndef CELL_H
#define CELL_H
class Cell {
	char type;
	int x;
	int y;
	public:
	explicit Cell(int nx, int ny);
	~Cell();
	int getX();
	int getY();
	void setX(int n);
	void setY(int n);
	explicit Cell(char t, int nx, int ny);
	char getType();
	void setType(char t);
	

	
};
#endif
