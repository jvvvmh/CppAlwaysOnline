#include <iostream>
using namespace std;

enum type{
    GENERAL=0, FOK=1, GTC=2
};

template <class T>
class Order {
public:
    int get_type(){
        return asDerived()->get_specific_type();
    }
    T* asDerived(){
        return static_cast<T*>(this);
    }
    int get_specific_type() {
        return type::GENERAL;
    }
};


class FOKOrder : public Order<FOKOrder>{
public:
    int get_specific_type(){
        return type::FOK;
    }
};

class GTCOrder : public Order<GTCOrder>{
public:
    int get_specific_type(){
        return type::GTC;
    }
};


int main() {
    Order<FOKOrder> fok;
    Order<GTCOrder> gtc;
    cout << fok.get_type() << endl;
    cout << gtc.get_type() << endl;
    return 0;
}
