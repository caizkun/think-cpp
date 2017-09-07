// summary for sort

// complexity:
    O(n^2)      selection sort
                insertion sort
                bubble sort

    O(nlog(n))  merge sort
                quick sort
                heapsort


// must be able to write a customized compare functio
bool compare(int a, int b) {
    return (a > b);     // reverse order
}
sort(data.begin(), data.end(), compare);

// or conveniently, use a lambda function
sort(data.begin(), data.end(), [] (pair<int, int> &a, pair<int, int> &b) {
    return (a.first < b.first);     // sort by the first element of pairs
});


// sort is often used in combination with algorithms such as binary search, two pointers,
