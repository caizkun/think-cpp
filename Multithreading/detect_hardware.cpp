/*
 * Summary:
 * 1. thread::hardware_concurrency() can be called to detect the number of cores available. 
 * 2. Creating many threads doesn't necessarily improve efficiency. In the case of oversubscription, context switch occurs too often and create more overhead.
 */

#include <iostream>
#include <thread>

using namespace std;


int main() {

    cout << thread::hardware_concurrency() << endl;

    return 0;
}






