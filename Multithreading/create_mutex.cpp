/*
 * Summary:
 * 1. Data racing happens often when multiples threads try to use their shared resources;
 *    for example, here we create a globalCount and it is incremented n times by each thread. For a large n, dace racing occurs and the final count would be wrong.
 * 2. mutex is a classic synchronizaiton technique using lock() and unlock(). 
 *    Once a critical section is locked by a thread, other threads have to wait until the lock is released. In that way, the shared resource is procted.
 *
 */


#include <iostream>
#include <thread>
#include <mutex>

using namespace std;

mutex mtx;

// define a shared variable
int globalCount = 0;

void addCount(int n) {
    for (int i = 0; i < n; ++i) {
        // lock this critical section
        mtx.lock();
        
        globalCount++;

        // unlock
        mtx.unlock();
    }
    cout << "From addCount: " << globalCount << endl;
}


int main(int argc, char* argv[]) {
    int n = 10000;      // a large enough number to see data racing
    if (argc == 1) {
        cout << "By default take n = " << n << endl;
    } else  {
        n = atoi(argv[1]);
    }

    cout << "\nFrom main: initial globalCount = " << globalCount << endl; 

    // create two threads which will have data race on the shared variable globalCount
    thread t1(addCount, n);
    thread t2(addCount, n);
    t1.join();
    t2.join();

    // expect 20 if correct
    cout << "\nFrom main: final globalCount = " << globalCount << endl;
    return 0;
}
