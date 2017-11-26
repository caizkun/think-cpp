// summary for disjoint-set data strcture (Union-Find)

// Useful for the problems relavant to connectivity / groups
// http://blog.csdn.net/dm_vincent/article/details/7655764
// http://blog.csdn.net/dm_vincent/article/details/7769159


// 3 basic operations
//    make_set(x)
//    union(x, y)
//    find_set(x)


void make_set(vector<int> &parent) {
    for (int i = 0; i < parent.size(); ++i) {
        parent[i] = i;
    }
    return;
}

//int find_set(vector<int> &parent, int x) {
//    if (x != parent[x]) {
//        parent[x] = find_set(parent, parent[x]);    // with path compression
//    }
//    return parent[x];
//}


// >>>>>>>>>> Path compression doesn't mean all the nodes in the same set point to the root! <<<<<<<<<<<<<
int find_set(vector<int> &parent, int x) {
    if (parent[x] == x) {
        return x;
    }
    parent[x] = find_set(parent, parent[x]);    // with path compression
    return parent[x];
}

void union(vector<int> &parent, int x, int y) {
    int root_x = find(parent, x);
    int root_y = find(parent, y);
    if (root_x == root_y) return;
    parent[root_x] = root_y;        // no union by rank yet
    return;
}


// A very useful trick is that sometimes you need to assume a dummy node which aggregates all the nodes with a desired property
