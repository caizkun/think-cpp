// summary for binary search

// Data must be sorted!
// If data is already sorted, bisearch can reduce complexity from O(n) to O(logn)
// If data is not sorted yet, sorting itself requires O(nlogn). In that sense, binary search doesn't actually reduce complexity.

// Complexity: O(logn)

// template

// find the index of target
bool bisearch(vector<int> &data, int target, int begin, int end) {
    if (begin > end) return false;
    int l = begin, r = end;
    while (start + 1 < end) {
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

