// # Intuition
// We extract each digit and check if it divides the number.
// Ignore digit 0 to avoid division error.

// # Approach
// Store original number.
// Extract last digit using n % 10.
// If digit != 0 and divides original number → increment count.
// Remove last digit using n / 10.
// Repeat until n becomes 0.
// Return count.

// # Complexity
// Time Complexity: O(d) → d = number of digits
// Space Complexity: O(1)

// # Code
// ```cpp
class Solution {
public:
    int countDigits(int num) {
        int n=num;
        int count=0;
        while(n>0){
            int ld=n%10;
            if(ld!=0 && num%ld==0){
                count++;
            }
            n=n/10;
        }
        return count;
    }
};