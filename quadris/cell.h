#ifndef CELL_H
#define CELL_H
class Cell {
	char type;
	public:
	explicit Cell();

	~Cell();
	explicit Cell(char t);
	bool isL();
	bool isI();
	char getType();

	
};
#endif
