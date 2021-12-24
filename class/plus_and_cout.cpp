#include <iostream>

using namespace std;

class A{
public:
	A(int x_): x(x_){
		cout << "Creat A" << endl;
	}
	A(const A & a){
		cout << "Copy Constructor" << endl;
		x = a.x;
	}
	A & operator = (const A & a){
		cout << "Copy" << endl;
		x = a.x;
		return *this;
	}
	A & operator + (const A & a){
		cout << "operator +" << endl;
		x = x + a.x;
		return *this;
	}
	A operator ++(int){
		// a++
		A tmp = A(*this);
		x += 1;
		return tmp;
	}
	A & operator ++(){
		// ++a;
		x += 1;
		return *this;
	}
	friend ostream & operator <<(ostream & o, const A & a){
		o << a.x << endl;
		return o;
	}
private:
	int x;
};

int main(){
    A a = A(1);
	A b = A(2);
	cout << "a = a + b"<<endl; // 3
	a = a + b;
	cout << "a++" << endl;
	a++;
	cout << "++a" << endl;
	++a;
	cout << "cout << a" << endl;
	cout << a << endl;
	return 0;
}
