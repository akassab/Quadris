#ifndef _TEXTDISPLAY_H_
#define _TEXTDISPLAY_H_
class Board;

class TextDisplay{
	std::vector<std::vector<<char>> theDisplay;
	public:
	TextDisplay();
	void notify(Subject &whoNotified) override;
	friend std::ostream &operator<<(std::ostream &out, const TextDisplay &td);

};
#endif
