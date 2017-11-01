/*
 * Summary:
 * 1. Condition variable is commonly used to avoid busy waiting by using wait-notify based on a condition
 * 2. Cond.wait(locker) does three things: 1. unlock the mutex; 2. go to sleep until being notified; 3. lock the mutex and proceed
 * 3. Use cond.notify_one() or notify_all() to wake up one or all the threads waiting for this coniditon
 *
 * ?? How to synchronize multiple producers/consumers?
 */

#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <chrono>
#include <deque>

using namespace std;

deque<int> dq;  // global buffer
mutex mtx;
condition_variable cond;


// producer
void produce() {
    int count = 10;
    while (count > 0) {
        unique_lock<mutex> locker(mtx);     // protect dq.push_front()
        dq.push_front(count);
        locker.unlock();
   
        cond.notify_one();                  // whenever producing a value, wake up one of the threads waiting for this condiiton
        //cond.notify_all();                  // notify all waiting threads to wake up
        
        cout << "From producer: produce a value " << count << endl;
        count--;
    }
}


// consumer
void consume() {
    int data = 0;
    while (data != 1) {
        unique_lock<mutex> locker(mtx);     // protect dq.pop_back()
        //while (dq.empty()) {
        //    cond.wait(locker);
        //}
        cond.wait(locker, []() { return !dq.empty(); } ); /* use condition variable to avoid busy waiting
                                                           *
                                                           * a thread does 3 things on wait():
                                                           * 1. unlock the mutex
                                                           * 2. go to sleep until being notified
                                                           * 3. lock the mutex again and proceed
                                                           *
                                                           * the extra function is a predicate to avoid spurious wake-up
                                                           * if predicte == false, the thread will go to sleep again
                                                           */
        
        //cout << "2: " << this_thread::get_id() << endl;
        data = dq.back();
        dq.pop_back();
        cout << "From consumer " << this_thread::get_id() << ": consume a value " << data << endl;
        locker.unlock();
    }
}


int main() {
    thread t1(produce);
    thread t2(consume);
    //thread t3(consume);   // doesn't work for multiple consumers; don't understand the execution yet
    t1.join();
    t2.join();
    //t3.join();
    
    return 0;
}
