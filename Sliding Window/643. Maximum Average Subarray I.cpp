// # Intuition
// Instead of recalculating sum for every subarray, use a sliding window.
// Keep updating the window sum by adding next element and removing the previous one.

// # Approach
// Compute sum of first k elements.
// Initialize answer as sum/k.
// Slide the window:
// Add nums[i] and subtract nums[i-k].
// Update maximum average.
// Return final answer.

// # Complexity
// Time Complexity: O(n)
// Space Complexity: O(1)

// ```cpp
class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int sum=0;
        for(int i=0;i<k;i++){
            sum+=nums[i];
        }
        double ans=sum/(double)k;
        for(int i=k;i<nums.size();i++){
            sum+=nums[i];
            sum-=nums[i-k];
            ans=max(ans,sum/(double)k);
        }
        return ans;
    }
};