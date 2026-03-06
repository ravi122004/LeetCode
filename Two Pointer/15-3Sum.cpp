// Intuition
// The brute force approach is to check every possible triplet (i, j, k) and see if their sum equals 0. This takes O(n³) time and is inefficient for large inputs.
// To optimize this, we first sort the array. Once the array is sorted, we can fix one element and use the two-pointer technique to find the remaining two numbers.
// Instead of checking every triplet, we reduce the problem to finding two numbers whose sum equals -nums[i]. Sorting also helps us easily skip duplicate elements, ensuring only unique triplets are added to the result.

// Approach
// 1️⃣ Sort the Array

// Sorting allows us to apply the two-pointer technique and also helps avoid duplicate triplets.

// sort(nums.begin(),nums.end());
// 2️⃣ Fix the First Element

// Iterate through the array and treat each element as the first element of the triplet.

// for(int i=0;i<n;i++)

// To avoid duplicates, skip the element if it is the same as the previous one.

// if(i>0 && nums[i]==nums[i-1]) continue;
// 3️⃣ Use Two Pointers

// Initialize two pointers:

// j = i + 1

// k = n - 1
// Calculate the sum:

// sum = nums[i] + nums[j] + nums[k]

// Then adjust pointers based on the sum.

// Condition Action
// sum < 0 move j++
// sum > 0 move k--
// sum == 0 store triplet and move both pointers
// 4️⃣ Skip Duplicate Values

// After finding a valid triplet, move pointers and skip duplicates to prevent repeated results.

// while(j<k && nums[j]==nums[j-1]) j++;
// while(j<k && nums[k]==nums[k+1]) k--;

// Complexity
// Time Complexity:
// Sorting takes O(n log n) and the two-pointer traversal takes O(n²).
// Overall complexity: O(n²)
// Space Complexity:
// O(1) (excluding the output list).



class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>>ans;
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size();i++){
            if(i>0 &&nums[i]==nums[i-1])continue;
            int j=i+1;
            int k=n-1;
            while(j<k){
                int sum=nums[i]+nums[j]+nums[k];
                if(sum<0)j++;
                else if(sum>0)k--;
                else{
                    ans.push_back({nums[i],nums[j],nums[k]});
                    j++;
                    k--;
                    while(j<k && nums[j]==nums[j-1]){
                        j++;
                    }
                }   
            }
        }
        return ans;
    }
};