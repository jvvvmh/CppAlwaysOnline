#include <iostream>
#include <memory>

using namespace std;
/*
use count == 0; gw is expired
use count == 1; 42
use count == 0; gw is expired
*/
weak_ptr<int> gw;

void observe(){
	cout << "use count == " << gw.use_count() << "; ";
	if (auto spt = gw.lock()){
		cout << *spt << endl;
	}else{
		cout << "gw is expired" << endl;
	}
}

int main(){
	observe();
	{
		auto sp = std::make_shared<int>(42);
		gw = sp;
		observe();
	}
	observe();
}
