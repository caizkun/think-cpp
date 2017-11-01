/*
 * Summary:
 * 1. Sometimes, a new thread is created to do some heavy work and we don't want to wait for it to finish. In this case, we can detach the thread.
 */

#include <iostream>
#include <thread>

using namespace std;


void sayHello() {
    cout << "From t1: I was created to do heavy work!";
    cout << "         Hope the main thread respects what I am doing, although it detached me!" << endl;
    // do some stuff
    for (int i = 0; i < 100000; ++i) {
    }   

    // the main thread may have finished before this message can be directed to the stdout
    cout << "From t1: Huu, done! Too sad that the main thread couldn't see this message!" << endl;
}

int main() {
    // instantiate a thread
    thread t1(sayHello);

    // detach a thread
    t1.detach();
    cout << "From main: I detached thread t1 to let it run independently! Hope it will be reaped by the STL!\n" << endl;

    return 0;
}






