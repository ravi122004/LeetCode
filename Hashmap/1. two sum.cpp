// # Title
// 🔥 Two Sum in O(n) | Hash Map One-Pass Solution 💡

// # Intuition
// Instead of checking all pairs, we store elements we’ve seen.
// For each number, we check if its complement (target - num) already exists.
// If yes → we found the pair instantly.

// # Approach
// Create an unordered_map to store value → index.
// Traverse the array:
// For each element, compute rem = target - nums[i].
// If rem exists in map → return indices.
// Else store current element with its index in map.
// Return the result vector.

// # Complexity
// Time Complexity: O(n)
// Space Complexity: O(n)

// # Code
// ```cpp
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ans;
        unordered_map<int,int> mp;
        for(int i=0;i<nums.size();i++){
            int rem=target-nums[i];
            if(mp.find(rem)!=mp.end()){
                ans.push_back(mp[rem]);
                ans.push_back(i);
            }else{
                mp[nums[i]]=i;
            }
        }
        return ans;
    }
};