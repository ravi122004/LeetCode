// # Intuition
// <!-- Describe your first thoughts on how to solve this problem. -->
// The brute force solution checks every quadruplet:

// a < b < c < d
// and verifies
// nums[a] + nums[b] + nums[c] = nums[d]

// This requires 4 nested loops → O(n⁴).

// But instead of checking all four indices together, we can split the equation into two parts.

// Step 1: Rearrange the equation
// nums[a] + nums[b] + nums[c] = nums[d]

// Move one term:
// nums[a] + nums[b] = nums[d] - nums[c]
// Now we have two independent expressions:
// Left side
// nums[a] + nums[b]

// Right side
// nums[d] - nums[c]
// Step 2: Store the right side in a HashMap
// For every valid pair (c,d):
// difference = nums[d] - nums[c]
// Store it in a hashmap.
// difference → frequency
// Example:
// nums = [1,2,3,6]
// 6 - 3 = 3

// map:
// 3 → 1
// Step 3: Check the left side

// Now check pairs (a,b).
// sum = nums[a] + nums[b]
// If that sum exists in the hashmap, we found valid quadruplets.

// if(mp.count(sum))
//     ans += mp[sum]
// Step 4: Maintain index order
// We must ensure
// a < b < c < d
// To maintain this:
// Fix b
// Let c = b + 1
// Insert (c,d) differences into the hashmap
// Check (a,b) sums
// This guarantees valid ordering.

// # Approach
// <!-- Describe your approach to solving the problem. -->
// Create a hashmap to store differences.
// Iterate b from right to left.
// Fix c = b + 1.
// Store nums[d] - nums[c] for all valid d.
// For all a < b, check if nums[a] + nums[b] exists in the hashmap.
// Add the frequency to the answer.

// # Complexity
// Type	Complexity
// Time	O(n²)
// Space	O(n²) (hashmap worst case)

// # Optimized Code
class Solution {
public:
    int countQuadruplets(vector<int>& nums) {
        int ans=0;
        int n=nums.size();
        unordered_map<int,int>mp;
        for(int b=n-3;b>=1;b--){
            int c=b+1;
            for(int d=c+1;d<n;d++){
                mp[nums[d]-nums[c]]++;
            }
            for(int a=0;a<b;a++){
                int sum=nums[a]+nums[b];
                if(mp.count(sum))ans+=mp[sum];
            }
        }
        
        return ans;
    }
};

// # Brute force Code

class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        int count=0;
        int n=nums1.size();
        unordered_map<int,int>freqSum;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                freqSum[nums1[i]+nums2[j]]++;
            }
        }
        
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                int sum=nums3[i]+nums4[j];
                if(freqSum.count(-sum)){
                    count+=freqSum[-sum];
                }
            }
        }
        return count;
    }
};
