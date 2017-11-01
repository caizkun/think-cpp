// summary for sort

// complexity:
    O(n^2)      selection sort
                insertion sort
                bubble sort

    O(nlog(n))  merge sort
                quick sort
                heapsort

// Must be able to customize a comparator
// 1. write a customized compare function
bool compare(int &a, int &b) {
    return (a > b);     // reverse order
}
sort(data.begin(), data.end(), compare);

// 2. more conveniently, use a lambda function
sort(data.begin(), data.end(), [] (pair<int, int> &a, pair<int, int> &b) {
    return (a.second < b.second);     // sort by the second element of pairs
});



// sort is often used in combination with algorithms such as binary search, two pointers
