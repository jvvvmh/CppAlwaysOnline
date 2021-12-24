#include <atomic>
#include <iostream>
#include <thread>
using namespace std;

// declare an atomic variable for balance: atomic_balance
atomic<int> atomic_balance;
// int b;
void thread_one() {
      for (int i = 1; i <= 10000000; i++) {
          atomic_balance += 1;
      }
}

void thread_two() {
      for (int i = 1; i <= 10000000; i++) {
          atomic_balance -= 1;
      }
}


int main() {
    thread th1(thread_one);
    thread th2(thread_two);

    // waiting for the threads to end.
    th1.join();
    th2.join();
    //// Print atomic_balance
    // b = atomic_balance;
    // cout<<b<<endl;
    cout << atomic_balance << endl;
}
