#ifndef GRAPHICSDISPLAY_H_
#define GRAPHICSDISPLAY_H_
#include <iostream>
#include "subject.h"
#include "window.h"
#include "observer.h"
#include "board.h"

class GraphicsDisplay: public Observer{

	Xwindow xw;
	std::vector<std::vector<char>> theDisplay;
	std::vector<std::vector<char>> nbDisplay;
	int level;
	int score;
	int hiscore;
	int newblockheight; //height of the newblock
	int newblockdim; //dimensions of the newblock
	char nextblock;//char of the nextblock
	public:
	void restart();
	GraphicsDisplay();
	void notify(Subject &whoFrom);
	void notify(Board &whoFrom);
	void notify(Cell &whoFrom);


};



#endif
