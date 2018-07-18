#ifndef _TEXTDISPLAY_H_
#define _TEXTDISPLAY_H_
#include <iostream>
#include <vector>
#include "observer.h"

class Board;

class TextDisplay: public Observer{
	std::vector<std::vector<char>> theDisplay;
	int level;
	int score;
	int hiscore;
	char nextblock;
	public:
	TextDisplay();
	void notify(Subject &whoNotified) override;
	friend std::ostream &operator<<(std::ostream &out, const TextDisplay &td);
};
#endif
