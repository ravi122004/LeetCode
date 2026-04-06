// # Intuition
// To generate all permutations, fix one element at a position and recursively permute the rest.
// Use swapping to place each element at the current index.

// # Approach
// Start from index 0.
// For each index:
// Swap current element with every element after it.
// Recurse for next index.
// Backtrack by swapping back.
// When index reaches end → store permutation.

// # Complexity
// Time Complexity: O(n!)
// Space Complexity: O(n) → recursion stack

// # Code
// ```cpp
class Solution {
public:
    void permutations(int idx,vector<int>& nums,vector<vector<int>>& ans){
        if(idx==nums.size()){
            ans.push_back(nums);
            return;
        }
        for(int i=idx;i<nums.size();i++){
            swap(nums[idx],nums[i]);
            permutations(idx+1,nums,ans);
            swap(nums[idx],nums[i]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        permutations(0,nums,ans);
        return ans;
    }
};