/********************************************
 Collections of tips learned from experience
 *********************************************/

/*
 very useful headers
 */
#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <queue>
#include <list>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <cmath>
#include <climits>

// or an all-in-one trick
//#include<bits/stdc++.h>

using namespace std;
typedef long long ll;


// remove duplicates and keep unique items ---> sort, unique
sort(data.begin(), data.end());     // sort first s.t. duplicates are consective
data.resize(unique(data.begin(), data.end()) - data.begin());   // unique returns the iterator after the last unremoved item


// lexicography order --> sort the vector of string or char


// find the min or max of a set which keeps changing ---> heap (C++ uses priority_queue, which is a implementation of max-heap)
priority_queue<int> max_heap(data.begin(), data.end());   // construct a heap from a array is O(n)
priority_queue<int, vector<int>, greater<int> > min_heap(data.begin(), data.end());    // change priority_queue to a min heap;


// type conversion/casting
string str = to_string(123);    // num to string
int num = stoi(str);            // string to num: stoi          needs header <string>
int num = atoi(str.c_str());    // string to num: atoi, atoll   needs header <cstdlib>
char c = '0' + 6;               // char of digit: c = '6'
int i = c - 'a';                // interval between chars: if c = 'b', i = 1



// dfs is feasible if the factorial(n) < 10^9, thus n < 13.
12! ~ 10^8
13! ~ 10^9


// fill 0 -> (n-1) in a vector
vector<int> v(n);
iota(v.begin(), v.end(), 0);    // 0 is the starting value



// get all digits of a number
// similar code can be used to do number base conversion
vector<int> digits;
for (int i = n; i != 0; i /= 10) {
    digits.push_back(i % 10);
}
reverse(digits.begin(), digits.end());


// convert from digits to a number
int num = 0;
for (int i = 0; i < digits.size(); ++i) {
    num = 10*num + digits[i];
}


