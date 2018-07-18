#include "subject.h"

Subject::Subject() {}
Subject::~Subject() {}


void Subject::attach(Observer *o){
	observers.emplace_back(o);
}

void Subject::detach(Observer *o){
	for (auto it = observer.begin(); it != observers.end(); ++it){
		if (*it == o){
			observers.erase(it);
			break;
		}
	}
}

void Subject::notifyObserver(){
	for (auto ob : observers) ob->notify();
}
