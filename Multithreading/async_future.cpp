/*
 * Summary:
 * 1. std::asyn(), which returns a future variable, can be used to do stuff in a asynchronous manner.
 * 2. One can get a returned value from the returned future variable later.
 */


#include <iostream>
#include <future>
#include <thread>
#include <chrono>

using namespace std;


int compute(int n) {
    // do something, micicked by sleeping here
    this_thread::sleep_for(chrono::seconds(1));
    
    int value = n*(n-1)/2;
    cout << "Finish computing, value = " << value << endl;
    return value;
}


int main() {
    // create a future to receive value
    future<int> fu = async(launch::async, compute, 4);   // lauch::async guarantees creating a new thread
                                                         // async() returns a future, from which a value can be got later.
                                                         // async() & future together realize asynchronous programming
    // do something else
    this_thread::sleep_for(chrono::seconds(3));
    
    // get value from a future
    int x = fu.get();       // a future can only call get() once!!
    cout << "Future gets value = " << x << endl;
    
    return 0;
}
