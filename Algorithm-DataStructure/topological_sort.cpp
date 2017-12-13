// summary for topological sort (an algorithm in directed acylic graph (DAG!!))

// typically useful for scheduling consective events with dependencies
// examples include course prerequisites

// Only DAG has a topological sort; ring doesn't have one.

// two general methods: BFS, DFS


// 1. Make graph and count inward degrees for each node

// (BFS) 2. use queue to sequentially process children nodes whose inward degree becomes zero after removing the previous nodes

// (DFS) 2. dive deeper from any child node whose inward degree becomes zero afer remvoing the previous nodes


// below is an example for Course Schedule II
class Solution {
public:
    vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<vector<int> > graph = makeGraph(numCourses, prerequisites);
        vector<int> inwards = computeInwards(graph);
        
        queue<int> candidates;
        for (int i = 0; i < inwards.size(); ++i) {
            if (inwards[i] == 0) {
                candidates.push(i);
            }
        }
        
        vector<int> res;
        while (!candidates.empty()) {
            int curr = candidates.front();
            candidates.pop();
            res.push_back(curr);
            for (int num : graph[curr]) {
                --inwards[num];
                if (inwards[num] == 0) {
                    candidates.push(num);
                }
            }
        }
        
        if (res.size() != numCourses) {
            return vector<int>{};
        }
        
        return res;
    }
    
private:
    vector<vector<int> > makeGraph(int numCourses, vector<pair<int, int> > &prerequisites) {
        vector<vector<int> > graph(numCourses);
        int n = prerequisites.size();
        for (int i = 0; i < n; ++i) {
            int first = prerequisites[i].second;
            int second = prerequisites[i].first;
            graph[first].push_back(second);
        }
        return graph;
    }
    
    vector<int> computeInwards(vector<vector<int> > &graph) {
        int n = graph.size();
        vector<int> inwards(n, 0);
        for (int i = 0; i < n; ++i) {
            for (int num : graph[i]) {
                ++inwards[num];
            }
        }
        return inwards;
    }
};



// dfs version

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<vector<int> > graph = makeGraph(numCourses, prerequisites);
        vector<int> inwards = computeInwards(graph);
        
        vector<int> res;
        for (int i = 0; i < inwards.size(); ++i) {
            if (inwards[i] == 0) {
                dfs(i, graph, inwards, res);    // dive deeper
            }
        }
        
        if (res.size() != numCourses) {
            return vector<int>{};
        }
        
        return res;
    }
    
private:
    void dfs(int node, vector<vector<int> > &graph, vector<int> &inwards, vector<int> &res) {
        res.push_back(node);
        --inwards[node];
        for (int neighbor : graph[node]) {
            --inwards[neighbor];
            if (inwards[neighbor] == 0) {
                dfs(neighbor, graph, inwards, res);
            }
        }
        return; // backtrack
    }
    
    vector<vector<int> > makeGraph(int numCourses, vector<pair<int, int> > &prerequisites) {
        vector<vector<int> > graph(numCourses);
        int n = prerequisites.size();
        for (int i = 0; i < n; ++i) {
            int first = prerequisites[i].second;
            int second = prerequisites[i].first;
            graph[first].push_back(second);
        }
        return graph;
    }
    
    vector<int> computeInwards(vector<vector<int> > &graph) {
        int n = graph.size();
        vector<int> inwards(n, 0);
        for (int i = 0; i < n; ++i) {
            for (int num : graph[i]) {
                ++inwards[num];
            }
        }
        return inwards;
    }
};


