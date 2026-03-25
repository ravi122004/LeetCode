// # Intuition
// In a sorted array, binary search helps find elements efficiently.
// To get the first occurrence, we continue searching on the left even after finding the target.

// # Approach
// Initialize l = 0, h = n-1, ans = -1.
// While l <= h:
// Compute mid.
// If nums[mid] == target:
// Store mid in ans and move left → h = mid - 1.
// If nums[mid] > target → move left.
// Else → move right.
// Return ans.

// # Complexity
// Time Complexity: O(log n)
// Space Complexity: O(1)

// # Code
// ```cpp
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n=nums.size();
        int l=0;
        int h=n-1;
        int ans=-1;
        while(l<=h){
            int mid=l+(h-l)/2;
            if(nums[mid]==target){
                ans=mid;
                h=mid-1;
            }
            else if(nums[mid]>target){
                h=mid-1;
            }else{
                l=mid+1;
            }
        }
        return ans;
    }
};