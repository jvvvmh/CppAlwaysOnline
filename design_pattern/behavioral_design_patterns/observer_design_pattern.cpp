/*
Observer design pattern (dependents or publish subscribe)

is a behavioral pattern.

How to notify the objects when the subject changes?

Observer is a pattern that shows
why we would use multiple inheritance
*/

class Subject;

class Observer{
public:
	virtual ~Observer();
	virtual void update(Subject* theChangedSubject) = 0;
protected:
	Observer();
};

class Subject{
public:
	virtual ~Subject();
	virtual void Attach (Observer*){
		_observers->Append(o);
	}
	virtual void Detach (Observer*){
		_observers->Remove(o); 
	}
	virtual void Notify(){
		ListIterator<Observer*> i(_observers);
		for (i.First(); !i.IsDone(); i.Next()){
			i.CurrentItem() -> Update(this);
		}
	}
protected:
	Subject();
private:
	List<Observer*> * _observers; 
};

class ClockTimer : public Subject{
	// ...
};

class DigitalClock: public Widget, public Observer{
	// ...
};
