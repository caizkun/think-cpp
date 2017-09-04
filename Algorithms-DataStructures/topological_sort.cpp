// summary for topological sort (an algorithm in directed acylic graph (DAG!!))

// typically useful for scheduling consective events with dependencies
// examples include course prerequisites

// Only DAG has a topological sort; ring doesn't have one.


// two general methods: BFS (easier to understand), DFS



// basic operations in BFS soltution (usually done together in a function):
    make_graph()
    compute_inwards()

// make_graph
fromToMap: <from, [to1, to2, ..]>

// computer_inwards
inwardDegrees[i] = inward degree of node i



// use queue to sequentially process children nodes whose inward degree becomes zero after removing the previous nodes








