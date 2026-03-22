// # Title
// 🔥 Make Array Uniform by Parity | Min Element Insight 💡

// # Intuition
// If all elements are already even or all are odd → uniform.
// If mixed, the smallest element decides:
// If minimum is odd → we can make all elements odd.
// If minimum is even → not possible.

// # Approach
// Find the minimum element in the array.
// Count how many elements are odd.
// If all are odd or all are even → return true.
// Otherwise, check if minimum element is odd:
// If yes → return true, else false.

// # Complexity
// Time Complexity: O(n)
// Space Complexity: O(1)

// # Code
// ```cpp
class Solution {
public:
    bool uniformArray(vector<int>& nums) {
        int n=nums.size();
        int mne=*min_element(nums.begin(),nums.end());

        int oddCount=0;
        for(int x:nums){
            if(x%2!=0){
                oddCount++;
            }
        }
        if(oddCount==0 || oddCount==n) return true;
        
        return mne%2==1;
    }
};