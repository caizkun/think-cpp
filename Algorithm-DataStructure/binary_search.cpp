// summary for binary search

// Data must be sorted!
// If data is sorted, binary search can reduce complexity from O(n) to O(logn)
// If data is not sorted, sorting itself requires O(nlogn). In that sense, binary search doesn't actually reduce complexity.

// Complexity: O(logn)


// binary search, in the most general sense, is an algorithm that reduces the situatons by half.
// the search may be applied to array indices, number range, matrix indices, etc.


// template: find the index of target
bool bisearch(vector<int> &data, int target, int begin, int end) {
    if (begin > end) return false;
    int l = begin, r = end;
    while (l + 1 < r) {         // no overlap to avoid dead loop
        int mid = l + (r - l) / 2;
        if (data[mid] == target) {
            return mid;
        } else if (data[mid] < target) {
            l = mid;
        } else {
            r = mid;
        }
    }
    if (data[l] == target) return l;
    if (data[r] == target) return r;
    return false;
}


// find the first position
while (l + 1 < r) {
    int mid = l + (r - l) / 2;
    if (data[mid] < target) {   // maintain strictly less
        l = mid;
    } else {
        r = mid;
    }
}
if (data[l] == target) return l;
if (data[r] == target) return r;


// find the last position
while (l + 1 < r) {
    int mid = l + (r - l) / 2;
    if (data[mid] > target) {   // maintain strictly greater
        r = mid;
    } else {
        l = mid;
    }
}
if (data[r] == target) return r;
if (data[l] == taregt) return l;


// find the total number of occurrence
// two pass: find the first, then find the last



// >>>>> Search in a rotated sorted array <<<<<
//
// (I) no duplicates
// 1. find min/max  --> discuss whether data[mid] <= > data[r]
// 2. find target   --> if found, return; otherwise, based on data[mid] <= > data[r], discuss whether target lies in between
//
// (II) with duplicates
// 1. find min/max  --> discuss whether data[mid] < > == data[r]; if ==, then --r;
// 2. find target   --> if found, return; otherwise, based on data[mid] < > = data[r], discuss whether target lies in between; if ==, then --r;










