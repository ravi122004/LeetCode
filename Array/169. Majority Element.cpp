// # Intuition
// The majority element appears more than n/2 times.
// Using Boyer-Moore Voting, we cancel out different elements.
// The remaining candidate is the potential majority element.

// # Approach
// Initialize count = 0 and candidate.
// Traverse array:
// If count == 0 → set candidate = current element.
// If current element == candidate → count++.
// Else → count--.
// Verify candidate:
// Count its frequency in array.
// If frequency > n/2 → return candidate.
// Else → return -1.

// # Complexity
// Time Complexity: O(n)
// Space Complexity: O(1)

// # Code
// ```cpp
class Solution {
public:
    int majorityElement(vector<int>& arr) {
        int count=0;
        int candidate=0;
        for(int num:arr){
            if(count==0){
                candidate=num;
            }
            if(candidate==num){
                count++;
            }else{
                count--;
            }
        }
        count=0;
        for(int num:arr){
            if(num==candidate){
                count++;
            }
        }
        if(count>arr.size()/2){
            return candidate;
        }
        return -1;
    }
};