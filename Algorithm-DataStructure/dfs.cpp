// summary for Depth First Search (DFS) & Backtracking

// If the solution of a problem can be abstracted as a tree structure, then DFS applies!
// Common problems are subset, permutation, combination, k-sum, ...


// Draw a tree/network when you consider DFS!!!
// 1. Horizontal: the nodes in a level tell you how to write recursion in your dfs helper function
// 2. Vertical: a path starting from the root tell you how to write the stopping criterion


// Complexity:
// n*(n-1)*(n-2)..(n-k+1) ~ O(n^k)
// Or O(2^n)


// If a problems asks for whether a method is feasible or the number of feasible solutions, dynamic progamming (dp is usually a more efficient solution.
// However, if it further asks for listing out all possible solutions, then dp usually cannot help and dfs is on demand!


// DFS template
class Solution {
public:
    vector<vector<int> > search(vector<int> &nums) {
        // initialize and pre-pocessing
        vector<vector<int> > ans;
        vector<int> curr;
        // dive into dfs
        dfs(nums, 0, curr, ans);
        // post-process
        return ans;
    }

    void dfs(vector<int> &nums, int start, vector<int> &curr, vector<vector<int> > &ans) {
        // if proper, save and backtrack
        if (start == nums.end()) {
            ans.push_back(curr);
            return;
        }
        
        // recursively call dfs to dive deeper if needed
        for (int i = start; i < nums.size(); ++i) {
            curr.push_back(nums[i]);
            dfs(nums, i + 1, curr, ans);
            curr.pop_back();
        }
        return;
    }
    
};


// Important strategies in DFS
//
// 1. To avoid permutation in ordering (e.g. 1,3 vs 3,1), pass a parameter "start" to dfs();
//
// 2. To avoid reusing the same num twice (vertically), pass a parameter "unordered_set<int> used" to dfs();
//
// 3. To avoid reusing duplicates (horizontally), use an "unordered_set<int> currUsed" inside dfs();
//                                              , or sort first in main function, and then check if nums[i] & nums[i-1] are equal;




// k-sum: dfs template
// Given an array of n distinct positive integers, an integer k (k <= n) and a number target.
// Return all combinations of k numbers in who sum up to the target.
class Solution {
public:
    /**
     * @param nums: an integer array.
     * @param k: a positive integer (k <= length(nums))
     * @param target: an integer
     * @return a list of lists of integer
     */
    vector<vector<int> > kSum(vector<int> &nums, int k, int target) {
        vector<vector<int> > res;
        vector<int> curr;
        dfs(nums, 0, k, target, curr, res);
        return res;
    }
    
    void dfs(vector<int> &nums, int start, int k, int target, vector<int> &curr, vector<vector<int> > &res) {
        if (k < 0 || target < 0) return;
        
        if (k == 0 && target == 0) {
            res.push_back(curr);
            return;
        }
        
        for (int i = start; i < nums.size(); ++i) {
            curr.push_back(nums[i]);
            dfs(nums, i + 1, k - 1, target - nums[i], curr, res);
            curr.pop_back();
        }
        return;
    }
};


// k-sum: dp template
// Given an array of n distinct positive integers, an integer k (k <= n) and a number target.
// Count the number of all combinations of k numbers in who sum up to the target.
class Solution {
public:
    /**
     * @param nums: an integer array.
     * @param k: a positive integer (k <= length(nums))
     * @param target: a integer
     * @return an integer
     */
    int kSum(vector<int> &nums, int k, int target) {
        int n = nums.size();
        if (n == 0) return 0;
        
        // dp[i][j][t]: # of ways of choosing from the first i elements some j elements, sum up to t
        vector<vector<vector<int> > > dp(n + 1, vector<vector<int> >(k + 1, vector<int>(target + 1, 0)));
        
        for (int i = 0; i < n; ++i) {
            dp[i][0][0] = 1;
        }
        
        // for position i, we choose it or not
        for (int i = 0; i <= n; ++i) {
            for (int j = 1; j <= k; ++j) {
                for (int t = 1; t <= target; ++t) {
                    if (j > i) {
                        dp[i][j][t] = 0;
                    } else {
                        dp[i][j][t] = dp[i-1][j][t];
                    }
                    if (t - nums[i - 1] >= 0) {
                        dp[i][j][t] += dp[i-1][j-1][t - nums[i-1]];
                    }
                }
            }
        }
        
        return dp[n][k][target];
    }
};


