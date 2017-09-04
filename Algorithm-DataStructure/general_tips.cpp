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


// find the min or max of a set which keeps changing ---> heap (C++ uses priority_queue)
priority_queue<int> max_heap(data.begin(), data.end());   // priority_queue is a max heap by defalut
priority_queue<int, vector<int> greater<int> > min_heap(data.begin(), data.end());    // change priority_queue to a min heap;


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


// number base conversion
vector<int> digits;
for (int m = n; m != 0; m /= 10) {
    digits.push_back(m % 10);
}



