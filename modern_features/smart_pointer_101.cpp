#include <iostream>
#include <memory>
using namespace std;


class Order {
public:
    Order() { cout << "Order Constructor" << endl; }
    ~Order() { cout << "Order Destructor" << endl; }
    void getPrice() { cout << "This is public function of class" << endl; }
};






// A helper function which returns a shared pointer
shared_ptr<Order> CreateSmartPointer() {
//Create a shared pointer
    cout << "Enter CreateSmartPointer" << endl;
    Order * p = new Order();
    cout << "Exit CreateSmartPointer" << endl;
    return shared_ptr<Order>(p);
}



// A helper function which returns a unique pointer
unique_ptr<Order> CreateUniquePointer() {
//Create a unique pointer
    cout << "Enter CreateUniquePointer" << endl;
    Order * p = new Order();
    cout << "Exit CreateUniquePointer" << endl;
    return unique_ptr<Order>(p);
}


template <class T>
class MyOwnSmartPointer
{
//You will implement your own smart pointer class
public:
    T * p;
    MyOwnSmartPointer<T>(T * p){
        this -> p = p;
    }
    T& operator *(){
        return *p;
    }
    ~MyOwnSmartPointer<T>(){
        delete p;
    }
};
// Test to confirm that shared pointers do release memory without explicitely calling