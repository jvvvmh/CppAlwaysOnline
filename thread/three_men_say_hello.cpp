#include <iostream>
#include <thread>
#include <mutex>

using namespace std;

mutex m; // use std::lock_guard if want to be exception safe

int i = 0;

void Call(){
	m.lock();
	cout << i << "Hello" << endl;
	i++;
	m.unlock();
}

int main(){
	thread man1(Call);
	thread man2(Call);
	thread man3(Call);
	man1.join(); man2.join(); man3.join();
	return 0;
}
