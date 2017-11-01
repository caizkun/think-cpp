/*
 * Summary:
 * 1. What if an exception occurs between lock() and unlock()? In that case, the lock would never be released. Therefore, using lock_guard<mutex> is recommended.
 * 2. Lock_guard<mutex> is a better implementation which will automatically release the lock whenever the guard goes out the execution scope.
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
        // use lock_guard in case an exception may be thrown
        // wheneven the guard is out of the execution scope, the mtx will be unlocked.
        lock_guard<mutex> guard(mtx);

        //mtx.lock();
        
        globalCount++;

        //mtx.unlock();
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
