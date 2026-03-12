// Intuition
// For each index i, we need to compute:

// | leftSum[i] - rightSum[i] |

// Where:

// leftSum[i] = sum of all elements before index i

// rightSum[i] = sum of all elements after index i

// Instead of recalculating sums for every index (which would be slow), we precompute prefix and suffix sums.

// Create a left array that stores the cumulative sum of elements before each index.

// Create a right array that stores the cumulative sum of elements after each index.

// For every index i, compute:

// abs(left[i] - right[i])

// This avoids repeated summation and keeps the solution efficient.

// Approach
// Step 1 — Compute Left Prefix Sum

// Create an array left.

// left[i] = sum of elements before i

// Formula:

// left[i] = left[i-1] + nums[i-1]

// Example:

// nums = [10,4,8,3]

// left = [0,10,14,22]
// Step 2 — Compute Right Suffix Sum

// Create another array right.

// right[i] = sum of elements after i

// Formula:

// right[i] = right[i+1] + nums[i+1]

// Example:

// right = [15,11,3,0]
// Step 3 — Calculate Final Answer

// For each index:

// ans[i] = | left[i] - right[i] |

// Example:

// ans = [15,1,11,22]

// Complexity
// Time Complexity
// O(n)
// Explanation:
// One loop for left array
// One loop for right array
// One loop for answer
// Total operations proportional to n.
// Space Complexity
// O(n)

// Code
class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int n=nums.size();
        vector<int>left(n);
        left[0]=0;
        for(int i=1;i<n;i++){
            left[i]=left[i-1]+nums[i-1];
        }
        vector<int>right(n);
        right[n-1]=0;
        for(int i=n-2;i>=0;i--){
            right[i]=right[i+1]+nums[i+1];
        }
        vector<int>ans(n);
        for(int i=0;i<n;i++){
            ans[i]=abs(left[i]-right[i]);
        }
        return ans;
    }
};
