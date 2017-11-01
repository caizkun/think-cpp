/*
 * Summary:
 * 1. Unique_lock<mutex> has more flexibility than lock_guard but at the cost of more overhead.
 * 2. Using unique_lock<mutex>, you can defer a lock, lock and unlock multiple times, and move to another unique_lock. Therefore, it can be used to implement finer-grained lock.
 */

#include <iostream>       // cout
#include <thread>         // thread
#include <mutex>          // mutex

using namespace std;


mutex mtx;           // mutex for critical section

void print_thread_id (int id) {
    //lock_guard<mutex> guard(mtx);

    // unique_lock<mutex> is more flexible than lock_guard<mutex> at the cost of some overhead
    //unique_lock<mutex> locker(mtx);   // lock when created
    unique_lock<mutex> locker(mtx, defer_lock); // you can even defer a lock
    
    locker.lock();       // start to lock
    cout << "thread #" << id << '\n';
    locker.unlock();    // unlock
    
    locker.lock();      // lock again
    cout << "thread $" << id << '\n';
    locker.unlock();
}

int main ()
{
    const int N = 100;
    thread threads[N];
    
    // spawn 10 threads:
    for (int i = 0; i < N; ++i) {
        threads[i] = thread(print_thread_id, i+1);
    }
    
    for (auto& th : threads) {
        th.join();
    }
    
    return 0;
}
