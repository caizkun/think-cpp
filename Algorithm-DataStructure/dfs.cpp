// summary for Depth First Search (DFS) & Backtracking


// If the solution of a problem can be abstracted as a tree structure, then DFS applies!
// Draw a tree when you consider DFS!!!

// Complexity:
// n*(n-1)*(n-2)..(n-k+1) ~ O(n^k)
// Or O(2^n)


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

    void dfs(vector<int> &nums, int begin, vector<int> &curr, vector<vector<int> > &ans) {
        // if proper, save and backtrack
        if (begin == nums.end()) {
            ans.push_back(curr);
            return;
        }
        
        // recursively call dfs to dive deeper if needed
        for (int i = begin; i < nums.size(); ++i) {
            curr.push_back(nums[i]);
            dfs(nums, i + 1, curr, ans);
            curr.pop_back();
        }
        return;
    }
    
};


// We can consider DFS in two typical directions:
