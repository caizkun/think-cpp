// summary for subarray & subsequence

subarray:     a continuous segment of the array
subsequence:   a subset of the array with the fixed order


// subsarray problem and methods
//
// 1. moving window of a fixed width k:
  - add a new element, delete the oldest element (update local/global)
  - deque (push_back(), pop_front())

// 2. two pointers (moving window of varying length)
int r = 0;
for (int l = 0; l < data.size(); ++l) {
    while (r < n) {
        if ( ) {    // if not satisfied
            // update r
            ++r;
            
        } else {
            break;
        }
    }
    
    // update l
    
}

// 3. preSum / preProd
// subSum = preSum[j] - preSum[i];  // i, ..., j-1
vector<int> preSum(n + 1, 0);
for (int i = 1; i < n; ++i) {
    preSum[i] += preSum[i - 1] + data[i - 1];   // preSum[i]: 0, 1, ..., i-1
}
unordered_set<int> saved;
for (int i = 0; i <= n; ++i) {
    if (saved.count(preSum[i] - target)) return true;
    saved.insert(preSum[i]);
}
return false;

// 4. DP
// dp[i]: XXX of the first i elements
// dp[i]: XXX ending in the i-th element
// dp[i][j]: XXX of subarray from index i to j




// is array A a subsequence of array B
bool isSubsequence(vector<int> &A, vector<int> &B) {
    int i = 0;
    for (int j = 0; j < B.size(); ++j) {
        if (A[i] == B[j]) ++i;
    }
    return (i == A.size());
}



