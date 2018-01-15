// summary for shortest path
// Dijkstra's algorithm: compute the shortest weighted paths to all the other nodes from a source

typedef pair<int, int> entry;

class Graph {
public:
    Graph() {}
    
    void addNode(int node);
    void addEdge(int fromNode, int toNode, int weight);
    int dijkstra(int origin);   // compute the shortest path starting from the origin node

private:
    unordered_set<int> nodes;
    unordered_map<int, vector<entry> > adjacent;
}


void Graph::addNode(int node) {
    nodes.insert(node);
}


void Graph::addEdge(int fromNode, int toNode, int weight) {
    adjacent[fromNode].push_back(make_pair(toNode, weight));
    addNode(fromNode);
    addNode(toNode);
}


// Dijkstra's algorithm to compute the shortest paths to other nodes from a source
vector<int> Graph::dijkstra(int origin) {
    // initialize distance
    vector<int> dist(nodes.size(), INT_MAX);
    dist[origin] = 0;
    
    // use a min_heap to maintain a connection list
    auto compare = [] (entry &u, entry &v) {
        return (u.first < v.first);
    }
    priority_queue<entry, vector<entry>, decltype(compare)> minHeap(compare);
    minHeap.push(make_pair(0, origin));
    
    // main loop: keep retrieving a shortest-connect node and update the distance to its neighbors
    while (!minHeap.empty()) {
        entry curr = minHeap.top();
        minHeap.pop();
        int fromNode = curr.second;
        int size = adjacent[fromNode].size();
        for (int i = 0; i < size; ++i) {
            int toNode = adjacent[fromNode][i].first;
            int weight = adjacent[fromNode][i].second;
            if (1L * dist[toNode] - dist[fromNode] - weight > 0) {    // if shorter when taking a detour
                dist[toNode] = dist[fromNode] + weight;
                minHeap.push(make_pair(dist[toNode], toNode));
            }
        }
    }
    
    return dist;
}
