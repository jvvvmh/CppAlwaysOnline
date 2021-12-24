/*
Iterator is a pattern that shows why we would use multiple inheritance

How do you provide a standard interface 
for moving through a collection of objects 
whose data structure is unknown?

*/

#include <iostream>
using namespace std;

template <class Item>
class Iterator{
public:
	virtual void First() = 0;
	virtual void Next() = 0;
	virtual bool IsDone const = 0;
	virtual Item currentItem() const = 0;
protected:
	Iterator();
};

template <class Item>
class AbstractAggregate{
public:
	virtual Iterator<Item>* CreateIterator() const = 0;
	// ...
};


/* Define a collection class (List) */
template <class Item>
class List: public AbstractAggregate{
public:
	List(long size=DEFAULT_LIST_CAPACITY);
	long Count() const;
	Item& Get(long index) const;
	// ...
	// and the method to provide the iterator
};

template <class Item>
class ListIterator: public Iterator<Item>{
public:
	ListIterator(const List<item>* aList)
	void First();
	void Next();
	bool IsDone const;
	Item CurrentItem() const;
	Iterator<Item>* CreateIterator() const;
private:
	const List<Item>* _list;
	long _current;
};

template <class Item>
ListIterator<Item>::ListIterator(const List<item>* aList): _list(aList), _current(0){
}

template <class Item>
void ListIterator<Item>::First(){
	_current = 0;
} 

template <class Item>
void ListIterator<Item>::Next(){
	_current++;
}

template <class Item>
void ListIterator<Item>::IsDone const{
	return _current >= _list->Count();
}

template<class Item>
void ListIterator<Item>::CurrentItem() const{
	if (IsDone()){
		throw IteratorOutOfBounds;
	}
	return _list->Get(_current);
}

template <class Item>
Iterator<Item>* List<Item>::CreateIterator() const{
	return new ListIterator<Item>(this);
}


