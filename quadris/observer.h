#ifndef _OBSERVER_H_
#define _OBSERVER_H_
#include "board.h"
#include "newblock.h"
#include "score.h"
class Observer {
	 public:
	virtual void notify(Board &whoFrom) = 0;
	virtual ~Observer() = default;
};

#endif

