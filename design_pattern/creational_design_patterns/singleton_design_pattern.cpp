/*
Singleton

is a creational design pattern
*/

class Singleton{
public:
	static Singleton* Instance(); // (in C++) static methods are never virtual
protected:
	Singleton(); // As the constructor is protected, 
	// the class controls when an instance
is created
private:
	static Singleton* _instance; // Eliminates the need for 
	// global variables that store single instances
};

Singleton* Singleton::_instance = 0;

Singleton* Singleton::Instance(){
	if (_instance == 0){
		_instance = new Singleton);
	}
	return _instance;
}
