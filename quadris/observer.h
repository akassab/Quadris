#ifndef _OBSERVER_H_
#define _OBSERVER_H_

class Board;
class Subject;
class Cell;

class Observer {
	 public:
	virtual void notify(Subject &whoFrom) = 0;	
	virtual void notify(Board &whoFrom) = 0;
	virtual void notify(Cell &whoFrom) = 0;
	virtual ~Observer();
};

#endif

