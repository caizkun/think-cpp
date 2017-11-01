// summary for heap
#include<map>
#include<set>
#include<unordered_map>
#include<unordered_set>

// map and set are ordered by their keys, while unordered_map and unordered_set do not.

// Complexity: map & set (TreeMap & TreeSet)
// Implemented as binary search tree, search O(logn)

// Complexity: unordered_map & unordered_set (HashMap & HashSet)
// Implement hash-tables, search O(1)


// >>> must be able to customize set/map comparator!!! <<<
auto comp = [](int a,  int b) { // not reference
    return (a > b);     // reverse order
};
set<int, decltype(comp)> myset(comp);
map<int, int, decltype(comp)> mymap(comp);




// Map and set are sorted in ascending order by default.
map<int, int>::iterator iter;
for (iter = hist.begin(); iter != hist.end(); ++iter) {
    data.push_back(hist->second);
}
// fetch data in descending order
map<int, int>::reverse_iterator iter;   // reverse_iterator
for (iter = hist.rbegin(); iter != hist.rend(); ++iter) {
    data.push_back(hist->second);
    // hist.erase(--(iter.base()));     // call erase with a reverse iterator!
}


