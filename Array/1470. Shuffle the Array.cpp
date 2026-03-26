// # Title
// 🔥 Shuffle the Array | Two Pointer Interleaving 💡

// # Intuition
// The array is split into two halves: [x1,x2,...,xn] and [y1,y2,...,yn].
// We need to merge them alternately → x1,y1,x2,y2,...

// # Approach
// Use two pointers:
// i = 0 for first half, j = n for second half.
// Create result array of size 2*n.
// Traverse k from 0 to 2*n-1:
// If k is even → take from first half (nums[i]).
// Else → take from second half (nums[j]).
// Increment respective pointers.
// Return result.

// # Complexity
// Time Complexity: O(n)
// Space Complexity: O(n)

// # Code
// ```cpp
class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        int i=0;
        int j=n;
        vector<int> ans(2*n);
        for(int k=0;k<2*n;k++){
            if(k%2==0){
                ans[k]=nums[i];
                i++;
            }else{
                ans[k]=nums[j];
                j++;
            }
        }
        return ans;
    }
};