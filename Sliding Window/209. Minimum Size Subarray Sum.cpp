# Intuition
We need the smallest subarray with sum ≥ target.
Using sliding window helps avoid checking all subarrays.

# Approach
Use two pointers i and j for window boundaries.
Expand window by adding nums[j].
While sum >= target:
Update minimum length.
Shrink window from left by subtracting nums[i].
Move j forward until traversal ends.
If no valid subarray exists → return 0.

# Complexity
Time Complexity: O(n)
Space Complexity: O(1)

# Code
```cpp
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n=nums.size();
        int i=0;
        int j=0;
        int sum=0;
        int minLen=INT_MAX;
        int len;
        while(j<n){
            sum+=nums[j];
            while(sum>=target){
                len=j-i+1;
                minLen=min(minLen,len);
                sum-=nums[i];
                i++;
            }
            j++;
        }
        return (minLen==INT_MAX)?0:minLen;
    }
};