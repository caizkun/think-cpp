/*
 * Summary:
 * 1. Promise is use to defer a value setting by calling promise::set_value(value) later;
 * 2. A future = promise::get_future() needs to be associated with the promise to receive the value once set
 */


#include <iostream>
#include <future>
#include <thread>
#include <chrono>

using namespace std;


int compute(future<int>& f) {
    // do something, micicked by sleep here
    this_thread::sleep_for(chrono::milliseconds(1));
    
    // get the value once it is set by the promise
    int n = f.get();
    cout << "Got the set value "  << n << endl;
    
    int value = n*(n-1)/2;
    cout << "Finish computing, value = " << value << endl;
    return value;
}


int main() {
    
    // create a promise, which promise to set a value later
    promise<int> prom;
    future<int> prom_fu = prom.get_future();    // associate a future with a promise
    
    // create a future to receive value
    future<int> fu = async(launch::async, compute, ref(prom_fu));   // lauch::async guarantees creating a new thread
                                                                    // pass a future to set value later
    // do something else, maybe to figure the value
    this_thread::sleep_for(chrono::milliseconds(3));
    
    // once we figure out the value, we can use promise to set the value
    // this works like defering setting the value
    cout << "Set the value = 4" << endl;
    prom.set_value(4);
    
    // get value from a future
    int x = fu.get();       // a future can only call get() once!!
    cout << "Future gets the return value = " << x << endl;
    
    return 0;
}
