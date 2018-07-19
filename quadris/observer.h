#ifndef _OBSERVER_H_
#define _OBSERVER_H_

class Board;
class Subject;

class Observer {
	 public:
	virtual void notify(Subject &whoFrom) = 0;
	virtual ~Observer();
};

#endif

