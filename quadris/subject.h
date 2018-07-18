#ifndef _OBSERVER_H_
#define _OBSERVER_H_

class Subject {
	std::vector<Observer*> observers;
	
	public:
	void attach(Observer *o);
	void detach(Observer *o);
	void notifyObservers();
}






#endif
