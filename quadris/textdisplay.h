#ifndef _TEXTDISPLAY_H_i
#define _TEXTDISPLAY_H_
#include <iostream>
#include <vector>
#include "observer.h"
class Board;
class Cell;

class TextDisplay: public Observer{
	std::vector<std::vector<char>> theDisplay;
	int level;
	int score;
	int hiscore;
	char nextblock;
	public:
	TextDisplay();
	void notify(Subject &whoFrom);
	void notify(Board &whoFrom);
	void notify(Cell &whoFrom);
	friend std::ostream &operator<<(std::ostream &out, const TextDisplay &td);
};
#endif
