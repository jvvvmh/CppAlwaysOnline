#include <iostream>
#include <thread>
#include<future>

using namespace std;

int main(){
	int res;
	thread t([&]{res = 3 + 4;});
	t.join();
	cout << res << endl;
	
	auto a = std::async([&]{return res;});
	cout << a.get() << endl; 
    return 0;
}
