// Intuition
// The goal is to find three numbers whose sum is closest to the given target.
// A brute-force approach would check every triplet (i, j, k), but that would take O(n³) time.

// To optimize this, we first sort the array. Sorting helps us apply the two-pointer technique.

// After fixing one element nums[i], the remaining problem becomes finding two numbers whose sum is closest to target - nums[i]. We use two pointers:

// j → next element after i

// k → last element of the array

// We compute the current sum and update the answer if this sum is closer to the target than the previous best.

// Then we adjust pointers:

// If sum < target, we move j forward to increase the sum.

// If sum > target, we move k backward to decrease the sum.

// If sum == target, we found the best possible answer and can return immediately.

// This reduces the search efficiently while maintaining the closest sum found so far.

// Approach
// Sort the array to enable the two-pointer technique.

// Initialize ans with the sum of the first three elements.

// Iterate through the array fixing one element nums[i].

// Use two pointers:

// j = i + 1

// k = n - 1

// Calculate the sum of the triplet.

// Update ans if this sum is closer to the target.

// Move pointers based on comparison with the target:

// If sum < target, increment j

// If sum > target, decrement k

// Continue until pointers meet.

// Complexity Analysis
// Time Complexity:

// Sorting takes O(n log n)

// Two-pointer traversal for each element takes O(n)

// Overall complexity: O(n²)

// Space Complexity:

// O(1) (no extra space used apart from variables)

// Code
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int ans = nums[0] + nums[1] + nums[2];

        for(int i=0;i<nums.size();i++){
            int j=i+1;
            int k=n-1;
            while(j<k){
                int sum=nums[i]+nums[j]+nums[k];
                if(abs(sum-target)<abs(ans-target)){
                    ans=sum;
                }
                if(sum<target){
                    j++;
                }else if(sum>target){
                    k--;
                }else{
                    return sum;
                }
            }
        }
        return ans;
    }
};
