// summary for heap
#include<priority_queue>

// Heap is essentially a almost complete binary tree but stored in an array.
// For a max heap, any node of the tree is larger than its left subtree and  right subtree.

// >>>>>>>>>>> Complexibility
// constructor  (call make_heap)        O(n)
// push()       (call push_heap)        O(logn)
// pop()        (call pop_heap)         O(logn)
// size()                               O(1)


template <class T, class Container = vector<T>, class Compare = less<typename Container::value_type> > class priority_queue;

// max heap by default
priority_queue<int> max_heap;
priority_queue<int> max_heap(data.begin(), data.end());  // O(n)


// min heap
// greater<int> needs header #include <functional>
priority_queue<int, vector<int>, greater<int> > min_heap;


//>>>>>>>>>>>> Must know how to write a customized comparison method
auto comp = [&nums1, &nums2] (pair<int, int> a, pair<int, int> b) {
    return nums1[a.first] + nums2[a.second] > nums1[b.first] + nums2[b.second];
};
priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(comp)> min_heap(comp);


// a max heap sorted by the second val of pair
auto comp = [] (pair<int, int> a, pair<int, int> b) {
    return a.second < b.second;
}
priority_queue<pair<int, int>, vector<pair<int, int> >, decltype(comp)> heap(comp);




//>>>>>>>>>>>> Good Partner: MAP + HEAP
// histogram O(n)
unordered_map<int, int> hist;
for (int i = 0; i < data.size(); ++i) {
    ++hist[data[i]];
}
// sort by frequency O(n)
priority_queue<pair<int, int> > heap;   // will be sorted wrt the first component
for (auto num : hist) {
    heap.push(make_pair(num.second, num.first));    // reverse val and freq
}



