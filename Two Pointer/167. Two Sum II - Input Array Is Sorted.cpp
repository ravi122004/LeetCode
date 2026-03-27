// # Intuition
// Since the array is sorted, we can use two pointers to find the target sum efficiently.
// If sum is too small → move left pointer.
// If sum is too large → move right pointer.

// # Approach
// Initialize l = 0 and r = n-1.
// While l < r:
// Compute sum = nums[l] + nums[r].
// If sum == target → return {l+1, r+1}.
// If sum < target → move left pointer.
// Else → move right pointer.
// Return empty vector if no pair found.

// # Complexity
// Time Complexity: O(n)
// Space Complexity: O(1)

// # Code
// ```cpp
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int l=0;
        int r=nums.size()-1;
        while(l<r){
            int sum=nums[l]+nums[r];
            if(sum==target){
                return {l+1,r+1};
            }
            else if(sum<target) l++;
            else r--;
        }
        return {};
    }
};