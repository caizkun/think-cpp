/*
 * Summary:
 * 1. Deadlock occurs when some threads are waiting for conditions that would never be true.
 * 2. Deadlock typically occurs when multiple mutexes are locked not in the same order.
 * 3. To avoid deadlock, always lock multiple mutexes in the same order; also, aovid calling other user-defined function within locked region
 */


#include <iostream>
#include <thread>
#include <mutex>

using namespace std;

mutex mtx1;
mutex mtx2;

void printOdd(int n) {
    if (n % 2 == 0) ++n;
    
    for (; n > 0; n -= 2) {
        unique_lock<mutex> lock1(mtx1);
        unique_lock<mutex> lock2(mtx2);      // lock 1, then 2
        
        cout << n << endl;
        
        lock2.unlock();
        lock1.unlock();
    }
}

void printEven(int n) {
    if (n % 2 == 1) --n;
    
    for (; n > 0; n -= 2) {
        //unique_lock<mutex> lock1(mtx1);    // this is the correct order
        unique_lock<mutex> lock2(mtx2);
        unique_lock<mutex> lock1(mtx1);      // lock 2, then 1! Deadlock!
        
        cout << n << endl;
        
        //lock2.unlock();
        lock1.unlock();
        lock2.unlock();
    }
}

int main() {
    
    int n = 21;
    
    thread t1(printOdd, n);
    thread t2(printEven, n);
    t1.join();
    t2.join();
    
    return 0;
}
